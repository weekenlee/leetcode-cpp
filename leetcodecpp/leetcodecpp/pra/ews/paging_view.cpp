
#define EWS_HAS_NOEXCEPT_SPECIFIER
#define EWS_HAS_TYPE_ALIAS
#define EWS_HAS_DEFAULT_TEMPLATE_ARGS_FOR_FUNCTIONS
#define EWS_HAS_THREAD_LOCAL_STORAGE
#define EWS_HAS_DEFAULT_AND_DELETE
#define EWS_HAS_VARIADIC_TEMPLATES
#define EWS_HAS_NON_BUGGY_TYPE_TRAITS
#define EWS_HAS_ROBUST_NONMODIFYING_SEQ_OPS
#define EWS_HAS_INITIALIZER_LISTS

#include "ews/ews.hpp"
#include "ews/ews_test_support.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

#define _LINUX 1

//创建目录
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#elif _LINUX
#define ACCESS access
#define MKDIR(a) mkdir((a), 0755)
#endif

int create_dir(const char* pdir) {
    int i = 0;
    int iret;
    int ilen;
    char *pszdir;

    if(NULL == pdir) {
        return 0;
    }

    pszdir = strdup(pdir);
    ilen = strlen(pszdir);

    for(i = 0; i < ilen; i++) {
        if(pszdir[i] == '\\' || pszdir[i] == '/') {
            pszdir[i] = '\0';

            iret = ACCESS(pszdir, 0);
            if(iret != 0) {
                iret = MKDIR(pszdir);
                if(iret != 0) {
                    return -1;
                }
            }
            pszdir[i] = '/';
        }
    }

    iret = MKDIR(pszdir);
    free(pszdir);
    return iret;
}

std::string get_today() {
   time_t tt = time(NULL);//这句返回的只是一个时间cuo
   struct tm* t= localtime(&tt);
   std::stringstream ss;
   ss << t->tm_year + 1900;
   ss <<std::setw(2)<<std::setfill('0')<<t->tm_mon + 1 << t->tm_mday ;
   return ss.str();
}

int main()
{
    std::string today = get_today();
    std::string last_email ;

    std::ifstream ifs("log");
    std::getline(ifs, last_email);
    std::cout << last_email << std::endl;

    std::ofstream ofs;
    ofs.open("log", std::ios::out);

    int res = EXIT_SUCCESS;
    ews::set_up();

    try
    {
        auto service = ews::service("https://owa.gf.com.cn/ews/Exchange.asmx",
                                     "",
                                     "",
                                     "");
  
        ews::distinguished_folder_id inbox = ews::standard_folder::inbox;

        // Now iterate over all items in the folder
        // Starting at the end with an offset of 0
        // Returning a number of 5 items per iteration
        // Until no more items are returned
        ews::paging_view view(5, 0, ews::paging_base_point::beginning);
        int i = 0;
        std::string first_id_name="";
        while (true)
        {
            auto item_ids = service.find_item(inbox, view);
            if (item_ids.empty())
            {
                std::cout << "No more messages found!\n";
                break;
            }
            

            for (const auto& id : item_ids)
            {
                auto msg = service.get_message(id);
                auto subject = msg.get_subject();
                std::cout << subject << "\t";
                std::cout << msg.get_from().value() << "\t";
                std::cout << msg.get_date_time_created().to_string() << "\n";

                std::string idname =  msg.get_from().value() + "_" + msg.get_subject() + msg.get_date_time_created().to_string();

                if(first_id_name.size() == 0) {
                    first_id_name = idname;
                }

                std::cout <<"last_email "<<last_email<<std::endl;
                std::cout <<"idname "<<idname<<std::endl;

                if(last_email == idname || i++ > 1000) {
                    std::cout << "写入" << first_id_name << std::endl;
                    ofs << first_id_name;
                    goto endloop;
                }

                if(subject.find("结算数据") != std::string::npos || subject.find("行情数据") != std::string::npos) {
                    continue;
                }
                
                std::string dirpath = ".//atts//"+ today + "//" + msg.get_from().value() + "_" + msg.get_subject();
                create_dir(dirpath.c_str());

                auto attachments = msg.get_attachments();
                for(const auto &attachment :attachments) {
                        auto path = dirpath + "//" + attachment.name();
                        if(path.find("image") != std::string::npos && path.find("jpg") != std::string::npos) {
                            continue;
                        }
                        const auto bytes = service.get_attachment(attachment.id()).write_content_to_file(path);
                        //std::cout << "save " << attachment.name();
                }
            }

            view.advance();
        }
    }
    catch (std::exception& exc)
    {
        std::cout <<"异常"<<std::endl;
        std::cout << exc.what() << std::endl;
        res = EXIT_FAILURE;
    }

endloop:
    ews::tear_down();
    ifs.close();
    ofs.close();
    return res;
}

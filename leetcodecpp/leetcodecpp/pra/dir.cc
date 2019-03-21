#include <iostream>
#include <cstring>
#include <io.h>
#include <stdint.h>

using namespace std;

void listfiles(const char* dir);

int main() {
    char dir[200];
    cout << "enter a dir:" ;
    cin.getline(dir, 200);
    listfiles(dir);
    return 0;
}

void listfiles(char* dir) {
    char dirnew[200];
    strcpy(dirnew, dir);
    strcat(dir, "\\*.*");

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dirnew, &findData);
    if(handle == -1) {
        return;
    }

    do {
        if(findData.attrib & _A_SUBDIR) {
            if(strcmp(findData.name, ".") == 0 || strcmp(findData.name,"..")==0) {
                conintue;
            }  

            cout << findData.name << "\t<dir>\n";

            strcpy(dirnew, dir);
            strcat(dirnew, "\\");
            strcat(dirnew, findData.name);
            
            listfiles(dirnew);
        }else {
            cout <<findData.name << "\t" << findData.size <<"bytes.\n";
        }
    }while(_findnext(handle,&findData) == 0);

    _findclose(handle);
}

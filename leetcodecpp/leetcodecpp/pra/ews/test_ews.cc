
#define EWS_HAS_NOEXCEPT_SPECIFIER
/*
#define EWS_HAS_MAKE_UNIQUE
*/
#define EWS_HAS_TYPE_ALIAS
#define EWS_HAS_DEFAULT_TEMPLATE_ARGS_FOR_FUNCTIONS
#define EWS_HAS_THREAD_LOCAL_STORAGE
#define EWS_HAS_DEFAULT_AND_DELETE
#define EWS_HAS_VARIADIC_TEMPLATES
#define EWS_HAS_NON_BUGGY_TYPE_TRAITS
#define EWS_HAS_ROBUST_NONMODIFYING_SEQ_OPS
#define EWS_HAS_INITIALIZER_LISTS

#include "ews/ews.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int main() {
    ews::set_up();
    try {
        auto service = ews::service("https://example.com/ews/Exchange.asmx",
                                     "ACME",
                                     "myuser",
                                     "mysecret");
        auto message = ews::message();
        message.set_subject("Test mail from outer space");
        std::vector<ews::mailbox> recipients{ ews::mailbox("president@example.com") };
        message.set_to_recipients(recipients);
    } catch (std::exception& exc) {
        std::cout << exc.what() << std::endl;
    }

    ews::tear_down();
    return 0;
}

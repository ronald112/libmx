#include "libmx.h"

// chk if there is at least one nb in str, false = no nb
bool mx_is_nb_in_str(char *str) {
    for (int i = 0; i < mx_strlen(str); ++i)
        if (!mx_isdigit(str[i]))
            return false;
    return true;
}

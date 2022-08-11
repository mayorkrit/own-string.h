#include "s21_string.h"

char *s21_strerror(int errnum) {
    static char *errors_msgs[] = ERRORS_ARR;
    static char output[1024] = {'\0'};
    int errors_count = ERRORS_COUNT;
    if (errnum < 0 || errnum > errors_count) {
        s21_strcpy(output, "Unknown error: ");
        char str_num[16] = "";
        s21_itoa((long int)errnum, str_num, 10);
        s21_strcat(output, str_num);
    } else {
        s21_strcpy(output, errors_msgs[errnum]);
    }
    return output;
}

#include "libmx.h"

static char *chk_if_zero() {
    char *arr = mx_strnew(1);

    arr[0] = 0 + '0';
    return arr;
}

static void chk_max_int(bool *if_negative, bool *flag, int *number) {
    *if_negative = 1;
    if (*number == -2147483648) {
        *number += 1;
        *flag = 1;
    }
    *number *= -1;
}

static char *calculation(int number, int counter,
bool if_negative, bool flag) {
    char *arr = NULL;

    if (if_negative == 1) 
        counter++;
    arr = mx_strnew(counter + 1);
    if (if_negative == 1) 
        arr[0] = '-';
    for (int i = counter - 1; i >= if_negative; i--) {
        if (flag == 1) {
            arr[counter - 1] = 8 + '0';
            flag = 0;
        }
        else 
            arr[i] = (number % 10) + '0';
        number /= 10;	
    }
    arr[counter + 1] = '\0';
    return arr;
}

char *mx_itoa(int number) {
    bool flag = 0;
    bool if_negative = 0;
    char *result = NULL;

    if (number < 0)
        chk_max_int(&if_negative, &flag, &number);
    else if (number == 0)
        result = chk_if_zero();
    else {
        int copy = number;
        int counter = 0;

        while (copy != 0) {
            counter++;
            copy /= 10;
        }
        result = calculation(number, counter, if_negative, flag);
    }
    return result;
}

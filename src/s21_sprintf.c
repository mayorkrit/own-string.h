#include "s21_string.h"

#include <stdlib.h>
#include "stdarg.h"
#include <stdio.h>
#include <math.h>

// план:
// идем по строке, копируем символы из format в str, пока не встретим %
// делаем все функции для парсинга по отдельности, должны быть следующие функции:
// для всего остального (точность, ширина и т.д.) точно такие же функции

// после этого берем значение, которое должно быть на этом месте, запускаем функцию для его преобразования
// результатом этой функции должна быть строка. Вставляем эту строку в str.

// все пункты это значения флагов, длины, точности, и т.д

// значение может быть 0, либо 1
// сделано для того, чтоб отличать от простого инта

// Value - структура с информацией об одном выражении

// Какая длина ширина и т.д.
// return проинициалированное нулевыми значениями структура Value
Value init_value_variable() {
    Value v = {0, 0, 0, 0, 0, 'c', 0, 0, 0, 0, 0, 0};
    return v;
}

// flag_parser - обрабатывает флаги
// str - указатель на текущее положение в строке обработчика
// value - собранная информация об объекте
// return : указатель на текущее положение в строке
char* flag_parser(char* str, Value* value) {
    while (*str == '-' || *str == '+' || *str == ' ') {
        if (*str == '-') {
            value->minus_flag = 1;
            str++;
            continue;
        }
        if (*str == '+') {
            value->plus_flag = 1;
            str++;
            continue;
        }
        if (*str == ' ') {
            value->space_flag = 1;
            str++;
            continue;
        }
    }
    return str;
}

// width_parser - обрабатывать ширину
// str - указатель на текущее положение в строке обработчика
// value - собранная информация об объекте
// factor - стек значений из переданных в функцию значений (не уверен, что нужно передавать указатель на него)
// return : указатель на текущее положение в строке
char* width_parser(char* str, Value* value) {
    char *curr_pos = str;
    while (*curr_pos >= '0' && *curr_pos <= '9') {
        value->width = value->width * 10 + (*curr_pos - '0');
        curr_pos++;
    }
    if (curr_pos != str) {
        value->mod_width = 1;
    } else {
        value->mod_width = 0;
    }
    return curr_pos;
}



// accuracy_parse - обрабатывает точность
// str - указатель на текущее положение в строке обработчика
// value - собранная информация об объекте
// factor - стек значений из переданных в функцию значений (не уверен, что нужно передавать указатель на него)
// return : указатель на текущее положение в строке
char* accuracy_parse(char* str, Value* value) {
    str++;
    char sym[BUFF_SIZE] = {'\0'}; int i = 0, ch;

    while (*str >= '0' && *str <= '9') {
        *(sym + i) = *str;
        i++;
        str++;
        value->mod_accuracy = 1;
    }
    ch = atoi(sym);
    value->accuracy = ch;

    return str;
}

// lenght_parse - обрабатывает длину
// str - указатель на текущее положение в строке обработчика
// value - собранная информация об объекте
// return : указатель на текущее положение в строке
char* length_parse(char* str, Value* value) {
    switch (*str) {
    case 'h':
        value->length = 'h';
        str++;
        break;
    case 'l':
        value->length = 'l';
        str++;
        break;
    default:
        value->mod_length = 0;
        break;
    }
    return str;
}

// type_parse - обрабатывает тип сообщения
// str - указатель на текущее положение в строке обработчика
// value - собранная информация об объекте
// return : указатель на текущее положение в строке
char* type_parse(char* str, Value* value) {
    switch (*str) {
    case 'c':
        value->type = 'c';
        str++;
        break;
    case 'd':
        value->type = 'd';
        str++;
        break;
    case 'i':
        value->type = 'i';
        str++;
        break;
    case 'f':
        value->type = 'f';
        str++;
        break;
    case 's':
        value->type = 's';
        str++;
        break;
    case 'u':
        value->type = 'u';
        str++;
        break;
    case '%':
        value->type = '%';
        str++;
        break;
    default:
        break;
    }
    return str;
}


// применяет флаги к str
// return: кол-во символов на который произошел сдвиг
///// домашка !!!! пробел не работает
int flag_mod(char* str, Value value) {
    int shift = 0;
    if (value.plus_flag && (value.type == 'd' || value.type == 'u' || value.type == 'i' || \
    value.type == 'f') && str[0] != '-') {
        if (str[0] != ' ') {
            char temp_str[BUFF_SIZE] = {'\0'};
            temp_str[0] = '+';
            temp_str[1] = '\0';
            s21_strcat(temp_str, (const char*)str);
            for (s21_size_t i = 0; i < s21_strlen( (const char*) temp_str); i++)
                str[i] = temp_str[i];
            shift += 1;
        } else {
            s21_size_t t = 1;
            while (str[t] == ' ') {
                t++;
            }
            str[t-1] = '+';
        }
    }
    if (value.minus_flag && value.width) {
        // for (int i = 0; i < value.width - (int)s21_strlen(str); i++)
        //     for (s21_size_t j = i; j < value.width - 1; j++)
        //         str[j] = str[j + 1];
        int counter1 = 0, counter2 = 0, counter3 = 0;
        char res[BUFF_SIZE] = {'\0'};
        res[0] = '\0';
        while (str[counter1] != '\0') {
            if (value.width == 2 && str[counter1] == ' ') {
                counter2++;
            } else if ((str[counter1] == ' ' && (str[counter1 - 1] == ' ' || str[counter1 + 1] == ' '))) {
                counter2++;
            } else {
                res[counter3] = str[counter1];
                counter3++;
            }
            counter1++;
        }
        while (counter2 != 0) {
            res[counter3] = ' ';
            counter3++;
            counter2--;
        }
        while (str[counter2] != '\0') {
            str[counter2] = res[counter2];
            counter2++;
        }
    }
    if (value.space_flag && !value.plus_flag && value.type != 's') {
        char temp_str[BUFF_SIZE + 1] = {'\0'};
        if (value.space_flag && str[0] != '-' && value.type != 'u') {
            temp_str[0] = ' ';
            if (str[0] != ' ' && str[s21_strlen(str) - 1] != ' ') {
                s21_strcpy(temp_str + 1, str);
                s21_strcpy(str, temp_str);
                shift += 1;
            } else {
            if (str[s21_strlen(str) - 1] == ' ') {
                s21_strcpy(temp_str + 1, str);
                s21_strcpy(str, temp_str);
                char new1[BUFF_SIZE] = {'\0'};
                s21_strncpy(new1, str, value.width);
                for (int i = 0; i < value.width; i++)
                    str[i] = new1[i];
                str[value.width] = '\0';
            }
            if (str[0] == ' ' && str[s21_strlen(str) - 1] != ' ') {
                s21_strcpy(temp_str + 1, str);
                s21_strcpy(str, temp_str);
                for (s21_size_t i = 0; i < s21_strlen(str) - 1; i++) {
                    str[i] = str[i + 1];
                }
                char new1[BUFF_SIZE] = {'\0'};
                s21_strncpy(new1, str, value.width);
                for (int i = 0; i < value.width; i++)
                    str[i] = new1[i];
                str[value.width] = '\0';
            }
            }
        }
    }
    return shift;
}

// применяет width к str
// return: кол-во символов на который произошел сдвиг
int width_mod(char* str, Value value) {
    int str_len = s21_strlen(str);
    int indent = value.width - str_len;
    indent = indent < 0? 0: indent;
    for (int i = str_len; i >= 0; i--)
        str[i + indent] = str[i];
    for (int i = 0; i < indent; i++)
        str[i] = ' ';
    str[str_len + indent] = '\0';
    return indent;
}

// применяет accuracy к str
// return: кол-во символов на который произошел сдвиг
int accuracy_mod(char* str, Value value) {
    int sdvig = 0;
    if (value.type == 'd' || value.type == 'i' || value.type == 'u') {
        if (value.accuracy == 0 && str[0] == '0') {
            sdvig -= s21_strlen(str);
            str[0] = '\0';
        } else {
            int len = s21_strlen(str);
            if (len < value.accuracy) {
                char new[BUFF_SIZE] = {'\0'};
                for (s21_size_t i = 0; i < ((s21_size_t)value.accuracy - len); i++)
                    new[i] = '0';
                new[value.accuracy] = '\0';
                s21_strcat(new, str);
                s21_memcpy(str, new, value.accuracy);
                sdvig = value.accuracy - len;
            }
        }
    } else if (value.type == 's') {
        int len = (int)s21_strlen(str);
        if (len > value.accuracy) {
            char new1[BUFF_SIZE] = {'\0'};
            s21_strncpy(new1, str, value.accuracy);
            for (int i = 0; i < value.accuracy; i++)
                str[i] = new1[i];
            str[value.accuracy] = '\0';

            sdvig = value.accuracy - len;
        }
    }
    return sdvig;
}



// применяет модификаторы к char (c)
// str - строка с результатом
// a - символ, который нужно обработать
// value - собранные модификаторы
// возвращает сдвиг
int mod_char(char *str, char ch, Value value) {
    int shift = 1;
    char new_part[BUFF_SIZE] = {'\0'};
    new_part[0] = (char)ch;
    new_part[1] = '\0';
    if (value.mod_width)
        shift += width_mod(new_part, value);
    if (value.minus_flag)
        shift += flag_mod(new_part, value);
    s21_strcat(str, (const char*)new_part);
    return shift;
}


// применяет модификаторы к int (d, i)
// str - строка с результатом
// i - число, которое нужно обработать
// value - собранные модификаторы
// возвращает сдвиг
int mod_int(char *str, long int i, Value value) {
    int shift = 0;
    char new_part[BUFF_SIZE] = {'\0'};
    new_part[0] = '\0';
    if (value.length == 'h')
        i = (short int)i;
    else if (value.length == 'l')
        i = (long int)i;
    else if (value.mod_length == 0)
        i = (int)i;

    s21_itoa(i, new_part, 10);
    shift += s21_strlen(new_part);
    if (value.mod_accuracy == 1)
        shift += accuracy_mod(new_part, value);
    if (value.mod_width == 1)
        shift += width_mod(new_part, value);
    if (value.minus_flag || value.plus_flag || value.space_flag)
        shift += flag_mod(new_part, value);
    s21_strcat(str, (const char*)new_part);
    return shift;
}


// применяет модификаторы к string (s)
// str - строка с результатом
// source - число, которое нужно обработать
// value - собранные модификаторы
// возвращает сдвиг
int mod_string(char *str, char* source, Value value) {
    int shift = s21_strlen(source);
    char new_part[BUFF_SIZE] = {'\0'};
    new_part[0] = '\0';
    s21_strcpy(new_part, source);
    if (value.mod_accuracy)
        shift += accuracy_mod(new_part, value);
    if (value.mod_width)
        shift += width_mod(new_part, value);
    if (value.minus_flag)
        shift += flag_mod(new_part, value);
    s21_strcat(str, (const char*)new_part);
    return shift;
}



// применяет модификаторы к float (f)
// str - строка с результатом
// d - число c плавающей точкой, которое нужно обработать
// value - собранные модификаторы
// возвращает сдвиг

void double_to_string(double val, char *ret, Value f) {
    char buff[BUFF_SIZE] = {'\0'};
    buff[0] = '\0';
    int idx = BUFF_SIZE - 2;
    s21_bool neg = val < 0 ? 1 : 0;
    val = neg ? val * -1 : val;
    double l = 0, r = modf(val, &l);
    if (f.accuracy == 0) {
        l = roundl(val);
        r = 0;
    }
    char fractions[BUFF_SIZE] = {'\0'};
    for (int i = 0; i < f.accuracy; i++) {
        r = r * 10;
        fractions[i] = (int)r + '0';
    }
    long long right = roundl(r), left = l;
    if (!right) {
        for (int i = 0; i < f.accuracy; idx--, i++)
            buff[idx] = '0';
    } else {
        for (int i = s21_strlen(fractions); right || i > 0;
            right /= 10, idx--, i--)
            buff[idx] = (int)(right % 10 + 0.05) + '0';
    }
    if ((f.mod_accuracy && f.accuracy != 0) || (int)r ||
        (!f.mod_accuracy && val == 0) || s21_strlen(fractions))
        buff[idx--] = '.';
    if (!left) {
        buff[idx] = '0';
        idx--;
    } else {
        for (; left; left /= 10, idx--)
            buff[idx] = (int)(left % 10) + '0';
    }
    int i = 0;
    for (; buff[idx + 1]; idx++, i++) {
        if (neg && i == 0) {
            ret[i] = '-';
            i++;
        }
        ret[i] = buff[idx + 1];
    }
    ret[i] = '\0';
}

int mod_float(char *str, double d, Value value) {
    int shift = 0;
    if (value.mod_accuracy == 0)
        value.accuracy = 6;
    if (value.length == 'L')
        d = (double)d;
    else if (value.mod_length == 0)
        d = (double)d;
    char new_part[BUFF_SIZE] = {'\0'};
    new_part[0] = '\0';
    double_to_string(d, new_part, value);
    shift += s21_strlen(new_part);
    // if (value.mod_accuracy)
    //     shift += accuracy_mod(new_part, value);
    if (value.mod_width == 1)
        shift += width_mod(new_part, value);
    if (value.minus_flag || value.plus_flag || value.space_flag)
        shift += flag_mod(new_part, value);
    s21_strcat(str, (const char*)new_part);
    return shift;
}

// применяет модификаторы к uint (u)
// str - строка с результатом
// u - безнаковое число, которое нужно обработать
// value - собранные модификаторы
// возвращает сдвиг
int mod_uint(char *str, unsigned long int u, Value value) {
    int shift = 0;
    char new_part[BUFF_SIZE] = {'\0'};
    new_part[0] = '\0';
    if (value.length == 'h') {
        u = (unsigned short int)u;
    } else if (value.length == 'l') {
        u = (unsigned long int)u;
    } else if (value.mod_length == 0) {
        u = (unsigned int)u;
    }
    s21_utoa(u, new_part, 10);
    shift += s21_strlen(new_part);
    if (value.mod_accuracy)
        shift += accuracy_mod(new_part, value);
    if (value.mod_width == 1)
        shift += width_mod(new_part, value);
    if (value.minus_flag)
        shift += flag_mod(new_part, value);
    s21_strcat(str, (const char*)new_part);
    return shift;
}

int s21_sprintf(char *str, const char *format, ...) {
    for (int i = 0; i < BUFF_SIZE; i++)
        str[i] = '\0';
    s21_size_t len_str = 0;
    va_list factor;
    va_start(factor, format);

    char *ptr_curr_char_format = (char*) format;
    while (*ptr_curr_char_format != '\0' && ptr_curr_char_format != s21_NULL) {
        if (*ptr_curr_char_format != '%') {
            *str = *ptr_curr_char_format;
            ptr_curr_char_format++;
            str++;
            len_str++;
            continue;
        }
        Value value = init_value_variable();
        ptr_curr_char_format++;
        if (*ptr_curr_char_format == '%') {
            s21_strcat(str, "%");
            ptr_curr_char_format++;
            str++;
            len_str++;
            continue;
        }
        if (ptr_curr_char_format != s21_NULL && *ptr_curr_char_format != '\0') {
            ptr_curr_char_format = flag_parser(ptr_curr_char_format, &value);
        }
        if (ptr_curr_char_format != s21_NULL && *ptr_curr_char_format != '\0') {
            ptr_curr_char_format = width_parser(ptr_curr_char_format, &value);
        }
        if (*ptr_curr_char_format == '.' && ptr_curr_char_format != s21_NULL \
        && *ptr_curr_char_format != '\0') {
            ptr_curr_char_format = accuracy_parse(ptr_curr_char_format, &value);
        }
        if (ptr_curr_char_format != s21_NULL && *ptr_curr_char_format != '\0') {
            ptr_curr_char_format = length_parse(ptr_curr_char_format, &value);
        }
        if (ptr_curr_char_format != s21_NULL && *ptr_curr_char_format != '\0') {
            ptr_curr_char_format = type_parse(ptr_curr_char_format, &value);
        }
        int shift = 0;
        if (value.type == 'c') {
            shift = mod_char(str, (char)va_arg(factor, int), value);
            str += shift;
            len_str += shift;
        } else if (value.type == 'd' || value.type == 'i') {
            shift = mod_int(str, va_arg(factor, long int), value);
            str += shift;
            len_str += shift;
        } else if (value.type == 'f') {
            shift = mod_float(str, va_arg(factor, double), value);
            str += shift;
            len_str += shift;
        } else if (value.type == 's') {
            shift = mod_string(str, va_arg(factor, char *), value);
            str += shift;
            len_str += shift;
        } else if (value.type == 'u') {
            shift = mod_uint(str, va_arg(factor, long unsigned int), value);
            str += shift;
            len_str += shift;
        }
    }
    va_end(factor);
    return len_str;
}

// int main() {
//     // unsigned long int val = 949149114140;
//     // char *val = "QW QW QW QWQWQWQW QWQWQW QW QW QW QWQWQWQW QWQWQW";
//     char dest[BUFF_SIZE] = {'\0'};
//     // (char *)malloc(sizeof(char) * BUFF_SIZE);
//     dest[0] = '\0';
//     const char *src = "%s%s%s%s"; // "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'
//     //long int v = 698518581899;
//     char *val =
//         "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
//     char *s1 = "";
//     char *s2 = "87418347813748913749871389480913";
//     char *s3 = "HAHAABOBASUCKER";
//     int i = s21_sprintf(dest, src,  val, s1, s2, s3);
//     // Value value = init_value_variable();
//     // value.mod_accuracy = 1;
//     // value.accuracy = 15;
//     // int i = accuracy_mod(&src, value);
//     //printf("%d\n", 123);
//     int b = printf("\n%s%s%s%s", val, s1, s2, s3);
//     printf("\n%d %d\n", i, b);
//     //free(dest);
// }

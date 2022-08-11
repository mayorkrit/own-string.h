#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_



typedef int s21_bool;

// Value - структура с информацией об одном выражении
typedef struct Value {
    s21_bool minus_flag;
    s21_bool plus_flag;
    s21_bool space_flag;
    s21_bool grid_flag;
    s21_bool zero_flag;

    char type;
    s21_bool mod_width;
    int width;
    s21_bool mod_accuracy;
    int accuracy;
    s21_bool mod_length;
    char length;
} Value;


int s21_sprintf(char *str, const char *format, ...);
Value init_value_variable();
char* flag_parser(char* str, Value* value);
char* width_parser(char* str, Value* value);
char* accuracy_parse(char* str, Value* value);
char* length_parse(char* str, Value* value);
char* type_parse(char* str, Value* value);
int flag_mod(char* str, Value value);
int width_mod(char* str, Value value);
int accuracy_mod(char* str, Value value);
int mod_char(char *str, char ch, Value value);
int mod_int(char *str, long int i, Value value);
int mod_string(char *str, char* source, Value value);
void double_to_string(double val, char *ret, Value f);
int mod_float(char *str, double d, Value value);
int mod_uint(char *str, unsigned long int u, Value value);

#endif  //  SRC_S21_SPRINTF_H_

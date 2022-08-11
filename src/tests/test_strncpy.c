/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_TEST.check" instead.
 */


#line 1 "s21_TEST.check"
#include "../tests_includes/s21_tests.h"

// 1
// #test memchr_test_1
// // Исходный массив
// unsigned char src[15] = "1234567890";
// ck_assert_pstr_eq(memchr(src, '4', 10), s21_memchr(src, '4', 10));


// #test memchr_test_not_in_the_array
// // Исходный массив
// unsigned char src[15] = "1234567890";
// ck_assert_pstr_eq(memchr(src, 't', 10), s21_memchr(src, 't', 10));

// // 2
// #test memcmp_test_2_test1
// unsigned char s1[15]="asd";
// unsigned char s2[15]="asd";
// ck_assert_uint_eq(memcmp(s1, s2, 10), s21_memcmp(s1, s2, 10));

// #test memcmp_test_2_empty
// unsigned char s1[15] = "";
// unsigned char s2[15] = "abcd";
// ck_assert_int_eq(memcmp(s1, s2, 10), s21_memcmp(s1, s2, 10));

// #test memcmp_test_2_secondEmpty
// unsigned char s1[15] = "abcd";
// unsigned char s2[15] = "";
// ck_assert_int_eq(memcmp(s1, s2, 10), s21_memcmp(s1, s2, 10));

// #test memcmp_test_2_negativeNumber
// unsigned char s1[15] = "abcd";
// unsigned char s2[15] = "grtwgsdfgbhe";
// ck_assert_int_eq(memcmp(s1, s2, 15), s21_memcmp(s1, s2, 15));



// // 3
// #test memcpy_test_1
// unsigned char src[10]="";
// unsigned char dest[10]="12345678";
// ck_assert_str_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5));

// #test memcpy_test_2
// unsigned char src[10]="2281488";
// unsigned char dest[10]="12345678";
// ck_assert_str_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5));

// #test memcpy_test_3
// unsigned char src[10]="12345678";
// unsigned char dest[10]="";
// ck_assert_str_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5));

// #test memcpy_test_4
// unsigned char src[10]="";
// unsigned char dest[10]="";
// ck_assert_str_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5));

// // 4

// #test memmove_test_1
// unsigned char src1[228] = "abc";
// const char src2[227] = "";
// ck_assert_str_eq(memmove(src1, src2, 3), s21_memmove(src1, src2, 3));

// #test memmove_test_2
// unsigned char src1[228] = "abcABCABCABCACB";
// const char src2[227] = "abcabcabcabcabc";
// ck_assert_str_eq(memmove(src1, src2, 3), s21_memmove(src1, src2, 3));

// #test memmove_test_3
// unsigned char src1[228] = "adadad";
// const char src2[227] = "ada";
// ck_assert_str_eq(memmove(src1, src2, 0), s21_memmove(src1, src2, 0));

// #test memmove_test_4
// unsigned char src1[228] = "148814881488148814881488";
// const char src2[227] = "228228228228228";
// ck_assert_str_eq(memmove(src1, src2, 137), s21_memmove(src1, src2, 137));


// #test memmove_test_5
// unsigned char src1[228] = "ya lublu lizat' jopu tvoey mame";
// const char src2[227] = "i pape";
// ck_assert_str_eq(memmove(src1, src2, 137), s21_memmove(src1, src2, 137));

// // 5
// #test memset_test_1
// char dest[5] = "";
// int ch = (int)'a';
// ck_assert_str_eq(memset(dest, ch, 2), s21_memset(dest, ch, 2));

// #test memset_test_over
// char dest[5] = "\0";
// int ch = (int)'a';
// ck_assert_str_eq(memset(dest, ch, 0), s21_memset(dest, ch, 0));

// // 6
// #test strcat_test_add_to_empty
// char dest[10] = "";
// char src[5] = "123";
// ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));


// #test strcat_test_add_empty
// char dest[10] = "123";
// char src[5] = "";
// ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));


// #test strcat_test_add_empty_to_empty
// char dest[10] = "";
// char src[5] = "";
// ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));

// // 7
// #test strncat_test_base
// char dest[10] = "qwe";
// char src[5] = "123";
// ck_assert_str_eq(strncat(dest, src, 2), s21_strncat(dest, src, 2));


// #test strncat_test_zero
// char dest[10] = "qwe";
// char src[5] = "123";
// ck_assert_str_eq(strncat(dest, src, 0), s21_strncat(dest, src, 0));


// #test strncat_test_over
// char dest[10] = "qwe";
// char src[5] = "123";
// ck_assert_str_eq(strncat(dest, src, 4), s21_strncat(dest, src, 4));

// // 8

// #test strchr_1
// const char src[15] = "1234567890";
// ck_assert_str_eq(strchr(src, '5'), s21_strchr(src, '5'));


// #test strchr_2
// const char src[15] = "1234567890";
// ck_assert_pstr_eq(strchr(src, 'a'), s21_strchr(src, 'a'));

// // 9
// #test strcmp_1
// const char src1[15] = "1234567890";
// const char src2[15] = "1234567890";
// ck_assert_int_eq(strcmp(src1, src2), s21_strcmp(src1, src2));


// #test strcmp_2
// const char src1[15] = "12345";
// const char src2[15] = "1234567890";
// ck_assert_int_eq(strcmp(src1, src2), s21_strcmp(src1, src2));


// #test strcmp_3
// const char src1[15] = "1234599999";
// const char src2[15] = "1234567890";
// ck_assert_int_eq(strcmp(src1, src2), s21_strcmp(src1, src2));

// //10
// #test strncmp_test_10_str1_empty
// // Сравниваемые строки
// char str1[100] = "";
// char str2[100] = "123";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// #test strncmp_test_10_str2_empty
// // Сравниваемые строки
// char str1[100] = "123";
// char str2[100] = "";
// ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));

// #test strncmp_test_10_identical
// // Сравниваемые строки
// char str1[100] = "123";
// char str2[100] = "123";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// #test strncmp_test_10_len_str1_less_than_str2
// // Сравниваемые строки
// char str1[100] = "12";
// char str2[100] = "123";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// #test strncmp_test_10_len_str2_less_than_str1
// // Сравниваемые строки
// char str1[100] = "abc";
// char str2[100] = "bc";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// #test strncmp_test_10_str2_less_than_str1
// // Сравниваемые строки
// char str1[100] = "12";
// char str2[100] = "11";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// #test strncmp_test_10_str1_less_than_str2
// // Сравниваемые строки
// char str1[100] = "1";
// char str2[100] = "9";
// ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));

// // 11

// #test strcpy_1
// const char str1[15] = "12345678900";
// char str2[20];
// ck_assert_str_eq(strcpy(str2, str1), s21_strcpy(str2, str1));

// #test strcpy_to_empty_2
// const char str1[15] = "";
// char str2[20];
// ck_assert_str_eq(strcpy(str2, str1), s21_strcpy(str2, str1));

// // 12

START_TEST(strncpy_1) {
#line 224
const char str1[15] = "123345667";
char str2[20];
ck_assert_str_eq(strncpy(str2, str1, 5), s21_strncpy(str2, str1, 5));
}
END_TEST

START_TEST(strncpy_2) {
#line 229
const char str1[15] = "123345667";
char str2[20];
ck_assert_str_eq(strncpy(str2, str1, 13), s21_strncpy(str2, str1, 13));
}
END_TEST

START_TEST(strncpy_3) {
#line 234
const char str1[15] = "";
char str2[20];
ck_assert_str_eq(strncpy(str2, str1, 5), s21_strncpy(str2, str1, 5));
}
END_TEST

START_TEST(strncpy_4) {
#line 239
const char str1[15] = "123345667";
char str2[20];
ck_assert_str_eq(strncpy(str2, str1, 0), s21_strncpy(str2, str1, 0));

// // 13
// #test strcspn_1
// const char str1[] = "LOST: 4-8-15-16-23-42";
// const char str2[] = "1234567890";
// ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1, str2));

// #test strcspn_2
// const char str1[] = "LOST: 4-8-15-16-23-42";
// const char str2[] = "123567890";
// ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1, str2));

// #test strcspn_3
// const char str1[] = "LOST: ";
// const char str2[] = "1234567890";
// ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1, str2));

// #test strcspn_4
// const char str1[] = "";
// const char str2[] = "1234567890";
// ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1, str2));

// // 14
// #test strerror_default
// for (int i = -6; i < ERRORS_COUNT + 123; i++)
// {
//     ck_assert_str_eq(strerror(i), s21_strerror(i));
// }

// // 15
// #test len_test_1
// char s1[] = "fffff";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// #test len_test_empty
// char s1[] = "";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// #test len_test_2
// char s1[] = "228";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// #test len_test_emptyyy
// char s1[] = "";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// #test len_test_whitespaces
// char s1[] = "                      ";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// #test len_test_single_char
// char s1[] = "2";
// ck_assert_uint_eq(strlen(s1), s21_strlen(s1));

// // 16
// #test strpbrk_default
// char s1[] = "223412430242143242";
// char s2[] = "0fdefe";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// #test strpbrk_s2_empty
// char s1[] = "223412430242143242";
// char s2[] = "";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// #test strpbrk_no_match
// char s1[] = "223412430242143242";
// char s2[] = "dfsdf";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// #test strpbrk_no_s1
// char s1[] = "";
// char s2[] = "dfsdf";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// #test strpbrk_both_empty
// char s1[] = "";
// char s2[] = "";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// #test strpbrk_last_match
// char s1[] = "223412430242143242v";
// char s2[] = "v";
// ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));

// // 17
// #test strrchr_default
// char s1[] = "223412430242143242v";
// int c = '1';
// ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));

// #test strrchr_no_match
// char s1[] = "223412430242143242";
// int c = 123;
// ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));

// #test strrchr_empty_str
// char s1[] = "";
// int c = '1';
// ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));

// #test strrchr_last_match
// char s1[] = "223412430242143242";
// int c = '2';
// ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));

// // 18
// #test strspn_default
// char s1[] = "123fef";
// char s2[] = "0123456789";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strspn_s1_empty
// char s1[] = "";
// char s2[] = "0123456789";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strspn_s2_empty
// char s1[] = "123fef";
// char s2[] = "";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strspn_both_empty
// char s1[] = "123fef";
// char s2[] = "";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strspn_no_match
// char s1[] = "123fef";
// char s2[] = "dddas";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strspn_middle_match
// char s1[] = "123fef21";
// char s2[] = "fef";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// // 19
// #test strstr_default
// char s1[] = "223412430242143242";
// char s2[] = "412";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strstr_last_match
// char s1[] = "223412430242143242";
// char s2[] = "242";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strstr_no_match
// char s1[] = "223412430242143242";
// char s2[] = "dfwef";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strstr_s1_empty
// char s1[] = "";
// char s2[] = "412";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strstr_s2_empty
// char s1[] = "223412430242143242";
// char s2[] = "";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));

// #test strstr_boh_empty
// char s1[] = "";
// char s2[] = "";
// ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

Suite *suite_strncpy(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, strncpy_1);
    tcase_add_test(tc1_1, strncpy_2);
    tcase_add_test(tc1_1, strncpy_3);
    tcase_add_test(tc1_1, strncpy_4);

    return s1;
}

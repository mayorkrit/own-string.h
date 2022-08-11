#include "../tests_includes/s21_tests.h"

/* SPRINTF */


START_TEST(sprintf_test_2) {
    char output[200] = "";
    char s21_output[200] = "";
    sprintf(output, "A");
    s21_sprintf(s21_output, "A");
    ck_assert_str_eq(s21_output, output);
} END_TEST

START_TEST(sprintf_test_3) {
    char output[200] = "";
    char s21_output[200] = "";
    unsigned int cout = 1000;
    sprintf(output, "%.15f %d %3u %-s", 3.765, 6, cout, "Hello");
    s21_sprintf(s21_output, "%.15f %d %3u %-s", 3.765, 6, cout, "Hello");
    ck_assert_str_eq(s21_output, output);
} END_TEST



START_TEST(printf_dTest_5) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    long int n = 3;
    s21_res = s21_sprintf(s21_output, "%ld%3c  % d   %+d %d%-2.d", n, 'A', 5, 7, 3, 3);
    res = sprintf(output, "%ld%3c  % d   %+d %d%-2.d", n, 'A', 5, 7, 3, 3);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


START_TEST(printf_iTest_6) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    short int n = 11;
    s21_res = s21_sprintf(s21_output, "%hi %.5i %0i", n, -46, 57);
    res = sprintf(output, "%hi %.5i %0i", n, -46, 57);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


START_TEST(printf_sTest_7) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    s21_res = s21_sprintf(s21_output, "%-2s %.3s %s %ls", "Hello", " world", "!", "ABC");
    res = sprintf(output, "%-2s %.3s %s ", "Hello", " world", "!");
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST

START_TEST(printf_uTest_8) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    unsigned short n = 2;
    unsigned long m = 33;
    s21_res = s21_sprintf(s21_output, "%hu %lu %u", n, m, (unsigned)58432322);
    res = sprintf(output, "%hu %lu %u", n, m, (unsigned)58432322);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


Suite* sprintf_test(void) {
    Suite* suite = suite_create("sprintf_test");
    TCase* tcase_core = tcase_create("PART 3");
    tcase_add_test(tcase_core, sprintf_test_2);
    tcase_add_test(tcase_core, sprintf_test_3);
    tcase_add_test(tcase_core, printf_dTest_5);
    tcase_add_test(tcase_core, printf_iTest_6);
    tcase_add_test(tcase_core, printf_sTest_7);
    tcase_add_test(tcase_core, printf_uTest_8);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
/* SPRINTF */



/* MAIN */
int suite_fails(Suite *s) {
    SRunner *srun = srunner_create(s);
    srunner_run_all(srun, CK_NORMAL);
    int fails = srunner_ntests_failed(srun);
    srunner_free(srun);
    return fails;
}

int set_fails (Suite* (*tests[])(), int n) {
    int summary = 0;
    for (int i = 0; i < n; i++)
    summary += suite_fails(tests[i]());
    return summary;
}

// int main(void) {
//     Suite* (*tests[25])() = {strcmp_test, strcpy_test, strncmp_test,
//         strncpy_test, strlen_test, memset_test, streror_test, strtok_test,
//         strtoupper_test, strtolower_test, strrchr_test, strpbrk_test,
//         strspn_test, strstr_test, memcpy_test, memcmp_test, memchr_test,
//         memmove_test, trim_test, insert_test, strchr_test, strcat_test,
//         strncat_test, strcspn_test, sprintf_test};
//     if (set_fails(tests, 25) != 0) {
//         return EXIT_FAILURE;
//     }
//     return EXIT_SUCCESS;
// }
/* MAIN */


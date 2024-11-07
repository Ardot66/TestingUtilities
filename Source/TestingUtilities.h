#ifndef __TESTING_UTILITIES__
#define __TESTING_UTILITIES__

#include <stdio.h>
#include <stddef.h>

// Defines a test which compares expressions [a] and [b] with the comparer [comparer] and prints the result.
// Pattern is a printf string pattern which should handle printing the values of [a] and [b] respectively.
// Varidiac args are for expressions that should be run in the case that the test failed, so that your testing recovers from error cases.
// An example use would be TEST(myValue, ==, 0, "%llu and %llu", return;)
#define TEST(a, comparer, b, pattern, ...) \
{\
    const char *expressionString = #a " " #comparer " " #b; \
    TestsCount++; \
    if((a) comparer (b)) \
    {\
        printf("Test Passed: %s\n", expressionString); \
        TestsPassed ++;\
    }\
    else\
    {\
        printf("Test Failed: %s; Values are %" #pattern ", %" #pattern "; at %s line %d\n", expressionString, a, b, __FILE__, __LINE__);\
        __VA_ARGS__\
    }\
}

// Marks the end of a testing program and prints the number of tests passed and failed.
#define TestsEnd() printf("Testing complete, %llu out of %llu tests passed.\n", TestsPassed, TestsCount)

static size_t TestsCount = 0;
static size_t TestsPassed = 0;

#endif
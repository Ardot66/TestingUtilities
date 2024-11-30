#ifndef __TESTING_UTILITIES__
#define __TESTING_UTILITIES__

#include <stdio.h>
#include <stddef.h>

#define TEST_BASE(a, comparer, b, onPass, onFail)\
{\
    const char *expressionString = #a " " #comparer " " #b; \
    TestsCount++; \
    if((a) comparer (b)) \
    {\
        onPass\
        TestsPassed ++;\
    }\
    else\
    {\
        onFail\
    }\
}

#define TEST_VERBOSE(message, a, b, pattern) printf(message ": %s; Values are %" #pattern ", %" #pattern "; at %s line %d\n", expressionString, a, b, __FILE__, __LINE__);

// Docs for TEST:
// Defines a test which compares expressions [a] and [b] with the comparer [comparer] and prints the result.
// Pattern is a printf string pattern which should handle printing the values of [a] and [b] respectively.
// Varidiac args are for expressions that should be run in the case that the test failed, so that your testing recovers from error cases.
// An example use would be TEST(myValue, ==, 0, "%llu and %llu", return;)

#ifdef TESTING_UTILITIES_VERBOSE
#define TEST(a, comparer, b, pattern, ...) TEST_BASE(a, comparer, b, \
    TEST_VERBOSE("Test Passed", a, b, pattern),\
    TEST_VERBOSE("Test Failed", a, b, pattern) __VA_ARGS__)

#else
#define TEST(a, comparer, b, pattern, ...) TEST_BASE(a, comparer, b, \
    , \
    TEST_VERBOSE("Test Failed", a, b, pattern) __VA_ARGS__)

#endif

// Marks the end of a testing program and prints the number of tests passed and failed.
#define TestsEnd() printf("Testing complete, %llu out of %llu tests passed.\n", TestsPassed, TestsCount)

static size_t TestsCount = 0;
static size_t TestsPassed = 0;

#endif
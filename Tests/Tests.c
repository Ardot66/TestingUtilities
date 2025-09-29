#define TESTING_UTILITIES_VERBOSE
#include "TestingUtilities.h"
#include <stdlib.h>

int main(int argCount, char **argValues)
{
    TEST(10ull, ==, 10ull, exit(1);)
    TEST(9ull, ==, 10ull)

    TestsEnd();
    
    if(TestsCount == 2 && TestsPassed == 1)
    {
        printf("\nMetatesting passed\n\n");
    }
    else
        printf("\nMetatesting failed\n\n");
}
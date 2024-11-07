#include "TestingUtilities.h"
#include <stdlib.h>

int main(int argCount, char **argValues)
{
    TEST(10ull, ==, 10ull, llu, exit(1);)
    TEST(9ull, ==, 10ull, llu)

    TestsEnd();
    
    if(TestsCount == 2 && TestsPassed == 1)
    {
        printf("\nMetatesting passed\n\n");
    }
    else
        printf("\nMetatesting failed\n\n");
}
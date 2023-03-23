#include <iostream>
#include "../inc/test.h"

#define TEST_ON

int main() {

#ifdef TEST_ON
    test();
#endif
    return 0;
}

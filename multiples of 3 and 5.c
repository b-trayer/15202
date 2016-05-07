/*
Copyright © 2016 g0st
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the COPYING file for more details.

Author: gh0st
Favorite music composer: Bach
*/
#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    
    printf("%d", sum);
    return 0;
}
//
//  main.c
//  Linh tinh
//
//  Created by Dao Duy Nhan on 28/01/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
int main ()
{
    int i=0;
    char str[]="test ttring.\n";
    char c;
    while (str[i])
    {
        c=str[i];
        putchar (toupper(c));
        i++;
    }
    return 0;
}
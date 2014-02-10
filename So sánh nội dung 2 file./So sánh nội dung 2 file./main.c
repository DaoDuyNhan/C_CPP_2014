//
//  main.c
//  So sánh nội dung 2 file.
//
//  Created by Dao Duy Nhan on 11/02/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

FILE *f1, *f2;

int main(int argc, const char * argv[])
{
    if (argc != 3) {
        printf("Error agrument!\n");
        exit(1);
    }
    f1 = fopen(argv[1], "r");
    if (NULL == f1) {
        printf("Cant not open f1!\n");
        exit(1);
    }
    f2 = fopen(argv[2], "r");
    if (NULL == f2) {
        printf("Cant not open f2!\n");
        exit(1);
    }
    char c1, c2;
    while (1) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 != c2) {
            printf("2 file not equal!\n");
            exit(0);
        }
        if (EOF == c1) {
            printf("2 file is equal!\n");
            exit(0);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}


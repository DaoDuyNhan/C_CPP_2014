//
//  main.c
//  Hiển thị file dưới dạng mã ASCII
//
//  Created by Dao Duy Nhan on 25/01/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    char path[256];
    FILE* input;
    char character;
    if (argc == 1) {
        printf("Bạn hãy nhập file cần hiển thị: ");
        gets(path);
        input = fopen(path, "r");
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("\nKhông thể mở được file!\n");
        exit(1);
    }
    while ( (character = fgetc(input)) != EOF) {
        if (character == '\n') {
            printf("\n");
            continue;
        }
        if (character <= 126 && character >=32) {
            printf("%c", character);
            continue;
        }
        printf("{%d}", character, character);
    }
    character = fgetc(input);
    return 0;
}


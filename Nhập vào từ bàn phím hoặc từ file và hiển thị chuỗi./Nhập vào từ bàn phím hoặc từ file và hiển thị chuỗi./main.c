//
//  main.c
//  Nhập vào từ bàn phím hoặc từ file và hiển thị chuỗi.
//
//  Created by Dao Duy Nhan on 26/01/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    // Nhập vào một xâu bất kí, hiển thị xâu vừa nhập ra màn hình và mã từng kí tự tương ứng.
    char string[1024];
    int leng;
    printf("Bạn hãy nhập vào một xâu: ");
    gets(string);
    puts(string);
    for (leng = 0 ; leng < 10; leng ++) {
        printf("%d-", string[leng]);
    }
    // Nhập vào hai kí tự, hiển thị nó dưới dang 1 kí tự.
    for (leng =0; leng < 10; leng++) {
        string[leng] = 0;
    }
    printf("Mã kí tự thứ nhất: ");
    scanf("%d", &string[1]);
    printf("Mã kí tự thứ hai: ");
    scanf("%d", &string[1]);
    puts(string);
    return 0;
}


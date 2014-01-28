//
//  main.c
//  Hiển thị bảng mã ASSCII và giá trị số tương ứng.
//
//  Created by Dao Duy Nhan on 25/01/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i;
    printf("Các kí tự không hiển thị được:\n");
    printf("0\t^@\tNull Character-Kí tự Null\n");
    printf("1\t^A\tStart of Header-Kí tự rỗng\n");
    printf("2\t^B\tStart of Text-Bắt đầu văn bản\n");
    printf("3\t^C\tEnd of Text-Kết thúc văn bản\n");
    printf("");
    for (i = 0; i <= 31 ; i++) {
        printf("\"%c\" có giá trị %d\n", i, i);
    }
    return 0;
}


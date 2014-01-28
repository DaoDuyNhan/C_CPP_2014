//
//  main.c
//  Input vào một dãy các đối tượng. Output một dãy các đối tượng riêng biệt.
//
//  Created by Dao Duy Nhan on 26/01/2014.
//  Copyright (c) Năm 2014 Dao Duy Nhan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_stack{
    int thutu;
    struct node_stack *next;
};

typedef struct node_stack node_stack;

struct node_tree{
    char CharCode[20];
    node_stack vitri;
    struct node_tree *lef;
    struct node_tree *right;
};

typedef struct node_tree node_tree;

node_stack* node_end_stack(node_stack *node_current){
    node_stack* node_temp;
    node_temp = node_current->next;
    while (node_temp != NULL) {
        node_current = node_temp;
        node_temp = node_current->next;
    }
    return node_current;
}

node_stack* add_node_stack(node_stack *node_current, int vitri){
    node_stack *new_node;
    new_node = malloc(sizeof(node_stack));
    if (new_node == NULL) {
        printf("Không cấp phát được new_node_stack!\n");
        exit(1);
    }
    node_current = node_end_stack(node_current);
    new_node->thutu = vitri;
    new_node->next = NULL;
    printf("Add new stack node: %p\n", new_node);
    node_current->next = new_node;
    return  new_node;
}

node_tree* add_tree(node_tree **node_current, char *charcode, int vitri){
    int temp;
    if ( *node_current == NULL) {
        printf("Node tree Null\n");
        node_tree *newnode;
        newnode = malloc(sizeof(node_tree));
        if (newnode == NULL) {
            printf("Không thể cấp phát newnode tree!\n");
            exit(1);
        }
        for (temp =0; temp < 20; temp++) {
            newnode->CharCode[temp]=0;
        }
        printf("\n");
        strcpy( newnode->CharCode, charcode);
        for (temp =0; temp < 20; temp++) {
            printf("|%d|->", charcode[temp]);
        }
        printf("\n");
        for (temp =0; temp < 20; temp++) {
            printf("|%d|->", newnode->CharCode[temp]);
        }
        printf("\n");
        printf("Đăng kí: ");
        puts(newnode->CharCode);
        newnode->vitri.thutu=vitri;
        printf("Add new node tree: %p\n", newnode);
        *node_current = newnode;
        return newnode;
    }
    if ( strcmp( (*node_current)->CharCode, charcode) == 0) {
        printf("Node: %s\n", (*node_current)->CharCode);
        for (temp = 0; temp < sizeof((*node_current)->CharCode) ; temp++) {
            printf("|%d|->", (*node_current)->CharCode[temp]);
        }
        printf("\nCompare: %s\n", charcode);
        for (temp = 0; temp < sizeof(charcode) ; temp++) {
            printf("|%d|->", charcode[temp]);
        }
        printf("\n");
        printf("|----> %d\n", strcmp( (*node_current)->CharCode, charcode));
        add_node_stack( &((*node_current)->vitri), vitri);
        return *node_current;
    }
    if ( strcmp( (*node_current)->CharCode, charcode) > 0) {
        printf("Node: %s\n", (*node_current)->CharCode);
        for (temp = 0; temp < sizeof((*node_current)->CharCode) ; temp++) {
            printf("|%d|->", (*node_current)->CharCode[temp]);
        }
        printf("\nCompare: %s\n", charcode);
        for (temp = 0; temp < sizeof(charcode) ; temp++) {
            printf("|%d|->", charcode[temp]);
        }
        printf("\n");
        printf("|----> %d\n", strcmp( (*node_current)->CharCode, charcode));
        return add_tree(  &((*node_current)->lef), charcode, vitri);
    }
    if ( strcmp( (*node_current)->CharCode, charcode) < 0) {
        printf("Node: %s\n", (*node_current)->CharCode);
        for (temp = 0; temp < sizeof((*node_current)->CharCode) ; temp++) {
            printf("|%d|->", (*node_current)->CharCode[temp]);
        }
        printf("\nCompare: %s\n", charcode);
        for (temp = 0; temp < sizeof(charcode) ; temp++) {
            printf("|%d|->", charcode[temp]);
        }
        printf("\n");
        printf("|----> %d\n", strcmp( (*node_current)->CharCode, charcode));
        return add_tree( &((*node_current)->right), charcode, vitri);
    }
    return NULL;
}

int number_of_stack(node_stack *node_current){
    if (node_current == NULL) {
        return 0;
    }
    return 1+ number_of_stack(node_current->next);
}

int number_of_tree( node_tree *node_current){
    if ( node_current == NULL) {
        return 0;
    }
    return 1+ number_of_tree(node_current->lef) + number_of_tree(node_current->right);
}

void show_stack(node_stack *current){
    if (current == NULL) {
        printf("\n");
        return;
    }
    printf("%d -> ", current->thutu);
    show_stack(current->next);
    return;
}

void show_tree(node_tree *current){
    if (current == NULL) {
        printf("\n");
        return;
    }
    show_tree(current->lef);
    printf("+ %p\n\tCharCode:-%s\n\t\tVị trí:", current, current->CharCode);
    show_stack(&current->vitri);
    show_tree(current->right);
    return;
}


int main(int argc, const char * argv[])
{
    // Mở file
    FILE *input, *ouput;
    if (argc != 3) {
        printf("Tham số đầu vào không hợp lệ!\n");
        exit(1);
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Không thể mở được file input!\n");
        exit(1);
    }
    ouput = fopen(argv[2], "w");
    if (ouput == NULL) {
        printf("Không thể mở được file output!\n");
        exit(1);
    }
    // Load dữ liệu
    node_tree *root_tree;
    root_tree = NULL;
    char readed_CharCode[25];
    int offset;
    offset = -1;
    char charreaded;
    charreaded = -5;
    charreaded = fgetc(input);
    while (!feof(input)) {
        //charreaded = fgetc(input);
        while (charreaded == ',' || charreaded == '\n' || charreaded == '\t' || charreaded == ' '){
            charreaded = fgetc(input);
        }
        if (charreaded == EOF) {
            break;
        }
        readed_CharCode[24]=0;
        while (charreaded != ',' && charreaded != '\n' && charreaded != '\t' && charreaded != EOF && charreaded != ' ') {
            readed_CharCode[readed_CharCode[24]] = charreaded;
            readed_CharCode[24] += 1;
            charreaded = fgetc(input);
        }
        readed_CharCode[readed_CharCode[24]] =0;
        offset++;
        printf("Prepair add: %s\n", readed_CharCode);
        add_tree(&root_tree, readed_CharCode, offset);
        for (readed_CharCode[24] = 0; readed_CharCode[24] <= 23; readed_CharCode[24]++ ) {
            readed_CharCode[readed_CharCode[24]] = 0;
        }
    }
    show_tree(root_tree);
    printf("So loai: %d\n", number_of_tree(root_tree));
    getchar();
    return 0;
}


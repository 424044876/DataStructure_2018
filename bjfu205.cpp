//
//  main.cpp
//  bjfu205.2
//
//  Created by fang on 2018/10/8.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include "cstring"
const int N = 500;
using namespace std;

typedef struct{
    char isbn[100];
    char name[100];
    float price;
}Book;

typedef struct{
    Book *elem;
    int length;
}SqList;

void InitSqList(SqList &L){
    L.elem = new Book[N];
    L.length = 0;
}

Book& GetElem(SqList L, int i){
    return L.elem[i];
}

void ShowList(SqList L){
    for (int i=0; i<L.length; i++) {
        printf("%s %s %.2f\n", GetElem(L,i).isbn, GetElem(L,i).name, GetElem(L,i).price);
    }
}

void SortList(SqList &L){
    for (int i=0; i<L.length-1; i++) {
        for (int j=0; j<L.length-1-i; j++) {
            if (L.elem[j].price<L.elem[j+1].price) {
                Book temp = L.elem[j];
                L.elem[j]=L.elem[j+1];
                L.elem[j+1]=temp;
            }
        }
    }
}


int main() {
    SqList lib;
    InitSqList(lib);
    for(int i=0;;i++){
        scanf("%s%s%f", GetElem(lib,i).isbn, GetElem(lib,i).name, &(GetElem(lib,i).price));
        if(GetElem(lib,i).isbn[0]=='0'&&GetElem(lib,i).name[0]=='0'&&GetElem(lib,i).price<1e-6) {
            break;
        }
        lib.length++;
    }
    SortList(lib);
    ShowList(lib);
    return 0;
}
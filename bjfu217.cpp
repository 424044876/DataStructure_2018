//
//  main.cpp
//  ListReverse
//
//  Created by fang on 2018/10/14.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include "cstdio"
#include "cstring"

using namespace std;

typedef struct Books{
    char isbn[200];
    char name[200];
    float price;
    struct Books *next = NULL;
}Book;

//以第一个book作为头指针

inline int getBook(Book &b){
    scanf("%s%s%f",b.isbn, b.name, &b.price);
    if (b.isbn[0]=='0'&&b.name[0]=='0'&&b.price<1e-6) {
        return 0;
    }
    return 1;
}

inline void printBook(Book a){
    printf("%s %s %.2f\n", a.isbn, a.name ,a.price);
}

void appendBook(Book &lis,Book &t){
    Book* temp = &lis;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = new Book;
    strcpy(temp->next->isbn, t.isbn);
    strcpy(temp->next->name, t.name);
    temp->next->price=t.price;
}

void insertBook(Book &lis, int n, Book &t){
    Book *temp = lis.next;
    for (int i=0; i<n-2; i++) {
        temp = temp->next;
    }
    Book *stemp;
    stemp = temp->next;
    temp->next = &t;
    t.next = stemp;
}

void deleteBook(Book &lis, int n){
    Book *temp = lis.next;
    for (int i=0; i<n-2; i++) {
        temp = temp->next;
    }
    Book *stemp;
    stemp = temp->next->next;
    delete temp->next;
    temp->next = stemp;
}

int showBook(Book *lis){
    if(lis->next==NULL){
        return 0;                    //return 0表示链表为空
    }
    Book *temp = lis->next;
    while (temp!=NULL) {
        printBook(*temp);
        temp = temp->next;
    }
    return 1;
}

void reserve(Book *lis){
    if (lis->next==NULL||lis->next->next==NULL) {
        return;
    }
    Book *pre=lis->next;
    Book *cur=pre->next;
    Book *temp=cur->next;
    while (cur->next) {
        cur->next=pre;
        pre=cur;
        cur=temp;
        temp=cur->next;
    }
    cur->next=pre;
    lis->next->next=NULL;
    lis->next=cur;
}

int main(int argc, const char * argv[]) {
    Books lib;
    int num;
    cin>>num;
    for (int i=0; i<num; i++) {
        Book temp;
        cin>>temp.isbn>>temp.name>>temp.price;
        appendBook(lib, temp);
    }
    reserve(&lib);
    showBook(&lib);
    return 0;
}
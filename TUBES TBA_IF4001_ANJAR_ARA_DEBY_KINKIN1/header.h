#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

typedef char infotype;
typedef string infotype2;
typedef struct Elm *adr;
typedef struct Elm2 *adr2;

struct Elm {
    infotype info;
    adr next;
};

struct Elm2 {
    infotype2 info2;
    adr2 next2;
};

struct List {
    adr first;
};

struct List2 {
    adr2 first2;
};

void createList(List &L);
void createList2(List2 &L);
adr alokasi(infotype x);
adr2 alokasi2(infotype2 x);
void insertLast(List &L, adr P);
void insertLast2(List2 &L, adr2 P);
void printInfo(List L);
void printInfo2(List2 L);
void token(string s, List &L1, List2 &L2, adr P, adr2 Q);
void validasi(List &L1, List2 &L2);

#endif // HEADER_H_INCLUDED

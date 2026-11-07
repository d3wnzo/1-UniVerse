#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void buatSimpul (int x);
void awal ();
void cetak ();
void insertKanan();

struct Node{
    int info;
    struct Node *link;
};

typedef struct Node Simpul;
Simpul *p, *FIRST, *LAST, *Q;
int x;

int main(){
    int a[7] = {22,28,7,11,66,63,10};
    int i;
    FIRST = NULL;
    i = 0;
    x = a[i];
    buatSimpul(x);
    awal();
    for (i=1; i<=6; i++){
        x=a[i];
        buatSimpul(x);
        insertKanan();
    }

    cout <<"Nilai sebelum dilakukan insert kanan : ";
    cetak();
    x = 100;
    buatSimpul(x);
    insertKanan();
    cout << endl;
    cout << endl;
    cout <<"Nilai setelah dilakukan insert kanan : ";
    cetak();
    cout << endl;
    cin.get();
}

void buatSimpul (int x){
    p = (Simpul*)malloc(sizeof(Simpul));

    if (p != NULL){
        p->info = x;
    }

    else{
        cout << "pembuatan gagal" << endl;
        cin.get();
        exit(1);
    }
}

void awal (){
    FIRST = p;
    LAST = p;
    p -> link = NULL;
}

void insertKanan(){
    LAST -> link = p;
    LAST = p;
    p -> link = NULL;
}

void cetak (){
    int x;
    Q = FIRST;
    while (Q != NULL){
        x = Q -> info;
        cout << " " << x;
        Q = Q -> link;
    }
}
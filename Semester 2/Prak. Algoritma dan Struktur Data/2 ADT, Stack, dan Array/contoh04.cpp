#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
    string NPM;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct {
    int top;
    NilaiMK Dat[10];
} stack;

void buatSTkosong(stack *S) {
    (*S).top = -1;
}
bool isKosong(stack S) {
    bool hasil = false;

    if(S.top == -1) {
        hasil = true;
    }
    return hasil;
}

bool isPenuh(stack S) {
    bool hasil = false;

    if(S.top ==9) {
    hasil = true;
    }
    return hasil;
}

void Pop(stack *S) {
    if ((*S).top == 0) {
      (*S).top = -1;  
    }
    else {
        if((*S).top != -1) {
        (*S).top = (*S).top - 1;
        }
    }
}
void push(string NPM, string nama_mhs, double nilai, stack *S) {
    if (isPenuh(*S) == 1) {
        cout << "Stack Penuh" << endl;
    }
    else {
    if (isKosong(*S) == 1) {
        (*S).top = 0;
        (*S).Dat[0].NPM = NPM;
        (*S).Dat[0].nama_mhs = nama_mhs;
        (*S).Dat[0].nilai = nilai;
        }
        else {
        (*S).top = (*S).top + 1;
        (*S).Dat[(*S).top].NPM = NPM;
        (*S).Dat[(*S).top].nama_mhs = nama_mhs;
        (*S).Dat[(*S).top].nilai = nilai;
        }
    }
}
void CetakStack(stack S)
{
    if(S.top != -1)
    {
        cout << "MENAMPILKAN STACK " << endl;
        int i;
        for(i=S.top; i>=0; i--)
    {
        cout << "================================================" << endl;
        cout << "Elemen ke              : " << i << endl;
        cout << "Nomor Pokok Mahasiswa  : " << S.Dat[i].NPM << endl;
        cout << "Nama Mahasiswa         : " << S.Dat[i].nama_mhs << endl;
        cout << "Nilai Mahasiswa        : " << S.Dat[i].nilai << endl;
        cout << "================================================" << endl;
    }
}
else
    {
        cout << "Stack Kosong " << endl;
    }
}

int main() {
    stack S;

    buatSTkosong (&S);
    CetakStack(S);
    cout << endl;
    cout << endl;
    cout << "================================================" << endl;
    push ("4524210xxx", "Yanto", 88.75, &S);
    push ("4524210xxx", "Andre", 78.85, &S);
    push ("4524210xxx", "Feriks", 98.65, &S);
    push ("4524210xxx", "Lawir", 68.55, &S);
    CetakStack(S);
    cout << "================================================" << endl;
    cout << endl;
    cout << endl;
    Pop (&S);
    CetakStack(S);
    cout << endl;
    cout << endl;
    Pop(&S);
    CetakStack(S);
    cout << "================================================" << endl;
    return 0;
}
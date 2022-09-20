
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
    system("CLS");
    cout << "+----------------------+\n";
    cout << "| PROGRAM SHIFT CIPHER |\n";
    cout << "+----------------------+\n\n";
    cout << "Teks  : ";
    char teks[100];
    cin.getline(teks,100);
    int i, j, length, pilihan, kunci;
    cout << "Kunci : ";
    cin >> kunci;
    cout << "\n";
    length = strlen(teks);
    cout << "Pilihan: \n1. Enkripsi \n2. Dekripsi \n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    cout << "\n";
    if(pilihan == 1){
        char ch;
        for(int i = 0; teks[i] != '\0'; ++i){
            ch = teks[i];
            if(ch >= 'a' && ch <= 'z'){
                ch = ch + kunci;
                if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
                }  
                teks[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + kunci;
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
                }
                teks[i] = ch;
            }
        }
        printf("Hasil Enkripsi: %s", teks);
    }
    else if(pilihan == 2){
        char ch;
        for(int i = 0; teks[i] != '\0'; ++i){
            ch = teks[i];
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - kunci;
                if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
                }
                teks[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z') {
                ch = ch - kunci;
                if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
                }
                teks[i] = ch;
            }
        }
        cout << "Hasil Dekripsi: " << teks;
    }
    cout << "\n";
    return 0;
}
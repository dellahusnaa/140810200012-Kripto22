/*
Nama    : Della Fauziyyah Husna
NPM     : 140810200012
Kelas   : B
PROGRAM VIGENERE CIPHER
*/

#include <iostream>
#include <string>
using namespace std;

class Vigenere {
    public:
    string key;
    Vigenere(string key){
        for(int i = 0; i < key.size();++i){
            if (key[i] >= 'A' && key [i] <= 'Z')
                this->key += key [i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key [i] + 'A' - 'a';
        }
    }
    
    string enkripsi(string text){
        string out;
    
        for (int i = 0, j = 0; i < text.length(); ++i){
            char c = text[i];
        
            if (c >= 'a' && c<= 'z')
            c += 'A' - 'a';
            else if ( c < 'A' || c> 'Z')
            continue;
        
            out += (c +key[j] -2 * 'A') %26 +'A';
            j = (j +1) % key.length();
        }
        return out;
    }

    string deskripsi(string text){
        string out;
        for (int i = 0, j = 0; i < text.length(); ++i){
            char c = text[i];
            
            if (c >= 'a' && c<= 'z')
            c += 'A' - 'a';
            else if ( c < 'A' || c> 'Z')
            continue;
        
            out += (c - key[j] +26 ) %26 +'A';
            j = (j +1) % key.length();
        }
        return out;
    }
};

int main(){
    string a,b;
    cout<<endl;
    cout<<"-----Program Vigenere Cipher-----";
    cout<<endl;
    cout<<"Masukkan Plaintext : ";
    cin>>a;
    cout<<"Masukkan Key       : ";
    cin>>b;
    string original=a;
    Vigenere chiper=b;
    
    string encrypted = chiper.enkripsi(original);
    string decrypted = chiper.deskripsi(encrypted);
    cout<<endl;
    cout<<"Hasil Enkripsi    : "<<encrypted<<endl;
    cout<<"Hasil Dekripsi    : "<<decrypted<<endl;
}
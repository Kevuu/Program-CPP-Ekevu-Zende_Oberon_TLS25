#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    char lc = tolower(static_cast<unsigned char>(c));
    return lc=='a' || lc=='e' || lc=='i' || lc=='o' || lc=='u';
}

string reverseString(const string& str) {
    string reversed;

    for (int i = str.size(); i-- > 0;) {
    reversed += str[i];
    }

    return reversed;
}

string encodeMachine(const string &input) {
    string password;
    
    if (input.empty()) return "";

    int asciiFirst = static_cast<unsigned char>(input[0]);
    string asciiStr = to_string(asciiFirst);

    for (char c : input) {
        if (!isVowel(c)) {
            password.push_back(c);
        }
    }

    password = reverseString(password);

    int len = password.size();
    int mid = (len + 1) / 2; 
    password = password.substr(0, mid) + asciiStr + password.substr(mid);
    return password;
}

string decodeMachine(const string &password) {
    string kiri, tengah, kanan;
    for (char c : password) {
        if (isdigit(c))
            tengah.push_back(c);
        else if (tengah.empty())
            kiri.push_back(c);
        else
            kanan.push_back(c);
    }

    if (digits.empty()) return password;

    int asciiInt = stoi(tengah);
    char asciiChar = static_cast<char>(asciiInt);

    string word = kiri + kanan;
    word = reverseString(word);
    if (word.empty() || word[0] != asciiChar) {
        word = asciiChar + word;
    }
    return word;
}

int main() {
    string encode, decode;
    cout<<"Masukkan kata : ";
    cin>>encode;
    cout<<"Masukkan kode sandi yang akan ditebak : ";
    cin>>decode;

    cout <<"Hasil pertama :"<<encode<<" --> "<< encodeMachine(encode) << endl;

    cout <<"Hasil kedua :"<<decode<<" --> "<< decodeMachine(decode) << endl;

    return 0;
}
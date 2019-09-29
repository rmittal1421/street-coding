#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    char direc; cin>>direc;
    int s; cin>>s;

    string word; cin>>word;

    if(s == 0) {
        cout << word;
        return 0;
    }
    s *= (direc == 'D') ? -1 : 1;

    for(char c: word) {
        int shift = s;
        if(shift > 0) {
            if('z' - c < shift) {
                shift -= 'z' - c;
                c = 'a' - 1;
            } 
        } else {
            if(c - 'a' < -shift) {
                shift += c - 'a';
                c = 'z' + 1;
            }
        }
        c += shift;
        cout << c;
    }

    return 0;
}
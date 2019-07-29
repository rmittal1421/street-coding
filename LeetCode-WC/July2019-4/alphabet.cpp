#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string alphabetBoardPath(string target) {
    int startI = 0;
    int startJ = 0;
    string result = "";
    for (int i = 0; i < target.length(); i++) {
        char it = target[i];
        int itI = (it - 'a')/5;
        int itJ = (it - 'a')%5;

        if (itI < startI) {
            while (startI - itI != 0) result += "U", startI--;
        }
        if (itJ < startJ) {
            while (startJ - itJ != 0) result += "L", startJ--;
        } 

        if (itI > startI) {
            while (itI - startI != 0) result += "D", startI++;
        } 
        if (itJ > startJ) {
            while (itJ - startJ != 0) result += "R", startJ++;
        }        

        if (itI == startI && itJ == startJ) {
            cout << itI << ", " << itJ << endl;
            result += "!";
            startI = itI;
            startJ = itJ;
        }
    }
    return result;
}

int main() {
    cout << "Result: " << alphabetBoardPath("zdz") << endl;
    return 0;
}












#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string alphabetBoardPath(string target) {
    int currentI = 0;
    int currentJ = 0;
    string result = "";
    for (int i = 0; i < target.length(); i++) {
        char it = target[i];
        int itI = (it - 'a')/5;
        int itJ = (it - 'a')%5;

        int shiftInRows = itI - currentI;
        int shiftInCols = itJ - currentJ;

        while (shiftInRows != 0 || shiftInCols != 0) {
            if (shiftInRows > 0) {
                if (!(currentI == 4 && currentJ != 0)) {
                    result += "D";
                    currentI++;
                    shiftInRows--;
                }
            } else if (shiftInRows < 0) {
                result += "U";
                currentI--;
                shiftInRows++;
            }

            if (shiftInCols > 0) {
                if (!(currentJ == 0 && currentI == 5)) {
                    result += "R";
                    currentJ++;
                    shiftInCols--;
                }
            } else if (shiftInCols < 0) {
                result += "L";
                currentJ--;
                shiftInCols++;
            }
        }        

        if (itI == currentI && itJ == currentJ) {
            cout << itI << ", " << itJ << endl;
            result += "!";
            currentI = itI;
            currentJ = itJ;
        }
    }
    return result;
}

int main() {
    cout << "Result: " << alphabetBoardPath("zdz") << endl;
    return 0;
}












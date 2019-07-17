#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
	srand(time(0));
    int t, r, c;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> r >> c;
        std::vector<pair<int, int> > moves;

        std::map<char,int> cells;
        for (int j=1; j <= r; j++) {
        	for (int k = 1; k <= c; k++) {
        		cells.insert (std::pair<int, int> (j,k));
        	}
        }

        int randR, randC;
        randR = (rand() % 5) + 1;
        randC = (rand() % 5) + 1;

        cout << randR << " " << randC << endl;

        // cout << "Case #" << i << ": " <<  << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include <unordered_map>
#include <utility>

using namespace std;

int main () {
    int t, hn, len;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        std::vector<int> vCipher;
        cin >> hn >> len;

        for (int z = 0; z < len; z++) {
            int val;
            cin >> val;
            vCipher.push_back (val);
        }

        int search, searchedN;
        bool found = false;
        std::vector<int> v;
        std::queue<int> storage;
        unordered_map<int, pair<int, int> > keyValue;

        for (int j = 2; j <= hn; j++) {
            bool notPrime = false;
            for (int x : v) {
                if (j%x == 0) {
                    notPrime = true;
                    break;
                }
            }
            if (!notPrime) {
                for (int n : vCipher) {
                    if (n%j==0) {
                        storage.push (n);
                        search = j;
                        found = true;
                    }
                }
                v.push_back (j);
                notPrime = false;
            }

            if (found) break;
        }



        cout << "search is :" << search << endl;
        
    }
    return 0;
}






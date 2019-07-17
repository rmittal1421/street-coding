// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
	cout << gcd (23,23) << endl;; 
	// int t, hn, len;
 //    cin >> t;

 //    for (int i = 1; i <= t; i++) {
 //        std::vector<int> vCipher;
 //        std::vector<int> vPrimes;
 //        cin >> hn >> len;

 //        for (int z = 0; z < len; z++) {
 //            int val;
 //            cin >> val;
 //            vCipher.push_back (val);
 //        }

 //        int value;
 //        int first, last;
 //        value = gcd (vCipher[0], vCipher[1]);

 //        for (int j = 0; j < len-1; j++) {
 //        	int a = vCipher[j];
 //        	int b = vCipher[j+1];
 //        	if (a == b) {
 //        		int count = 0;
 //        		while (vCipher[j] == vCipher[j+1]) {
 //        			count++;
 //        			j++;
 //        		}
 //        	} 
 //        	value = gcd (vCipher[j],vCipher[j+1]);

 //        	if (j == 0) {
 //        		vPrimes.push_back (vCipher[j]/value);
 //        	}
 //        	while (count != 0) {
 //        		vPrimes.push_back (value);
 //        	}
 //        	if (j == len-2) {
 //        		vPrimes.push_back (vCipher[j+1]/value);
 //        	}
 //        }

 //        std::vector<int> sortedVPrimes (vPrimes);
 //        std::sort (sortedVPrimes.begin(), sortedVPrimes.end());

 //        std::map<int,char> charMap;

 //        char ch = 'A';
 //        for (int x : sortedVPrimes) {
 //        	if (charMap.find(x) == charMap.end()) {
 //        		charMap.insert (std::pair<int,char>(x,ch));
 //        		ch++;
 //        	}
 //        }

 //        string s = "";
 //        for (int x : vPrimes) {
 //        	s += charMap[x];
 //        }
 //        cout << "Case #" << i << ": " << s << endl;
 //    }
    return 0;
}







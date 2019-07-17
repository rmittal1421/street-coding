#include <iostream>

using namespace std;

bool isSame (string s) {
	if (s.length() == 0 || s.length() == 1) {
		return true;
	}

	if (s[0] == s[s.length()-1]) {
		return isSame (s.substr(1,s.length()-2));
	} else {
		return false;
	}
}

string longestPalindrome(string s) {
	int max = 0;
	string biggestString = "";

	for (int i = 0; i < s.length(); i++) {
		for (int j = s.length() - 1; j > i; j--) {
			if (s[i] == s[j]) {
				string str = s.substr (i, (j-i+1));
				if (isSame (str)) {
					if (str.length() > max) {
						max = str.length();
						biggestString = str;
					}
					break;
				}
			}
		}
	}

	if (max == 0 && s.length() != 0) {
		return string(1, s[0]);
	}

	return biggestString;
}

int main () {
	cout << longestPalindrome ("babad") << endl;
	return 0;
}
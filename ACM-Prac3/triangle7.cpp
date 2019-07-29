#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int help (int n) {
	int sum = 0;
	int max = (n%2 == 0) ? n/2 - 1 : n/2;
	for (int i = 0; i <= max; i++) {
		sum += 2*i + ((n%2==0) ? 1 : 0);
	}
	return sum;
}

int count(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		return count(n-1) + (n*n + n)/2 + help(n);
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    while (true) {
        int n; cin>>n;
        if (n == 0) break;
        
        cout << count(n) << endl;
    }
    return 0;
}

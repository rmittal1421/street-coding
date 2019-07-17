#include <iostream>

using namespace std;

int main () {
    int t, n;
    cin >> t;
    int a, b;

    for (int i = 1; i <= t; i++) {
    	cin >> n;
    	a = n;
	    b = 0;
	    int div = 1;
	    int rem = 10;

        while (n>=div) {
        	if ((n%rem)/div == 4) {
        		a -= div;
        		b += div;
        	}
        	div *= 10;
        	rem *= 10;
        }

        cout << "Case #" << i << ": " << a << " " << b << endl;
    }
    return 0;
}
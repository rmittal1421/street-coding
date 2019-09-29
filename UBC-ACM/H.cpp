#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    long long c; cin>>c;

    //eq cd^3 = a^2
    long long sqc = std::sqrtl(c);
    long long d = 1;
    cout << sqc << ' ' << floor(sqc) << ' ' << ceil(sqc) << endl;
    if(floor(sqc) == ceil(sqc)) {
        cout << d;
        return 0;
    }
    while(true) {
        // cout << d << ' ' << d^3 << endl;
        long long ans = sqc * std::sqrtl(d*d*d);
        if(floor(ans) == ceil(ans)) {
            cout << d;
            return 0;
        } else d++;
    }
    return 0;
}
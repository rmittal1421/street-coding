// #include <bits/stdc++.h>   
#include <iostream>
#include <vector>                                     
using namespace std;

int main() {
	vector<int> arr = {7, 4, 8, 1};
	int t = 0;
	for(auto a : arr) t += a;
	int n = arr.size();
	vector<vector<bool>> dp(n+1, vector<bool>(t+1));
	for(int i=0; i<=n; i++)  dp[i][0] = 1;
  for(int i = 0; i <= t; ++i) dp[0][i] = 0;
  dp[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=t; j++) {
			if(arr[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}
	for(auto dd : dp) {
		for(auto d : dd) cout << d << " " ;
		cout << endl;
	}
	int p = t/2;
	int res;
	for(int i=p; i>=0; --i) {
		if(dp[n][i]) {
			res = t - (2*i);
			break;
		}
	}
	cout << res << endl;
	return 0;
} 
/*
	2225: 합분해
*/
#include<iostream>
#include<algorithm>
#define MOD 1000000000;
using namespace std;
long long d[201][201];
int n, k;



int main() {
	cin >> n >> k;
	long long ans = 0;
	
	for (int i = 0; i <= n; i++) {
		d[i][1] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = j; l >= 0; l--) {
				d[j][i] += d[j - l][i - 1] % MOD;
			}
		}
	}

	ans = d[n][k] % MOD;
	
	cout << ans << endl;	
}
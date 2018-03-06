/*
	9465: ½ºÆ¼Ä¿
*/
#include<iostream>
#include<algorithm>
using namespace std;
int d[3][100001];
int a[2][100001];


int f_max(int a, int b, int c) {
	int vmax = a;
	if (vmax < b) vmax = b;
	if (vmax < c) vmax = c;
	return vmax;
}

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		d[2][1] = 0;

		for (int i = 2; i <= n; i++) {
			d[0][i] = max(d[1][i - 1], d[2][i - 1]) + a[0][i];
			d[1][i] = max(d[0][i - 1], d[2][i - 1]) + a[1][i];
			d[2][i] = f_max(d[0][i-1], d[1][i-1], d[2][i-1]);
		}

		int ans = f_max(d[0][n], d[1][n], d[2][n]);
		cout << ans << "\n";
	}
}

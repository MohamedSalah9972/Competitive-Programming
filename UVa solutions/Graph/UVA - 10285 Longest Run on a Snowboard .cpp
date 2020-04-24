#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
const int N = 1e2 + 5;
ll dp[N][N];
int n, m;
ll arr[N][N];
bool valid(int i, int j) {
	return i < n && i >= 0 && j < m && j >= 0;
}
int dy[] = { 0, 0, 1, -1 };
int dx[] = { -1, 1, 0, 0 };

ll sol(int i, int j) {

	ll &ret = dp[i][j];
	if (~ret)
		return ret;
	ret = 0;
	for (int l = 0; l < 4; ++l) {
		int nwi = i + dx[l];
		int nwj = j + dy[l];
		if (valid(nwi, nwj) && arr[i][j] > arr[nwi][nwj]) {
			ret = max(sol(nwi, nwj) + 1, ret);
		}
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		string nm;
		cin >> nm;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		ll ans = 0;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = max(ans, sol(i, j) + 1);
			}
		}
		cout << nm << ": " << ans << endl;
	}
	return 0;
}

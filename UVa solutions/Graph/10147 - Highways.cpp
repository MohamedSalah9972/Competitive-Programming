#include <bits/stdc++.h>
using namespace std;
#define endl			"\n"
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define vi				vector <int>
#define vl				vector <ll>
#define ii				pair <ll,ll>
#define vii				vector <ii>
#define ull				unsigned long long
const double PI = 2 * acos(0.0);
void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 5;
int sz[N] , p[N];
int n;
void init() {
    iota(p, p + n + 5, 0); // 0 1 2 3 .. N
    fill(sz, sz + n + 5, 1);
}

int f(int u){
    return p[u] = (p[u] == u ? u : f(p[u]));
}

bool unite(int u , int v){
    u = f(u);
    v = f(v);

    if(u == v)return true;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
    return false;
}
struct edge{
    int v,u,w;
};
bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
#endif
    run();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        vector<pair<int, int>> v;
        vector<edge> g;
        int connected = 0;
        lp(i, n) {
            edge e;
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));

        }
        int m;
        cin >> m;
        lp(i, m) {
            int x, y;
            cin >> x >> y;
            if (!unite(x, y))connected++;
        }
        if (connected == n - 1) {
            cout << "No new highways need" << endl;
            if (t)cout << endl;
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                edge e;
                e.w = (v[i - 1].first - v[j - 1].first) * (v[i - 1].first - v[j - 1].first) +
                      (v[i - 1].second - v[j - 1].second) * (v[i - 1].second - v[j - 1].second);
                e.u = i;
                e.v = j;
                g.push_back(e);
            }
        }
        sort(all(g), cmp);
        for (auto e:g) {
            if (!unite(e.u, e.v)) {
                unite(e.u, e.v);
                cout << e.u << ' ' << e.v << endl;
            }
        }
        if (t)cout << endl;
    }
    return 0;
}

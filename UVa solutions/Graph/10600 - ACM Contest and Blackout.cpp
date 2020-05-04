#include <bits/stdc++.h>
using namespace std;
#define endl			"\n"
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
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

    if(u == v)return false;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
    return true;
}
struct edge{
    int v,u,w;
    edge(){}
    edge(int v,int u,int w):v(v),u(u),w(w){}
    bool operator < (const edge& e)const{
        return w<e.w;
    }
    bool operator ==(const edge &e)const {
        return v==e.v && u == e.u && w==e.w;
    }
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
        int m;
        cin >> n >> m;
        init();
        vector<pair<int, int>> v;
        vector<edge> g;
        ll cost1 = 0;
        lp(i, m) {
            edge e;
            cin >> e.u >> e.v >> e.w;
            g.push_back(e);
        }
        sort(all(g));
        vector<edge> united;
        for (int i = 0; i < m; ++i) {
            if ((unite(g[i].u, g[i].v))) {
                cost1 += g[i].w;
                united.push_back(g[i]);
            }
        }

        ll cost2 = LONG_LONG_MAX;
        for (int i = 0; i < united.size(); ++i) {
            init();
            ll curCost = 0;
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (g[j] == united[i])continue;
                if (unite(g[j].u, g[j].v)) {
                    curCost += g[j].w ;
                    cnt++;
                }
            }
            if (cnt == n - 1)cost2 = min(cost2, curCost);
        }

        cout << cost1 << ' ' << cost2 << endl;
    }
    return 0;
}

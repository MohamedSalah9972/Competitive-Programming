#include <bits/stdc++.h>
using namespace std;
/*
 *  JUST KEEP GOING
 */
#define endl			'\n'
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define For(i,s)        for(auto i:s)
#define Forr(i,s)        for(auto &i:s)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define vi				vector <int>
#define vl				vector <ll>
#define ii				pair <int,int>
#define vii				vector <ii>
#define vll				vector <pair<ll,ll>>
#define PI				double PPPPPP = 3.14159265358979323846;
#define bit(mask,i) ((mask>>i)&1)
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
        vector<string> __attribute__ ((unused)) args,
        __attribute__ ((unused)) int idx,
        __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e3+3;
vii adj[N];
int n,m,dist[N];
void bellman(){
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int u = 0; u < n; ++u) {
            for(auto v:adj[u]){
                dist[v.first] = min(dist[v.first],dist[u]+v.second); /// relax
            }
        }

    }
}
bool hasNegativeCycle(){
    bellman();
    for (int u = 0; u < n; ++u) {
        for(auto v:adj[u]){
            if(dist[v.first]>dist[u]+v.second){
                return true;
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    int t;
    cin>>t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v, t;
            cin >> u >> v >> t;
            adj[u].emplace_back(v, t);
        }
        if (hasNegativeCycle())
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
    return 0;
}

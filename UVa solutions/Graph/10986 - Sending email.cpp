#include <bits/stdc++.h>
using namespace std;
/*
 *  JUST KEEP GOING
 */
#define endl			'\n'
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
const int N = 20000;
struct edge{
    int from,to,w;
    edge(){}
    edge(int from,int to,int w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const {
        return e.w<this->w;
    }
};
vector<edge> adj[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(u, v, w);
            adj[v].emplace_back(v, u, w);
        }
        vi dist(n, INT_MAX);
        priority_queue<edge> q;
        q.push(edge(s, s, 0));
        dist[s] = 0;
        while (!q.empty()) {
            edge cur = q.top();
            q.pop();
            if (cur.w > dist[cur.to]) {
                continue;
            }
            for (edge e:adj[cur.to]) {
                if (dist[e.to] > dist[e.from] + e.w) {
                    e.w = dist[e.to] = dist[e.from] + e.w;
                    q.push(e);
                }
            }
        }
        //Case #3: unreachable
        cout << "Case #" << tt << ": ";
        if (dist[d] == INT_MAX) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[d] << endl;
        }
    }


    return 0;
}

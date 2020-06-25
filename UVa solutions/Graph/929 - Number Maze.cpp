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
const int N = 1e3+3;
int arr[N][N],n,m;
bool valid(int i,int j) {
    return i >= 1 && i <= n && j <= m && j >= 1;
}
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
struct edge{
    pair<int,int> from,to;
    int w;
    edge(){}
    edge(pair<int,int> from,pair<int,int> to,int w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const {
        return e.w<this->w;
    }
};
ll dist[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    int t;
    cin>>t;
    for (int tt = 0; tt < t; ++tt) {
        cin>>n>>m;
        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j <= m ; ++j) {
                cin>>arr[i][j];
                dist[i][j] = LONG_LONG_MAX;
            }
        }
        priority_queue<edge> pq;
        pq.push(edge({1,1},{1,1},arr[1][1]));
        dist[1][1] = arr[1][1];

        while (!pq.empty()){
            edge cur = pq.top();
            pq.pop();
            if(cur.w>dist[cur.to.first][cur.to.second])
                continue;
            for (int i = 0; i < 4; ++i) {

                int x = cur.to.first+dx[i];
                int y = cur.to.second+dy[i];
                if(!valid(x,y))
                    continue;
                if (dist[x][y] > dist[cur.to.first][cur.to.second] + arr[x][y]) {
                    int w = dist[x][y] = dist[cur.to.first][cur.to.second] + arr[x][y];
                    edge e(cur.to,{x,y},w);
                    pq.push(e);
                }
            }
        }
        cout<<dist[n][m]<<endl;

    }

    return 0;
}

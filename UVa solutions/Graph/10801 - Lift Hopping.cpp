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

void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
struct edge{
    int elevator,floor,w;
    edge(){}
    edge(int elevator,int floor,int w):elevator(elevator),floor(floor),w(w){}
    bool operator < (const edge& e)const {
        return e.w<this->w;
    }
};
int n,k;
int dijkstra(int elevator,int d,vector<edge> adj[5][100]){
    vector<vi> dist(1+5, vi(100,INT_MAX));
    vector<vector<bool>> vis(1+5, vector<bool>(100+9,false));
    priority_queue<edge> q;
    q.push(edge(elevator, 0, 0));
    dist[elevator][0] = 0;

    while (!q.empty()) {
        edge cur = q.top();
        q.pop();
        if (vis[cur.elevator][cur.floor]) {
            continue;
        }
        vis[cur.elevator][cur.floor]=true;
        for (edge e:adj[cur.elevator][cur.floor]) {
            if (dist[e.elevator][e.floor] > dist[cur.elevator][cur.floor] + e.w) {
                e.w = dist[e.elevator][e.floor] = dist[cur.elevator][cur.floor] + e.w;
                q.push(e);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 5; ++i) {
        ans = min(ans,dist[i][d]);
    }
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    while (cin>>n>>k){
        vi T(n);
        for(int &i:T)
            cin>>i;
        cin.ignore();
        vector<edge> adj[5][100];
        vector<vector<bool>> canStop(n,vector<bool>(100));
        for (int i = 0; i < n; ++i) {
            string floors;
            int u = 0;
            canStop[i][0] = true;
            getline(cin, floors);
            stringstream in(floors);
            int v;
            in >> v;
            u = v;
            canStop[i][u] = true;
            while (in >> v) {
                canStop[i][v] = true;
                adj[i][u].emplace_back(i, v, T[i] * abs(v - u));
                adj[i][v].emplace_back(i, u, T[i] * abs(v - u));
                u = v;
            }
        }
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = j+1; l < n; ++l) {
                    if(canStop[j][i] && canStop[l][i]){ /// can switch elevator
                        adj[j][i].emplace_back(l,i,60);
                        adj[l][i].emplace_back(j,i,60);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 5; ++i) {
            ans = min(ans,dijkstra(i,k,adj));
        }
        if(ans==INT_MAX)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}

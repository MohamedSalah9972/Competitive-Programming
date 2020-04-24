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
#define PI				double PPPPPP = 3.14159265358979323846;
#define inf             0x3f3f3f3f
void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
const int N=1e2+5;
vii adj[N];
bool vis[N];
stack<int> stk;
int n;
void ToPo(int node){
    vis[node]=true;
    for(ii to:adj[node]){
        if(!vis[to.first])ToPo(to.first);
    }
    stk.push(node);
}

vector<ll> sssp(int start){
    vector<ll> dist(N,inf);
    dist[start]=0;
    ToPo(start);
    while (!stk.empty()){
        int u = stk.top();
        stk.pop();
        for (ii v:adj[u]) {
            dist[v.first]=min(dist[v.first],dist[u]+v.second);
        }
    }
    return dist;

}

int main() {
    run();
    int t=1;
    while (cin>>n){
        if(n==0)return 0;
        int s;
        cin>>s;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        memset(vis,0, sizeof(vis));
        int to,from;
        while(cin>>from>>to){
            if(!from && !to)break;
            adj[from].push_back({to,-1});
        }

        int idx=s;
        vl dist=sssp(s);
        for (int i = 1; i <= n ; ++i) {
            if(dist[i]<dist[idx]){
                idx=i;
            }
        }
        //Case 1: The longest path from 1 has length 1, finishing at 2.
        cout<<"Case "<<t++<<": The longest path from "<<s<<" has length "<<-dist[idx]<<", finishing at "<<idx<<".\n\n";
    }
    return 0;
}


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

void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
const int N=100+3;
bool vis[N];
vi adj[N];
stack<int> stk;
void dfs(int u){

    vis[u]=true;
    for(int i:adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
    stk.push(u);

}
int main() {
    run();
    int n,m;
    while(cin>>n>>m){
        if(!n && !m)return 0;
        for (int i = 1; i <= n ; ++i) {
            adj[i].clear();
            vis[i]=false;
        }
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= n ; ++i) {
            if(!vis[i])dfs(i);
        }
        while(sz(stk)>1){
            cout<<stk.top()<<' ';
            stk.pop();
        }
        cout<<stk.top()<<endl;
        stk.pop();
    }
    return 0;
}

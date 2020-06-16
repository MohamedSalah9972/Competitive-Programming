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
int n;
bool vis[27][27];
char arr[27][27];
int ans;
int dy[] = {0,1,1,1,0,-1,-1,-1};
int dx[] = {-1,-1,0,1,1,1,0,-1};
bool valid(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
}
void dfs(int i,int j){
    vis[i][j] = true;
    for (int j1 = 0; j1 < 8; ++j1) {
        int new_i = dx[j1]+i,new_j = dy[j1]+j;
        if(valid(new_i,new_j) && !vis[new_i][new_j] && arr[new_i][new_j]=='1'){
            dfs(new_i,new_j);
        }
    }

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    int t=1;
    while(cin>>n){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>arr[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && arr[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        memset(vis,0, sizeof(vis));
        cout<<"Image number "<<t++<<" contains "<<ans<<" war eagles.\n";
        ans=0;
    }



    return 0;
}

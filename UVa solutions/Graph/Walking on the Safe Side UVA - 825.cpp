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
const int N=1e2+3;
bool unsafe[N][N];
int w,h;
ll dp[N][N];
ll count_paths(int i,int j){
    if(i>w || j>h || unsafe[i][j])return 0;
    if(i==w && j==h)return 1;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    return ret=count_paths(i+1,j)+count_paths(i,j+1);
}
int main() {
    run();
    int t;
    cin>>t;
    for (int j = 0; j < t; ++j) {

        cin>>w>>h;
        cin.ignore();
        clr(dp,-1);
        clr(unsafe,0);
        for (int i = 1; i <= w; ++i) {
            string s;
            getline(cin,s);
            stringstream in(s);
            int idx;
            in>>idx;
            while(in>>idx){
                unsafe[i][idx]=true;
            }
        }
        if(j)cout<<endl;
        cout<<count_paths(1,1)<<endl;

    }
    return 0;
}

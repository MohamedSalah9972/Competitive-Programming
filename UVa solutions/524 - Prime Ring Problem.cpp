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
vector<int> v;
bool isPrime(int n){
    if(n%2==0)
        return false;
    for (int i = 3; i*i <= n; i+=2) {
        if(n%i==0)
            return false;
    }
    return true;
}
bool vis[20];
void solve(int i,int prev) {
    if (i == n) {
        if (sz(v) != n)
            return;

        bool ok = true;
        for (int j = 0; j < n - 1; ++j) {
            if (!isPrime(v[j] + v[j + 1]))
                ok = false;
        }
        if (!isPrime(v.back() + 1))
            ok = false;
        if (ok) {
            for (int j = 0; j < n - 1; ++j) {
                cout << v[j] << ' ';
            }
            cout << v.back() << endl;
        }
        return;
    }
    for (int j = 1; j < n ; ++j) {
        if(!vis[j] && isPrime(j+1+prev)){

            vis[j] = true;
            v.push_back(j+1);
            solve(i+1,j+1);
            v.pop_back();
            vis[j] = false;
        }
    }


}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
#endif
    run();
    int t=1;
    while(cin>>n) {
        ///Case 1:
        if(t>1)
            cout<<endl;

        cout << "Case " << t++ << ":\n";
        v.resize(1,1);
        solve(1,1);
    }
    return 0;
}

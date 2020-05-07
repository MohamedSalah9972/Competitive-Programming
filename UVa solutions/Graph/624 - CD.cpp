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
int arr[22],n;
ll s;
ll sl = 0;
void sol(int i,ll sum) {
    if (i == n) {
       if(sum<=s) sl = max(sl,sum);
        return;
    }
    sol(i + 1, sum + arr[i]);
    sol(i + 1, sum);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
#endif
    run();
    while(cin>>s>>n) {
        sl = 0;
        lp(i,n)
            cin>>arr[i];
        sol(0, 0);
        for (int i = 0; i < (1LL<<n); ++i) {
            ll curSum =0 ;
            for (int j = 0; j < n; ++j) {
                if((1LL<<j)&i){
                   curSum+=arr[j];
                }
            }
            if(curSum == sl){
                for (int j = 0; j < n; ++j) {
                    if((1LL<<j)&i){
                        cout<<arr[j]<<' ';
                    }
                }
                cout<<"sum:"<<sl<<endl;
                break;
            }
        }
    }
    return 0;
}

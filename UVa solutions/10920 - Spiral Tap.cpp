#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ii pair<ll, ll>

using namespace std;
const int N = 2e5 + 5;
void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
void printAns(ii ans){
    cout<<"Line = "<<ans.first<<", column = "<<ans.second<<"."<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    int tt=1;
    ll n,p;
    while(cin>>n>>p){
        if(n==0 && p==0)return 0;
        int i = 1,j=1;
        ll k;
        for (; i <= n ; i+=2) {
             k = i*i;
            if(k>=p)
                break;
            j++;
        }
        int c = j+n/2,r=c;
        bool ok =false;
        ii ans;
        for (; r > c-i; --r) {
            if(k==p){
                ok = true;
                ans = {r,c};
                break;
            }
            k--;
        }
        if(ok){
            printAns(ans);
            continue;
        }
        r++,c--;
        int l = c;
        for (; c > l-i+1; c--) {

            if(k==p){
                ok = true;
                ans = {r,c};
                break;
            }
            k--;
        }
        c++;
        if(ok){
           printAns(ans);
           continue;
       }
        r++;
        l = r;
        for (; r <l+i-1 ; ++r) {
              if(k==p){
                  ok = true;
                  ans = {r,c};
                  break;
              }
            k--;
        }
        if(ok){
            printAns(ans);
            continue;
        }
        r--,c++;
        l = c;
        for (; c < l+i-2 ; c++) {
             if(k==p){
                 ok = true;
                 ans = {r,c};
                 break;
             }
            k--;
        }
        if(ok){
            printAns(ans);
            continue;
        }
    }

    return 0;
}

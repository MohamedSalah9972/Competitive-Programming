#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory.h>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
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
#define inf             0x3f3f3f3f
void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
int n;

struct block{
    bool S,W;
    block(){
        S = false;
        W = false;
    }
};
block cant[33][33];
ll dp[33][33];
ii fn,st;
ll countPath(int i,int j){
    if(i<1 || j<1) {
        return 0;
    }
    if(i==st.first&& j==st.second)return 1;
    ll&ret=dp[i][j];
    if(~ret)return ret;
    ret=0;
    if(!cant[i][j-1].S)ret=countPath(i,j-1);
    if(!cant[i-1][j].W)ret+=countPath(i-1,j);
    return ret;
}
int main(){
    run();
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>st.first>>st.second;
        cin>>fn.first>>fn.second;
        int w;
        cin>>w;
        clr(dp,0);
        for (int i = 0; i <= n ; ++i) {
            for (int j = 0; j <= n ; ++j) {
                cant[i][j].S = false;
                cant[i][j].W = false;
            }
        }
        while (w--){
            int i,j;
            char d;
            cin>>i>>j>>d;
            if(d=='S'){
                cant[i][j].S=true;
            }
            else if(d=='N'){
                cant[i][j+1].S=true;
            }
            else if(d=='W'){
                cant[i][j].W=true;
            }
            else{
                cant[i+1][j].W=true;
            }
        }
        dp[st.first][st.second]=1;
        for (int i = st.first; i <= fn.first ; ++i) {
            for (int j = st.second; j <=fn.second ; ++j) {
                if(!cant[i][j+1].S){
                    dp[i][j+1]+=dp[i][j];
                }
                if(!cant[i+1][j].W){
                    dp[i+1][j]+=dp[i][j];
                }
            }

        }
        cout<<dp[fn.first][fn.second]<<endl;
    }

    return 0;
}

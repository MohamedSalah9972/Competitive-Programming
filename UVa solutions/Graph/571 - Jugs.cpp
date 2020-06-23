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
const int N = 1e3+5;
int ca,cb,n,a,b;
string step[]={ "fill A","fill B", "empty A", "empty B", "pour A B", "pour B A"};
bool vis[N][N];
struct node{
  int ca,cb,state;
  node(int ca,int cb,int state=-1){
      this->ca = ca;
      this->cb = cb;
      this->state = state;
  }
  node(){}
};
node prev_[N][N];
bool setState(int state,node& nw) {
    nw.state = state;
    if (state == 0 && nw.ca < ca) { //fill A
        nw.ca = ca;
        return true;
    }
    if(state == 1 && nw.cb<cb){ //fill B
        nw.cb = cb;
        return true;
    }
    if(state == 2 && nw.ca>0){ // empty A
        nw.ca = 0;
        return true;
    }
    if(state == 3 && nw.cb>0){ // empty B
        nw.cb = 0;
        return true;
    }
    if(state == 4 && nw.ca>0 && nw.cb<cb){ //pour A B
        int cbb = nw.cb;
        nw.cb = min(cb,nw.cb+nw.ca);
        nw.ca -=cb-cbb;
        nw.ca = max(nw.ca,0);

        return true;
    }
    if(state == 5 && nw.cb>0 && nw.ca<ca) {// pour B A
        int caa = nw.ca;
        nw.ca = min(ca,nw.ca+nw.cb);
        nw.cb -= ca-caa;
        nw.cb = max(nw.cb,0);
        return true;
    }
    return false;
}
void backtrack(node cur){
    if(cur.cb == 0 && cur.ca == 0){
        return;
    }
    backtrack(prev_[cur.ca][cur.cb]);
    cout<<step[cur.state]<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run();
    while(cin>>ca>>cb>>n){
        queue<node> q;
        q.push(node(0,0));
        prev_[0][0] = node(0,0,-1);
        vis[0][0] = 1;
        node last;
        while(!q.empty()){
            node cur = q.front();
            q.pop();
            if(cur.cb == n)
            {
                last = cur;
                break;
            }
            for (int i = 0; i < 6; ++i) {
                node nw=cur;
                if(setState(i,nw) && !vis[nw.ca][nw.cb])
                {
                    q.push(nw);
                    vis[nw.ca][nw.cb] = true;
                    prev_[nw.ca][nw.cb] = cur;
                }
            }

        }
        backtrack(last);
        cout<<"success"<<endl;
        clr(vis,0);
    }


    return 0;
}

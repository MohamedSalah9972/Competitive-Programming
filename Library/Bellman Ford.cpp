#define vii				vector <pair<int,int>>
const int N = 1e3+3;
vii adj[N];
int n,m,dist[N];
void bellman(){
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int u = 0; u < n; ++u) {
            for(auto v:adj[u]){
                dist[v.first] = min(dist[v.first],dist[u]+v.second); /// relax
            }
        }
    }
}
bool hasNegativeCycle(){
    bellman();
    for (int u = 0; u < n; ++u) {
        for(auto v:adj[u]){
            if(dist[v.first]>dist[u]+v.second){ 
                return true;
            }
        }
    }
    return false;
}

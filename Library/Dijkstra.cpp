struct edge{
    int from,to,w;
    edge(){}
    edge(int from,int to,int w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const {
        return e.w<this->w;
    }
};
vector<edge> adj[N];

vi dist(n, INT_MAX);
priority_queue<edge> q;
q.push(edge(s, s, 0));
dist[s] = 0;
while (!q.empty()) {
    edge cur = q.top();
    q.pop();
    if (cur.w > dist[cur.to]) {
        continue;
    }
    for (edge e:adj[cur.to]) {
        if (dist[e.to] > dist[e.from] + e.w) {
            e.w = dist[e.to] = dist[e.from] + e.w;
            q.push(e);
        }
    }
}

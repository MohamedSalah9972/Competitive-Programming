/// Pascal Triangle
ll C[31][31];
void buildPascal(){

    for(int i = 0; i <= 30; i++)
        for(int j = 0; j <= i; j++){
            if(j == 0)C[i][j]  =1;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];
        }

}

2D cumulative sum:
 
Rule: (p-1)%p=p-1 such that p is prime
long long binpow(long long a, long long b, long long m) {
    // a power b mod m
    a %= m;
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


1.	ll nCr(ll n, ll r) {
2.		long long p = 1, k = 1;
3.		if (n - r < r)
4.			r = n - r;
5.		if (r != 0) {
6.			while (r) {
7.				p *= n;
8.				k *= r;
9.				long long m = __gcd(p, k);
10.				p /= m;
11.				k /= m;
12.				
13.				n--;
14.				r--;
15.			}
16.		}
17.	 
18.		else
19.			p = 1;
20.		return p;
21.	}

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

 
ll countDiv(ll n)
{
	// Note: counting include n
	ll cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i)
				cnt++;
			else
				cnt = cnt + 2;
		}
	}
	return cnt;
}

Prime Factorization using Sieve O(log n) for multiple queries
 
void primeFactors(int n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        cout << n << " ";  
}  

Divisibility
2 => if last of number is even (0, 2, 4, 6, 8). 
3 =>  if the sum of all the individual digits is evenly divisible by 3.
4 => last two digit (e.g. 3628 is divisible by 4 because 28 divisible by 4).
5 => if the last digit of the number is 0 or 5.
6 => if they are evenly divisible by both 2 AND 3.
7 => to determine if a number is divisible by 7, take the last digit of the number, double it and subtract the doubled number from the remaining number.
If the result is evenly divisible by 7 (e.g. 14, 7, 0, -7, etc.), then the number is divisible by seven. This may need to be repeated several times.
Example: Is 3101 evenly divisible by 7 ?
 310   - take off the last digit of the number which was 1
  -2   - double the removed digit and subtract it
 308   - repeat the process by taking off the 8
 -16   - and doubling it to get 16 which is subtracted
 14    - the result is 14 which is a multiple of 7  
8 => last three digit or less
9 => sum of digit divisible by 9
10 => last digit equal zero '0'

***Strings***
const int MAX_CHAR = 26;
struct trie {
	trie* child[MAX_CHAR];
	bool isLeaf;

	trie() { 	memset(child, 0, sizeof(child));
		isLeaf = 0; }
	void insert(char *str) {
		if(*str == '\0') isLeaf = 1;
		else {	int cur = *str - 'a';
			if(child[cur] == 0 ) child[cur] = new trie();
			child[cur]->insert(str+1); }
	}

	bool wordExist(char* str) {
		if(*str == '\0')return isLeaf;
		int cur = *str - 'a';
		if(child[cur] == 0 ) return false;	// such path don't exist
		return child[cur]->wordExist(str+1);
	}
	bool prefixExist(char* str) {
		if(*str == '\0') return true;
		int cur = *str - 'a';
		if(child[cur] == 0 ) return false;	// such path don't exist
		return child[cur]->prefixExist(str+1);
	}
}; 
 

	 
 
***Graph***
#define MAXNODES 100000+9
#define PB push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

//Shortest path in wighted graphs (Dijkstra)

vector<pii> Dijkstra(int src, const vector<vii> &edges) ///<Neighbor, edgeCost>
{
    int N = edges.size();

    vi parent(N), cost(N, INF);
    vector<bool> expanded(N, false);
    parent[src] = src;
    cost[src] = 0;
    ///Queue pairs: (cost of a node, the node)
    priority_queue<pii, vii, greater<pii>> q;
    q.push(make_pair(0, src)); ///<totalCost, node>
    while(!q.empty())
    {
        int node = q.top().second;
        q.pop();
        ///If this node has been expanded before.
        if(expanded[node])  continue;
        else    expanded[node] = true;
        for(int i = 0; i < (int)edges[node].size(); i++)
        {
            pii edge = edges[node][i];
            int neighbor = edge.first, EdgeCost = edge.second;
            if(cost[node] + EdgeCost < cost[neighbor])
            {
                parent[neighbor] = node;
                cost[neighbor] = cost[node] + EdgeCost;
                q.push(make_pair(cost[neighbor], neighbor));
            }
        }
    }
    vii result(N);
    for(int i = 0; i < N; i++)  result[i] = make_pair(cost[i], parent[i]); ///<Least cost,parent>
    return result;
}


 
// Minimum spanning tree ( Kruskal )

vector<int> parent, rank_;
/// Nodes number....
void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n=1000; /// Number of nodes...
int cost = 0; ///Total cost of the tree...
vector<Edge> Kruskal(vector<Edge>& edges){  /// Put Edges of graph here..
vector<Edge> result;
parent.resize(n);
rank_.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if(find_set(e.u) != find_set(e.v)){
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
return result;
}
 
// Graph Traverse (DFS)

vector<vi> edges(MAXNODES);
bool visited[MAXNODES];

void dfs(int node)
{
	visited[node] = true;
	for(int neighbor: edges[node])	if(!visited[neighbor])
	{
		dfs(neighbor);
	}
}
// ( DSU )

struct DSU
{
    int parent[MAXNODES];
    int GroupSize[MAXNODES];
    DSU() {
        for(int i = 0; i < MAXNODES; i++) {
            parent[i] = i;
            GroupSize[i] = 1;
        }
    }
    int FindLeader(int i)
    {
        if(parent[i] == i)  return i;

        return parent[i] = FindLeader(parent[i]);
    }
    bool SameGroup(int x, int y) {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if (leader1 == leader2)  return;
        if (GroupSize[leader1] > GroupSize[leader2])
        {
            parent[leader2] =  leader1;
            GroupSize[leader1] += GroupSize[leader2];
        }
        else {
            parent[leader1] =  leader2;
            GroupSize[leader2] += GroupSize[leader1];
        }
    }
    int GetSize(int x)
    { int leader = FindLeader(x);
        return GroupSize[leader]; }
};
 
/// Shortest path in unweighted graph (BFS)

vector<vi> edges(MAXNODES); ///adjacency list
vi distances(MAXNODES, -1);
vi p(MAXNODES);

void BFS(int src)
{
    distances[src] = 0;
    p[src] = src;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();   q.pop();
        int cost = distances[node];

        for(int child: edges[node])     if(distances[child]== -1)
        {
            p[child] = node;
            q.push(child);
            distances[child] = cost+1;
        }
    }
}

///For the graph in the picture, with src = 1.

//distances = 0 , 1 , 2 , 2 , 1
//p         = 1 , 1 , 2 , 2 , 1

vector<int> path(){
v.PB(dest);         ///3 2 1 //dest is the destination node ...
int node = dest;
do{
    if(p[node]==0){
	v.clear();
	return v;
    }
    node = p[node];
    v.PB(node);
    
}while(node != src);

reverse(v.begin(), v.end());
return v;
}
 
struct edge {
	int from, to, w;

	edge(int from, int to, int w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

int Dijkstra2(vector< vector< edge > > adjList, int src, int dest = -1)	// O(E logV)
{
	int n = sz(adjList);
	vi dist(n, OO), prev(n, -1);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push( edge(-1, src, 0) );

	while( !q.empty() ) {
		edge e = q.top();	q.pop();

		if(e.w > dist[e.to])	continue;	// some other state reached better

		prev[ e.to ] = e.from;

		rep(j, adjList[e.to]) {
			edge ne = adjList[e.to][j];
			if( dist[ne.to] > dist[ne.from] + ne.w ) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push( ne );
			}
		}
	}

	return dest == -1 ? -1 : dist[dest];
}
Print all cycle in graph
// C++ program to print all the cycles 
// in an undirected graph 
#include <bits/stdc++.h> 
using namespace std; 
const int N = 100000; 

// variables to be used 
// in both functions 
vector<int> graph[N]; 
vector<int> cycles[N]; 

// Function to mark the vertex with 
// different colors for different cycles 
void dfs_cycle(int u, int p, int color[], 
			int mark[], int par[], int& cyclenumber) 
{ 

	// already (completely) visited vertex. 
	if (color[u] == 2) { 
		return; 
	} 

	// seen vertex, but was not completely visited -> cycle detected. 
	// backtrack based on parents to find the complete cycle. 
	if (color[u] == 1) { 

		cyclenumber++; 
		int cur = p; 
		mark[cur] = cyclenumber; 

		// backtrack the vertex which are 
		// in the current cycle thats found 
		while (cur != u) { 
			cur = par[cur]; 
			mark[cur] = cyclenumber; 
		} 
		return; 
	} 
	par[u] = p; 

	// partially visited. 
	color[u] = 1; 

	// simple dfs on graph 
	for (int v : graph[u]) { 

		// if it has not been visited previously 
		if (v == par[u]) { 
			continue; 
		} 
		dfs_cycle(v, u, color, mark, par, cyclenumber); 
	} 

	// completely visited. 
	color[u] = 2; 
} 

// add the edges to the graph 
void addEdge(int u, int v) 
{ 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
} 

// Function to print the cycles 
void printCycles(int edges, int mark[], int& cyclenumber) 
{ 

	// push the edges that into the 
	// cycle adjacency list 
	for (int i = 1; i <= edges; i++) { 
		if (mark[i] != 0) 
			cycles[mark[i]].push_back(i); 
	} 

	// print all the vertex with same cycle 
	for (int i = 1; i <= cyclenumber; i++) { 
		// Print the i-th cycle 
		cout << "Cycle Number " << i << ": "; 
		for (int x : cycles[i]) 
			cout << x << " "; 
		cout << endl; 
	} 
} 

// Driver Code 
int main() 
{ 

	// add edges 
	addEdge(1, 2); 
	addEdge(2, 3); 
	addEdge(3, 4); 
	addEdge(4, 6); 
	addEdge(4, 7); 
	addEdge(5, 6); 
	addEdge(3, 5); 
	addEdge(7, 8); 
	addEdge(6, 10); 
	addEdge(5, 9); 
	addEdge(10, 11); 
	addEdge(11, 12); 
	addEdge(11, 13); 
	addEdge(12, 13); 

	// arrays required to color the 
	// graph, store the parent of node 
	int color[N]; 
	int par[N]; 

	// mark with unique numbers 
	int mark[N]; 

	// store the numbers of cycle 
	int cyclenumber = 0; 
	int edges = 13; 

	// call DFS to mark the cycles 
	dfs_cycle(1, 0, color, mark, par, cyclenumber); 

	// function to print the cycles 
	printCycles(edges, mark, cyclenumber); 
}
ToPo  :  out-in degree (Ascending)

int main()
{
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> adj[102];
		int node, k;
		vi out_degree(n+1, 0);
		set <int > order;
		vi ans;
		while (m--)
		{
			cin >> node >> k;
 
 
			out_degree[node]=k;
			lp(i, k) {
				int child;
				cin >> child;
				adj[child].push_back(node);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!out_degree[i])order.insert(i);
		}
		while (!order.empty())
		{
			int cur = *order.begin();
			for (int parent : adj[cur]) {
				out_degree[parent]--;
				if (!out_degree[parent])order.insert(parent); 
			}
			ans.push_back(cur);
			order.erase(cur);
 
		}
		lp(i, n - 1)cout << ans[i] << " ";
		cout << ans.back() << endl;
		if (t)cout << endl;
 
	}
	return 0;
}
Number of divisors of 963761198400 = 6720

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
const double PI = 2*acos(0.0);
void run() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
 
// Function to print all sub strings 
void subString(string s, int n)  
{ 
    // Pick starting point in outer loop 
    // and lengths of different strings for 
    // a given starting point 
    for (int i = 0; i < n; i++)  
        for (int len = 1; len <= n - i; len++) 
            cout << s.substr(i, len) << endl; 
}

1.	#include "bits/stdc++.h"  
2.	  
3.	using namespace std;  
4.	  
5.	#define ll          long long int   
6.	#define inf         (ll)1e17  
7.	  
8.	static const int maxn = 100 + 5;  
9.	static const int Max = 1e5 + 5;  
10.	  
11.	ll dp[maxn][Max];  
12.	bool memoize[maxn][Max];  
13.	  
14.	int w[maxn], val[maxn];  
15.	  
16.	int N, W;  
17.	  
18.	ll solve(int pos, int make)  
19.	{  
20.	  if (pos >= N)   
21.	  {  
22.	      if (make == 0) return 0;  
23.	      return inf;  
24.	  }  
25.	  ll &ret = dp[pos][make];  
26.	  bool &mem = memoize[pos][make];  
27.	  if (mem) return ret;  
28.	  mem = 1;  
29.	  ret = inf;  
30.	  if (make - val[pos] >= 0) ret = min(ret, w[pos] + solve(pos+1, make - val[pos]));  
31.	  ret = min(ret, solve(pos+1, make));  
32.	  return ret;  
33.	}  
34.	                                        
35.	int main()  
36.	{  
37.	    scanf("%d %d", &N, &W);  
38.	    for (int i = 0; i < N; i++) scanf("%d %d", &w[i], &val[i]);  
39.	    for (int make = 100000; make >= 0; make--)  
40.	    {  
41.	        ll ans = solve(0, make);  
42.	        if (ans <= W)   
43.	        {  
44.	            printf("%d\n", make);  
45.	            break;  
46.	        }  
47.	    }  
48.	} 

1.	// int dr[] = {1, -1, 0, 0}; // 4 Direction  
2.	// int dc[] = {0, 0, 1, -1};  
3.	// int dr[] = {0, 0, 1, -1, 1, 1, -1, -1}; // 8 Direction  
4.	// int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};  
5.	// int dr[] = {-1, 1, -2, -2, -1, 1, 2, 2}; // knight Moves  
6.	// int dc[] = {-2, -2, -1, 1, 2, 2, 1, -1}; 
const int N = 1e5 + 1;
	int sz[N] , p[N];
	

	void init(){
	    iota(p , p + N , 0); // 0 1 2 3 .. N
	    fill(sz , sz + N , 1);
	}
	

	int f(int u){
	    return p[u] = (p[u] == u ? u : f(p[u]));
	}
	

	void unite(int u , int v){
	    u = f(u);
	    v = f(v);
	

	    if(u == v)return;
	

	    if(sz[v] < sz[u])swap(u , v);
	

	    p[u] = v;
	    sz[v] += sz[u];
	}

**Inversions in nlog(n)**

ll _mergeSort(int arr[], int temp[],int left, int right);
ll merge(int arr[], int temp[], int left,int mid, int right);

ll mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

ll _mergeSort(int arr[], int temp[],
               int left, int right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp,
                                left, mid);
        inv_count += _mergeSort(arr, temp,
                                mid + 1, right);

        inv_count += merge(arr, temp, left,
                           mid + 1, right);
    }
    return inv_count;
}

ll merge(int arr[], int temp[], int left,
          int mid, int right)
{
    int i, j, k;
    ll inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
expo. Matrix
/*
 * new_a = x1*a+x2*b
 * new_b = x3*a+x4*b
 * a = {{x1,x2}, {x3,x4}}
 */
void mul(vector<vl> &a,vector<vl> &b) {
    ll m[2][2]={{0,0},{0,0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                m[i][k] += a[i][j] * b[j][k];
                m[i][k] %= mod;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = m[i][j];
        }
    }
}
vector<vl> ans(2,vl(2));
void exp_power(vector<vl> a,ll n){
    ans = {{1,0},{0,1}};
    while(n>0){
        if(n%2){
            mul(ans,a);
        }
        mul(a,a);
        n/=2;
    }
}


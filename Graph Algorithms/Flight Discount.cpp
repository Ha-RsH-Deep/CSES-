#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define f(i,n) for(lli i=0;i<n;i++)
#define f2(j,i,n) for(lli j=i+1;j<n;j++)
#define s_sort(v) sort(v.begin(),v.end())
#define reverse_sort(v) sort(v.rbegin(),v.rend())
#define p pair<lli,lli>
#define F first
#define S second
const lli INF = INT64_MAX;
vector<vector<pair<int,int>>> neighbors(100005);
vector<vector<pair<int,int>>> reverse_neighbors(100005);
vector<lli> dis;
vector<lli> min_cost(int start,int lui ,vector<vector<pair<int,int>>> adj){
    dis.assign(lui,INT64_MAX);
    vector<bool> visited(lui,false);
    priority_queue <pair<lli,lli>> q;
    dis[start]=0;
    q.push({0,start});
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(visited[v]==true) continue;
        visited[v]= true;
        for(auto edge:adj[v]){
            lli to = edge.first;
            lli len = edge.second;
            if(dis[v]+len<dis[to]){
                dis[to] = dis[v]+len;
                q.push({-dis[to],to});
            }
        }
    }
    return dis;
}
void solve(){
    lli n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        neighbors[a].push_back({b,c});
        reverse_neighbors[b].push_back({a,c});
    }
    vector<lli> start_costs = min_cost(1,n+1,neighbors);
    vector<lli> end_costs = min_cost(n,n+1,reverse_neighbors);

    lli total_min = INT64_MAX;
	for (int i = 1; i <=n; i++) {
		for (auto [v, len] : neighbors[i]) {
			if (start_costs[i] == INT64_MAX || end_costs[v] == INT64_MAX) {
				continue;
			}
			total_min = min(total_min, start_costs[i] + (len / 2) + end_costs[v]);
		}
	}
	cout << total_min << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        auto start_timer = chrono::high_resolution_clock::now();
    #endif
    cout<<fixed<<setprecision(20);
    solve();
    
    
    #ifdef LOCAL
        auto stop_timer = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
        cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    #endif
    return 0;
}
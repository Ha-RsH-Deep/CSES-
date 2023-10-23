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

vector<bool> visited;
vector<vector<int>> adj;
vector<int> dp;
vector<int> next_node;

void dfs(int node){
    visited[node]=true;
    for(int u :adj[node]){
        if(visited[u]!=true) dfs(u);
        if(dp[u]!=-1 && dp[u]+1>dp[node]){
            dp[node] = dp[u]+1;
            next_node[node] = u;
        }
      
    }
}

void solve(){
    long unsigned int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int a,b;
    for(long unsigned int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dp.assign(n+1,-1);
    dp[n]=1;
    next_node.resize(n+1);
    visited.assign(n+1,false);
    dfs(1);

    if(dp[1]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<dp[1]<<endl;
    int node = 1; 
    while(node){
        cout<<node<<" ";
        node = next_node[node];
    }
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
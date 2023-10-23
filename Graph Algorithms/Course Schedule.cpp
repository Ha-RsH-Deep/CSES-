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
vector<int> ans;
vector<vector<int>> adj;

void dfs(int v){
    visited[v]=true;
    for(int u :adj[v]){
        if(visited[u]!=true){
            dfs(u);
        }
    }
    ans.push_back(v);
}

int v1[100005];
bool cycle(int s){
    v1[s]=1;
    for (auto i: adj[s]){
        if (!v1[i]){
            if (cycle(i)) return 1;
        }
        else if (v1[i]==1) return 1;
    }
    v1[s] = 2;
    return 0;
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
    visited.assign(n+1,false);
    ans.clear();
    for(long unsigned int i=1;i<n+1;i++){
        if(visited[i]!=true && cycle(i)){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        if(visited[i]!=true) dfs(i);
    }
    reverse(ans.begin(),ans.end());
    for(long unsigned int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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
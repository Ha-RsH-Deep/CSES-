#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
vector<bool> visited;

void dfs(int v){
    visited[v]=true;
    for(int u:adj[v]){
        if(!visited[u]) dfs(u);
    }
}
void solve(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int connected =0;
    vector<pair<int,int>> p;
    visited.assign(n+1,false);
    for(int i=1;i<=n;i++){
        a=1;
        if(!visited[i]){
            if(i!=1) b= i;
            connected++;
            p.push_back({a,b});
            dfs(i);
            a=i;
        }
    }
    cout<<connected-1<<endl;
    for(int i=1;i<connected;i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;

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
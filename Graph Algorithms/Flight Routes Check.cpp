#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100005][2];
vector<bool> visited;

void dfs(int v,int x){
    visited[v] = true;
    for(int u: adj[v][x]){
        if(visited[u]!= true) dfs(u,x);
    }
}

void solve(){
    int n,m,a,b;
    cin>>n>>m;
   
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    visited.assign(n+1,false);
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl; 
            return;
        }
    }

    visited.assign(n+1,false);
    dfs(1,1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl; 
            return;
        }
    }
    cout<<"YES"<<endl;
    return;


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
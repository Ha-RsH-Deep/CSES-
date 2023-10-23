#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
vector<bool> visited;
int d=0,node=0;
void dfs(int v,int p, int dis){
    for(int u: edge[v]){
        if(u!=p){
            dfs(u,v,dis+1); 
        } 
    }
    if(dis>d) d = dis, node = v;
}
void solve(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        edge[a].push_back(b);    edge[b].push_back(a);
    }
    dfs(1,0,0);
    dfs(node,0,0);
    cout<<d<<endl;
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
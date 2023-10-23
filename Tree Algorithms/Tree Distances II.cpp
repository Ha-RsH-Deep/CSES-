#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> edge[200001];
int n;
ll dp[200001], ans[200001];
void dfs1(int v = 1, int p = 0, ll dist = 0){
    ans[1] += dist;
    dp[v] = 1;
    for(int u: edge[v]){
        if(u!=p){
            dfs1(u,v,dist+1);
            dp[v] += dp[u];
        }
    }
}
void dfs2(int v = 1, int p = 0){
    for(int u:edge[v]){
        if(u!=p){
            ans[u] = ans[v] + n - 2 * dp[u];
            dfs2(u,v);
        }
    }
}
void solve(){
    int a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        edge[a].push_back(b);   edge[b].push_back(a);
    }
    dfs1();
    dfs2();
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";    
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
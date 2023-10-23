#include<bits/stdc++.h>

using namespace std;
vector<int> edge[200005];
vector<int> dp;


void dfs(int v){
    for(auto u:edge[v]){
        dfs(u);
        dp[v] = dp[v]+dp[u]+1;
    }

}
void solve(){
    int n,a;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a;
        edge[a].push_back(i+2);
    }
    dp.assign(n+1,0);
    //dp[1]=1;
    dfs(1);

    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
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
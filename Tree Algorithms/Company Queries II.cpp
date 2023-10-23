#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
vector<bool> visited;
vector<int> ans;
int n,q,a,b;

void solve(){
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>a;
        edge[a].push_back(i);
        
        
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
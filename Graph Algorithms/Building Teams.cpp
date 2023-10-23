#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> visited;

queue<pair<int,int>> q;
bool ok=1;

void bfs(int v){
    while(!q.empty()){
        pair<int,int> curr = q.front(); q.pop();
            visited[curr.first] = curr.second;
            for(int u:adj[curr.first]){
                if(visited[u]==-1){
                    q.push({u,1-curr.second});
                }
                if(visited[u]==curr.second){
                    //cout<<node<<"  "<<u<<"    "<<flag<<endl;
                    ok = 0;
                    return;
                }
            }       
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
    visited.assign(n+1,-1);
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            q.push({i,0});
            bfs(i);
        }
    }
    if (ok) {
		for (int i = 1; i <= n; i++) { cout << visited[i] + 1 << ' '; }
		cout << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
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
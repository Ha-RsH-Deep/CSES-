#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
int n;

int dist[2][200005];

vector<int> ans;
int dfs(int v,int p, int dis, int i){
    dist[i][v]= dis;
    int opt =-1;
    for(int u:edge[v]){
        if(u!=p){
            int x = dfs(u,v,dis+1,i);
            if(opt==-1 || dist[i][x]>dist[i][opt]) opt = x;
        }
    }

    return opt==-1? v:opt;
}




void solve(){
    int a,b;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<=n-1;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ans.assign(n+1,-1);
    int maxnode1 = dfs(1,1,0,0);
    int maxnode2= dfs(maxnode1,maxnode1,0,0);
    dfs(maxnode2,maxnode2,0,1);
    for (int i = 1; i <=n; i++)
    {
        cout<<max(dist[0][i],dist[1][i])<<" ";
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
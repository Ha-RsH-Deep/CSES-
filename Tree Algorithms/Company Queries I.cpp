#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
vector<int> node_id;
vector<int> depth;
int n,q,a,b;

void dfs(int v,int dep,int p){
    node_id.push_back(v);
    depth.push_back(dep);
    for(auto u: edge[v]){
        if(u!=p){
            dfs(u,dep+1,v);
        }
        if(edge[v].size()==1) return;
    }
    node_id.push_back(v);
    depth.push_back(dep);

}
int get_index(int a){
    for(int i=0;i<node_id.size();i++){
        if(node_id[i]==a){
            return i;
        }
    }
}

void solve(){
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>a;
        edge[a].push_back(i);
        edge[i].push_back(a);  
    }
    dfs(1,1,-1);

    // for(int i=0;i<node_id.size();i++){
    //     cout<<node_id[i]<<" death" <<depth[i]<<endl;
    // }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        int j= get_index(a);
        int curr_depth = depth[j];
        int reach = curr_depth-b;
        if(reach<=0){
            cout<<-1<<endl;
            continue;
        }
        for(int k=j;k>=0;k--){
            if(depth[k]==reach){
                cout<<node_id[k]<<endl;
                break;
            }

        }
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
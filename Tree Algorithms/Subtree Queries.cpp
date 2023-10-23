#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
vector<int> ans;
vector<int> val;
vector<int> subtree;
vector<int> pathsum;
int d=0,node=0;
int n,q,a,b,c;
int dfs(int v,int p){
    int count=1;
    int sum = val[v]; 
    for(int u: edge[v]){
        if(u!=p){
            count += dfs(u,v); 
            sum += val[u];
        } 
    }
    pathsum[v] = sum;
    subtree[v]=count;
    ans.push_back(v);
    return count;
}
void solve(){
    cin>>n>>q;
    val.assign(n+1,0);
    subtree.assign(n+1,1);
    pathsum.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,0);
    reverse(ans.begin(),ans.end());
    for (int i = 1; i <= n; i++)
    {
        cout<<subtree[i]<<"  ";
    }
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<pathsum[i]<<"  ";
    }
    cout<<endl;
    for (int i =0; i <n; i++)
    {
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<q;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            val[b]=c;
        }
        if(a==2){
            cin>>b;
            int sum=0;
            for(int i=0;i<n;i++){
                if(ans[i]==b){
                    node = i;
                    break;
                }
            }
            for(int i=0;i<subtree[b];i++){
                sum+=val[ans[node+i]];
            }
            cout<<sum<<endl;
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
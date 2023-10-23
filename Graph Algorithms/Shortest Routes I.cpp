#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define f(i,n) for(lli i=0;i<n;i++)
#define f2(j,i,n) for(lli j=i+1;j<n;j++)
#define s_sort(v) sort(v.begin(),v.end())
#define reverse_sort(v) sort(v.rbegin(),v.rend())
#define p pair<lli,lli>
#define F first
#define S second

const lli INF = LONG_LONG_MAX;

vector<vector<pair<int,int>>> adj(100005);
vector<lli> dis;



void solve(){
    lli n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dis.assign(n+1,INF);
    set<pair<lli,lli>> q;
    dis[1]=0;
    q.insert({0,1});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge:adj[v]){
                lli to = edge.first;
                lli len = edge.second;
                if(dis[v]+len<dis[to]){
                    q.erase({dis[to],to});
                    dis[to] = dis[v]+len;
                    q.insert({dis[to],to});
                }
        }
    }
            
    
    for(lli i=1;i<=n;i++) {
        cout<<dis[i]<<" ";
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
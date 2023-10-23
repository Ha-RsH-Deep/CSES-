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


vector<int> edge[100001];
vector<int> back_edge[100001];
vector<int> dp;
vector<int> in_degree;


void solve(){
     int n,m;
    cin>>n>>m;
    in_degree.assign(n+1,0);
    dp.assign(n+1,0);
    dp[1]=1;

    int a,b;
    for( int i=0;i<m;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        back_edge[b].push_back(a);
        in_degree[b]++;
    }
    queue<int> q;
    for( int i=1;i<n+1;i++){
        if(in_degree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for( int next: edge[node]){
            in_degree[next]--;
            if(in_degree[next]==0) q.push(next);
        }
        for( int prev: back_edge[node]){
            dp[node]= (dp[node]+dp[prev])% 1000000007;
        }
    }
    cout<<dp[n]<<endl;
    
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
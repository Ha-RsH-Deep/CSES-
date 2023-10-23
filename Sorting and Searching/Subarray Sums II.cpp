#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
#define f(i,n) for(lli i=0;i<n;i++)
#define f2(j,i,n) for(lli j=i+1;j<n;j++)
#define s_sort(v) sort(v.begin(),v.end())
#define reverse_sort(v) sort(v.rbegin(),v.rend())
#define p pair<lli,lli>
#define F first
#define S second
void solve(){
    int n, X;
    cin>>n>>X;
    vector<int> v(n);
    ll ans =0;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll prefix_sum =0;
    map<ll,int> sum;
    sum[0]=1;
    for(int x:v){
        prefix_sum +=x;
        ans +=sum[prefix_sum-X];
        sum[prefix_sum]++;
    }
    cout<<ans<<endl;   
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
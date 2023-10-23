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


void solve(){
    lli n;
    cin>>n;
    vector<lli> v(n);
    lli prefix_sum =0,suffix_sum =0;
    f(i,n) {
        cin>>v[i];
        suffix_sum += v[i];
    }
    s_sort(v);
    lli  min_cost = INT_FAST16_MAX;
    for(int i=0;i<n;i++){
        lli cost = 0 ;
        suffix_sum -= v[i];
        prefix_sum += v[i];
        cost += abs(prefix_sum - (i+1)*v[i]);
        cost += abs(suffix_sum - (n-i-1)*v[i]);
        min_cost = min(min_cost,cost);
    }
    cout<<min_cost<<endl;
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
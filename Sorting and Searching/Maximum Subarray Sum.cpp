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
    f(i,n){
        cin>>v[i];
    }

    lli max_sum = INT_MIN, temp_sum =0;
    f(i,n){
        temp_sum = max(temp_sum+v[i],v[i]);
        max_sum = max(max_sum,temp_sum);
    }
    cout<<max_sum<<endl;

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
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

lli maxi = 2*10e5;
vector<lli> sum(maxi);

void solve(){
    lli n;
    cin>>n;
    vector<lli> v(n+1);
    f(i,n+1) {
        cin>>v[i+1];
    }
    s_sort(v);
    sum[0]=1;
    lli ans = 0;
    for(int i=1;i<n+1;i++){
        if(sum[i-1]<v[i]){
            ans = sum[i-1];
            cout<<ans<<endl;
            break;
        }
        sum[i] = sum[i-1]+v[i];
    }
    if(ans==0) cout<<sum[n]<<endl;

    



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
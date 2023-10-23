#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
     int n ;
     cin>>n;
     ll ans=0;
     map<ll,ll> prefix; 
     ll x;
     ll s=0;
     prefix[0]=1;
     for(int i=0;i<n;i++) {
        cin>>x;
        s +=x;
        prefix[((s%n)+n)%n]++;
     }
     for(auto x:prefix){
        ans += (x.second)*(x.second-1)/2;
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
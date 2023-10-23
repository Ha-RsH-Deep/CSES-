#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int del[] ={0,1,0,-1,0};

queue<pair<int,int>> q;

void solve(){
    int n,m;

    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    visited.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        } 
    }
    int count =0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && visited[i][j]==false){
                count++;
                q.push({i,j});
                visited[i][j]=true;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nr = r+ del[i];
                        int nc = c+ del[i+1];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.' && visited[nr][nc]== false){
                            visited[nr][nc]=true;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    cout<<count<<endl;
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
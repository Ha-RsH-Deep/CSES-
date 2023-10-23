#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    int start_i,start_j;
    int delRow[4] ={-1,0,1,0};
    int delCol[4]={0,1,0,-1};
    char a;
    cin>>n,m;
    string<char> s;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            grid[i][j]=a;
            if(a=='#') visited[i][j] =-1;
            if(a=='A') start_i=i; start_j=j;
        }
    }
    queue<pair<int,int>> q;
    int end_i,end_j;
    q.push({start_i,start_j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        int state = visited[r][c];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r+delRow[i];
            int nc = c +delCol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='B' && visited[nr][nc]!=-1){
                q.push({nr,nc});
                visited[nr][nc] = state+1;
                int distance = state+1;
            }
            if(grid[nr][nc]='B'){
                end_i=nr;
                end_j =nc;
            }
        }
    }
    
    while(start_i!= end_i && start_j!=end_j){
        if(start_i-1>=0){

        }
        
    }






}
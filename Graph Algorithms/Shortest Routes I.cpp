//dijkstra model
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e9
#define maxn 100005

vector<pair<int,int>>graph[maxn];
int dis[maxn];
bool gone[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int n,m;
int a,b,c;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    //initialize
    memset(dis, 0x3F, sizeof(dis));
    dis[1]=0;

    //建圖 
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    
    //dijkstra
    pq.push({0,1});
    while(!pq.empty()){
        auto now=pq.top();
        pq.pop();
        int v=now.second;
        if(gone[v]){
            continue;                   
        }
        gone[v]=true;                   
        for(auto next:graph[v]){         
            int u=next.first;            
            int k=next.second;           
            if(dis[u]>dis[v]+k){
                dis[u]=dis[v]+k;
                pq.push({dis[u],u});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}

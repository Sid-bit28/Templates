#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
void dfs(int vertex,int component){
    vis[vertex]=component;
    for(auto child:g[vertex]){
        if(!vis[child]){
            dfs(child,component);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt_components=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt_components++;
            dfs(i,cnt_components);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<vis[i]<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dis;
void bfs(int node){
	queue<int> q;
	q.push(node);
	dis[node]=0;
	while(!q.empty()){
		int frnt=q.front();
		q.pop();
		for(auto child:g[frnt]){
			if(dis[child]>dis[frnt]+1){
				dis[child]=dis[frnt]+1;
				q.push(child);
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	g.clear();
	g.resize(n+1);
	dis.assign(n+1,1e9);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}   
	bfs(1);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<endl;
	}
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
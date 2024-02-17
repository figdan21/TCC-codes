#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 1000000
#define MID 50
#define source 99
#define sink 98
vector<int> adj[MAX];
pair<int, int> flow[MAX][MAX];
vector<int> path;
int visited[MAX];

bool dfs(int node){
	visited[node] = true;
	if (node == sink){
		return true;
	}
	for (int v:adj[node]){
		if (!visited[v] and flow[node][v].second > flow[node][v].first and dfs(v)){
			path.push_back(v);
			return true;
		}
	}
	return false;
}

int max_flow(){
	int Flow = 0;
	while (true){
		path.clear();
		memset(visited,0,sizeof(visited));
		dfs(source);
		if (path.empty()) break;
		path.push_back(source);
		int lower = INF;
		for (int i=1; i<(int)path.size(); i++){
			lower = min(lower, flow[path[i]][path[i-1]].second-flow[path[i]][path[i-1]].first);
		}
		for (int i=1; i<(int)path.size(); i++){
			flow[path[i]][path[i-1]].first+=lower;
			flow[path[i-1]][path[i]].first-=lower;
		}
		Flow+=lower;
	}
	return Flow;
}

void addEdge(int from, int to, int cap){
	adj[from].push_back(to);
	adj[to].push_back(from);
	flow[from][to]={0,cap};
	flow[to][from]={0,0};
}

int main(){
	
	addEdge(13,2,2);
	addEdge(13,3,2);
	addEdge(14,4,2);
	addEdge(14,7,2);
	addEdge(15,1,2);
	addEdge(15,6,2);
	
	addEdge(16,3,2);
	addEdge(16,6,2);
	addEdge(17,1,2);
	addEdge(17,4,2);
	addEdge(18,5,2);
	addEdge(18,2,2);
	
	addEdge(19,3,2);
	addEdge(19,5,2);
	addEdge(20,2,2);
	addEdge(20,7,2);
	addEdge(21,4,2);
	addEdge(21,6,2);
	
	
	addEdge(source,13,2);
	addEdge(source,14,2);
	addEdge(source,15,2);
	addEdge(source,16,2);
	addEdge(source,17,2);
	addEdge(source,18,2);
	addEdge(source,19,2);
	addEdge(source,20,2);
	addEdge(source,21,2);
	
	addEdge(1,sink,0);
	addEdge(2,sink,1);
	addEdge(3,sink,2);
	addEdge(4,sink,3);
	addEdge(5,sink,3);
	addEdge(6,sink,4);
	addEdge(7,sink,5);
	
	cout<<max_flow()<<endl;
	for (int i=0; i<MAX; i++){
		for (int j=0; j<MAX; j++){
			if (flow[i][j].first<flow[i][j].second and flow[i][j].second>0) cout<<i<<" "<<j<<" "<<flow[i][j].second-flow[i][j].first<<endl; 
		}
	}
}

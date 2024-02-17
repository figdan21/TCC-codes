#include <bits/stdc++.h>
using namespace std;
#define MAX 100
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
}

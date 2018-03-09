#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int v[1001][1001];
int visited[1001];
int n, m, startv, x, y;

void dfs(int node) 
{
	visited[node] = 1;
	cout << node << " ";
	
	for (int i = 1; i <= n; i++) {
		if (v[node][i] && !visited[i]) {
			dfs(i);
		}
	}
}

void bfs(int node) 
{
	queue<int> q;
	int a;
	q.push(node);
	visited[node] = 1;
	
	while (!q.empty()) {
		a = q.front();
		q.pop();
		cout << a << " ";
		for (int i=1; i<=n; i++) 
		{
			if (v[a][i] && !visited[i]) 
			{ 
				q.push(i);
				visited[i] = 1; 
			}
		}
	}
}

int main()
{
	cin >> n >> m >> startv;

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		v[x][y] = 1;
		v[y][x] = 1;
	}

	dfs(startv);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	bfs(startv);
}
/*
	2667: 단지번호붙이기
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int g[26][26];
int visited[26][26];
int d[400]; // 단지별 1의 갯수를 가진 벡터
int dangiN, N; // 단지의 수, N은 입력값

bool safe(int a, int b) {
	if (a > 0 && a <= N && b > 0 && b <= N) {
		return true;
	}
}

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	int cnt = 0;
	
	q.push({ a, b });
	visited[a][b] = 1; //처음 입력받은 좌표는 방문으로 표시
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++; //수를 세어준다.
		
		// 사방향 이동
		for (int i = 0; i < 4; i++) { 
			int x1 = x + dx[i], y1 = y + dy[i];
			//주어진 그래프에서 벗어나지 않고 && 그래프에 1로 표시되어있고 && 방문하지 않았다면
			if (safe(x1, y1) && g[x1][y1] == 1 && visited[x1][y1] == 0) { 
				q.push({ x1, y1 }); // 큐에 넣고
				visited[x1][y1] = 1; //방문 표시해준다.
			}
		}
	}

	return cnt; // 단지별 1 갯수를 넣는 변수를 벡터에 넣어준다.
}


int main() {
	cin >> N;
	int tmp;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &tmp);
			g[i][j] = tmp;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (g[i][j] != 0 && visited[i][j] ==0) {
				d[idx]=bfs(i, j);
				dangiN++;
				idx++;
			}
		}
	}

	if (dangiN != 0) { //단지의 수가 0이 아니라면
		sort(d, d+dangiN);
		printf("%d\n", dangiN);
		for (int i = 0; i < dangiN; i++) {
			cout << d[i] << "\n";
		}
	}
	else { //단지의 수가 0이라면 단지 수만 출력한다.
		printf("%d\n", dangiN);
	}
}
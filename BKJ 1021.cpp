﻿/*
	1021: 회전하는 큐
*/
#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main()
{
	int N, M, target;
	int mvCnt = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		dq.push_back(i + 1);
	}
	
	for (int i = 0; i<M; i++)
	{
		cin >> target;
		int dist = 0; 
		int size = dq.size();

		for (auto iter: dq)
		{
			if (iter == target) break;
			dist++;
		}

		int right = dist;
		int left = size - dist;

		if (left >= right) { // 오른쪽으로 가는 거나, 왼쪽이동이나 오른쪽이동이나 같다면! 
			for (int j = 0; j<right; j++) {
				int tmp = dq.front(); dq.pop_front();
				dq.push_back(tmp);
				mvCnt++;
			}
		}
		else { // 왼쪽으로 가거나
			for (int j = 0; j<left; j++) {
				int tmp = dq.back(); dq.pop_back();
				dq.push_front(tmp);
				mvCnt++;
			}
		}
		dq.pop_front();
	}

	cout << mvCnt << "\n";
}
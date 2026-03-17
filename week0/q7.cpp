#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;

	int* kids = new int[N + 1];
	for (int i = 0;i < N;i++) {
		std::cin >> kids[i + 1];
	}

	std::vector<std::vector<int>> map(N + 1);
	int kid1, kid2;
	for (int i = 0; i < M; i++) {
		std::cin >> kid1 >> kid2;
		map[kid1].push_back(kid2);
		map[kid2].push_back(kid1);
	}

	std::vector<int> group;

	std::vector<int> q;
	bool* visited = new bool[N + 1]();
	std::vector<std::pair<int, int>> newKids;
	int current, num, sum;
	int index = 0;

	for (int i = 1; i < N + 1; i++) {
		if (visited[i]) 
			continue;
		
		q.clear();
		q.push_back(i);
		visited[i] = true;
		num = 0;
		sum = 0;

		while (!q.empty()) {
			current = q.back();
			q.pop_back();
			sum += kids[current];
			num++;
			for (int j = 0;j < map[current].size();j++) {
				if (!visited[map[current][j]]) {
					visited[map[current][j]] = true;
					q.push_back(map[current][j]);
				}
			}
		}
		newKids.push_back({ num, sum });

	}

	int* table = new int[K](); //table[아이 수] = 사탕 수

	int nums, candy;
	for (int i = 0; i < newKids.size();i++) {
		nums = newKids[i].first;
		candy = newKids[i].second;
		if (candy == 0) {
			continue;
		}
		for (int j = K - 1; j >= nums;j--) {
			if (table[j] < table[j - nums] + candy) {
				table[j] = table[j - nums] + candy;
			}
		}
	}

	int maxCandy = 0;
	for (int i = 0; i < K;i++) {
		if (maxCandy < table[i])
			maxCandy = table[i];
	}
	std::cout << maxCandy;

	return 0;
}
#include <iostream>
#include <vector>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;

	std::vector<std::vector<int>> road(N + 2);

	int h1, h2;
	for (int i = 0;i < M;i++) {
		std::cin >> h1 >> h2;
		road[h1].push_back(h2);
		road[h2].push_back(h1);
	}

	bool* noCheck = new bool[N + 2]();
	int k;
	for (int i = 0;i < K;i++) {
		std::cin >> k;
		noCheck[k] = 1;
	}

	int current = 1;
	bool* visited = new bool[N + 2]();

	int* q = new int[2*M];
	int top = 0, bottom = 0;

	for (int i = 0;i < road[1].size();i++) {
		if (!noCheck[road[1][i]])
			q[top++] = road[1][i];
	}
	visited[1] = true;

	while (top > bottom) {
		current = q[bottom++];
		visited[current] = true;
		for (int i = 0;i < road[current].size();i++) {
			if (!visited[road[current][i]] && !noCheck[road[current][i]]) {
				q[top++] = road[current][i];
			}
		}
	}

	int answer = 0;
	for (int i = 2; i < N + 2;i++) {
		if (visited[i])
			answer++;
	}

	std::cout << answer;

	return 0;
}
#include <iostream>

int main() {
	int N, M;
	std::cin >> N >> M;

	int* L = new int[M];
	int* count = new int[M]();

	int** student = new int* [N];
	for (int i = 0; i < N; i++) {
		student[i] = new int[M]();
	}

	for (int i = 0; i < M;i++) {
		std::cin >> L[i];
	}


	for (int i = 0; i < N; i++) {
		while (true) {
			int subject;
			std::cin >> subject;
			if (subject == -1) {
				break;
			}
			subject--;
			student[i][subject] = 1;
			count[subject]++;
		}
	}

	for (int i = 0; i < M;i++) {
		if (count[i] <= L[i]) {
			for (int j = 0; j < N; j++) {
				if (student[j][i] == 1)
					student[j][i] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		while (true) {
			int subject;
			std::cin >> subject;
			if (subject == -1) {
				break;
			}
			subject--;

			if (student[i][subject] != -1) {
				student[i][subject] = 1;
				count[subject]++;
			}
		}
	}

	for (int i = 0; i < M;i++) {
		if (count[i] <= L[i]) {
			for (int j = 0; j < N; j++) {
				if (student[j][i] == 1)
					student[j][i] = -1;
			}
		}
	}

	for (int i = 0; i < N;i++) {
		int flag = 0;
		for (int j = 0;j < M;j++) {
			if (student[i][j] == -1) {
				std::cout << j + 1 << " ";
				flag = 1;
			}
		}
		if (!flag) {
			std::cout << "망했어요";
		}
		std::cout << "\n";
	}


	return 0;
}
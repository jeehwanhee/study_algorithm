#include <iostream>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	int** dots = new int* [N];
	int x, y;
	for (int i = 0;i < N;i++) {
		std::cin >> x >> y;
		dots[i] = new int[3];
		dots[i][0] = x;
		dots[i][1] = y;
		dots[i][2] = i+1;
	}

	std::sort(dots, dots + N, [](int* dot1, int* dot2) {
		if (dot1[0] == dot2[0]) {
			return dot1[1] < dot2[1];
		}
		return dot1[0] < dot2[0];
	});

	int pre = dots[0][2];

	for (int i = 1;i < N;i++) {
		std::cout << pre << " " << dots[i][2] << "\n";
		pre = dots[i][2];
	}


	return 0;
}
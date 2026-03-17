#include <iostream>

int main() {
	int N;
	std::cin >> N;

	int current, answer = 0, pre3, pre2, pre, flag = 0;

	if (N == 2) {
		std::cin >> pre >> current;
		std::cout << 2;
		return 0;
	}
	else if (N == 3) {
		std::cin >> pre2 >> pre >> current;
		if (pre2 <= current)
			answer++;
		if (pre2 <= pre)
			answer++;
		if (pre <= current)
			answer++;
		std::cout << answer;
		return 0;
	}

	std::cin >> pre2 >> pre >> current;
	if (pre2 > pre) {
		flag++;
		if (pre <= current) {
			answer++;
		}
		if (pre2 <= current) {
			answer++;
		}
	}

	for (int i = 3; i < N; i++) {
		pre3 = pre2;
		pre2 = pre;
		pre = current;
		std::cin >> current;

		if (pre2 > pre) {
			answer = 0;
			flag++;
			if (pre2 <= current) {
				answer++;
			}
			if (pre3 <= pre) {
				answer++;
			}
		}
	}

	if (pre > current) {
		flag++;
		if (pre2 > current) {
			answer = 1;
		}
		else {
			answer = 2;
		}
	}

	if (flag == 0) {
		std::cout << N;
	}
	else if (flag == 1) {
		std::cout << answer;
	}
	else {
		std::cout << 0;
	}


	return 0;
}







/*
#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int* arr = new int[N];

	int maxN, maxN2, current, count = 0, pre2, pre;
	bool firstOrLast = false;

	std::cin >> pre >> current;
	if (pre <= current) {
		maxN = current;
		maxN2 = pre;
	}
	else {
		maxN = pre;
		maxN2 = current;
		count++;
	}

	for (int i = 2; i < N; i++) {
		pre2 = pre;
		pre = current;
		std::cin >> current;


		if (maxN2 > current) {
			count += 2;
		}
		else if (maxN > current) {
			count++;
			maxN2 = current;
		}
		else {
			maxN2 = maxN;
			maxN = current;
		}

		bool first = (i == 2 and pre2 > current);
		bool last = (i == N-1 and pre2 > current);

		if (first or last) {
			firstOrLast = !firstOrLast;
		}
	}

	int answer;
	if (count == 0) {
		answer = N;
	}
	else if (count == 1) {
		answer = 2;
	}
	else {
		if (firstOrLast)
			answer = 1;
		else
			answer = 0;
	}

	std::cout << answer;


	return 0;
}
*/
#include <iostream>
#include <algorithm>

int main() {
	int n, k;
	std::cin >> n >> k;

	int* coins = new int[n]();

	int input, index = n - 1;
	bool flag = false;

	for (int i = 0;i < n;i++) {
		flag = false;
		std::cin >> input;
		for (int j = n - 1;j > index;j--) {
			if (coins[j] == input)
				flag = true;
		}
		if (!flag)
			coins[index--] = input;
	}

	coins = coins + index + 1;
	int len = n - 1 - index;


	sort(coins, coins + len, std::greater<int>());

	int* table = new int[k + 1]; //table[금액] = 개수
	for (int i = 0;i < k + 1;i++) {
		table[i] = k + 1;
	}

	table[0] = 0;

	int coin, count;
	for (int i = 0; i < len;i++) {
		coin = coins[i];
		for (int j = 0; j < k + 1;j++) {
			if (table[j] != k + 1 && j + coin <= k) {
				if (table[j + coin] > table[j] + 1)
					table[j + coin] = table[j] + 1;
			}
			if (j % coin == 0) {
				if (table[j] > (j / coin)) {
					table[j] = j / coin;
				}
			}
		}
	}

	if (table[k] != k + 1) {
		std::cout << table[k];
		return 0;
	}
	std::cout << -1;

	return 0;
}
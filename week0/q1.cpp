#include <iostream>
#include <algorithm>

int main() {
    int cows[11];
    std::fill(cows, cows + 11, -1);

    int N, n = 0;
    std::cin >> N;

    int cow, position;

    for (int i = 0; i < N; i++) {
        std::cin >> cow >> position;
        if (cows[cow] == -1) {
            cows[cow] = position;
            continue;
        }

        if (cows[cow] != position) {
            cows[cow] = position;
            n++;
        }
    }

    std::cout << n;
    return 0;
}
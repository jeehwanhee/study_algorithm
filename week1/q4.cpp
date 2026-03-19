#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, N, C;
    cin >> T;
    int* answer = new int[T];
    for (int testCase=0;testCase<T;testCase++) {
        cin >> N >> C;
        int* house = new int[N];
        for (int i=0; i<N; i++) {
            cin >> house[i];
        }

        sort(house, house+N);

        int start = 0, end = (house[N-1] - house[0]) / (C - 1), mid;
        int flag, count;
        while (start <= end) {
            mid = (start + end) / 2;
            flag = 0;
            count = 1;
            for (int i=1; i<N; i++) {
                if (house[i]-house[flag] >= mid) {
                    count++;
                    flag = i;
                }
            }
            if (count >= C) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        answer[testCase] = end;
    }

    for (int i=0; i<T; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
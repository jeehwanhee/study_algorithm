#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    int* arr = new int[N];

    for (int i=0; i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    cin >> M;
    bool* answer = new bool[M]();
    int start, end, mid, target;
    for(int i=0;i<M;i++){
        cin >> target;

        start = 0;
        end = N-1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (arr[mid] == target) {
                answer[i] = true;
                break;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
    }

    for (int i=0; i<M; i++) {
        cout << (int)answer[i] << "\n";
    }


    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[N];

    for (int i=0; i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int start, end, mid, target;
    long long sum;
    start = 0;
    end = arr[N-1];
    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;
        for (int i=0; i<N; i++) {
            if (arr[i]>mid) {
                sum += arr[i] - mid;
            }
        }

        if (sum >= M)
            start = mid + 1;
        else 
            end = mid -1;
    }
        

    cout << end;


    return 0;
}
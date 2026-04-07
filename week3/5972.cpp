#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int N, M;
    int A, B, C;
    cin >> N >> M;

    vector<vector<pair<int, int>>> map(N);
    int* answer = new int[N];
    bool* visited = new bool[N]();
    int flag = 0;

    for (int i=0;i<N;i++) {
        answer[i] = 50000001;
    }

    for (int i=0; i<M; i++) {
        cin >> A >> B >> C;
        map[A-1].push_back({B-1,C});
        map[B-1].push_back({A-1,C});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;



    answer[0] = 0;
    pq.push({0, 0});
    int node;
    int dis;
    while (!pq.empty())
    {
        node = pq.top().first;
        dis = pq.top().second;
        pq.pop();

        if (answer[node] < dis) {
            continue;
        }

        for (int i=0;i<map[node].size();i++) {
            if (answer[map[node][i].first] > dis + map[node][i].second) {
                answer[map[node][i].first] = dis + map[node][i].second;
                pq.push({map[node][i].first, dis + map[node][i].second});
            }
        }
    }
    
    cout << answer[N-1];

    return 0;
}
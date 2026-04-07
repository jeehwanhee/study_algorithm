#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int* func(vector<vector<pair<int, int>>> graph, int node) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int n = graph.size();
    int* answer = new int[n+1];
    for (int i=0;i<n+1;i++) {
        answer[i] = 1000000001;
    }

    pq.push({0,node});
    answer[node] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second;
        int edge = pq.top().first;
        pq.pop();
        if (answer[x] < edge) continue;
        for (int i=0; i<graph[x].size(); i++) {
                int nextX = graph[x][i].first;
                if (answer[nextX] > answer[x] + graph[x][i].second) {
                        pq.push({answer[x] + graph[x][i].second, nextX});
                        answer[nextX] = answer[x] + graph[x][i].second;
                }
            }
    }

    return answer;
}



int main() {
    int n,m,x;
    cin >> n >> m >> x;

    vector<vector<pair<int,int>>> graph(n+1);
    vector<vector<pair<int,int>>> graphBack(n+1);

    for (int i=0;i<m;i++) {
        int n1, n2, t;
        cin >> n1 >> n2 >> t;
        graph[n1].push_back({n2, t});
        graphBack[n2].push_back({n1, t});
    }

    int* go;
    int* back;
    go = func(graphBack, x);
    back = func(graph, x);

    int maxNum = 0;
    for (int i=2;i<n+1;i++) {
        if (i == x) continue;
        if (go[i] >= 1000000001 || back[i] >= 1000000001) continue;
        if (maxNum < go[i]+back[i]) maxNum=go[i]+back[i];
    }

    cout << maxNum;
    return 0;
}
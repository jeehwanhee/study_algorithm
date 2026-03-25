#include "../header.h"
#include <iostream>
#include <vector>

using namespace std;

int n1, n2;
vector<vector<int>> tree;

vector<int> DFS(bool* visited, int point) {
    int nextPoint;
    vector<int> p;
    if (point == n2) {
        p.push_back(point);
        return p;
    }

    for (int i=0; i<tree[point].size();i++) {
        nextPoint = tree[point][i];
        if (visited[nextPoint] == false) {
            visited[nextPoint] = true;
            p = DFS(visited, nextPoint);
            if (!p.empty()) {
                p.push_back(point);
                return p;
            }
        }
    }
    return p;
}

int main() {
    int T, N;
    int v1, v2;
    cin >> T;
    int* answer = new int[T]();
    for (int i=0; i<T; i++) {
        cin >> N;
        tree.resize(N+1);
        int* parentNode = new int[N+1];
        
        for (int j=0; j<N-1; j++) {
            cin >> v1 >> v2;
            tree[v1].push_back(v2);
            tree[v2].push_back(v1);
            parentNode[v2] = v1;
        }

        cin >> n1 >> n2;
        bool* visited = new bool[N+1]();
        visited[n1] = true;
        vector<int> path;
        path = DFS(visited, n1);

        for (int j=0; j<path.size()-1; j++) {
            int now = path[j];
            int next = path[j+1];
            if (parentNode[now] != next) {
                answer[i] = now;
                break;
            }
        }
        if (answer[i] == 0) {
            answer[i] = path.back();
        }
        tree.clear();
    }

    for(int i=0;i<T;i++) {
        cout << answer[i] << "\n";
    }


    return 0;
}
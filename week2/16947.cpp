#include <iostream>
#include <vector>

using namespace std;

int* visited;
vector<vector<int>> graph;
int answer = 0;
bool cycle = false;

int find_cycle(int node, int preNode) {
    visited[node] = 1;
    for (int i=0; i<graph[node].size();i++) {
        int nextNode = graph[node][i];
        if ( preNode == nextNode)
            continue;

        if (visited[nextNode] == 1) {
            cycle = true;
            return nextNode;
        }
        int flag = find_cycle(nextNode, node);
        
        if(flag != 0) {
            if(flag == node) {
                return 0;
            }
            return flag;
        }

    }

    
    visited[node] = 0;

    return 0;
}

int DFS(int node, int preNode) {
    visited[node] = 1;
    
    for (int i=0; i<graph[node].size();i++) {
        int nextNode = graph[node][i];
        if ( preNode == nextNode)
            continue;

        if (visited[nextNode] == 1) {
            visited[node] = 2;
            return 2;
        }
        int flag = DFS(nextNode, node);
        
        if(flag) {
            visited[node] = flag + 1;
            return flag + 1;
        }

    }

    return 0;
}

int main() {
    int N;
    cin >> N;

    visited = new int[N+1]();

    graph.resize(N+1);

    int n1, n2;
    for (int i=0; i<N; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    int enter = find_cycle(1, 0);

    int* answer = new int[N+1]();
    

    for (int i=1; i<N+1; i++) {
        if (visited[i] == 0) {
            DFS(i, 0);
        }
    }

    for (int i=1; i<N+1; i++) {
        cout << visited[i]-1 << " ";
    }


    return 0;
}
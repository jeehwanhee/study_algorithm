#include <iostream>
#include <vector>

using namespace std;

int** visited;
int answer = 0;
int R, S;

bool DFS(int x, int y) {
    if (y == S-1) {
        answer++;
        return true;
    }
    int nextx, nexty;

    vector<int> direction;
    if (x == 0) {
        direction = {0, 1};
    }
    else if (x == R-1) {
        direction = {-1, 0};
    }
    else {
        direction = {-1, 0, 1};
    }

    for (int i=0;i<direction.size();i++) {
        nextx = x+direction[i]; nexty = y+1;
        if (visited[nextx][nexty] == 0) {
            visited[nextx][nexty] = 1;
            if (DFS(nextx, nexty)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int v1, v2;
    cin >> R >> S;

    string input;
    visited = new int*[R];
    for (int i=0;i<R;i++) {
        int* column = new int[S]();
        cin >> input;
        for (int j=0; j<S;j++) {
            if (input[j] == 'x') {
                column[j] = 1;
            }
        }
        visited[i] = column;
    }

    for (int i=0; i<R; i++) {
        DFS(i, 0);
    }

    cout << answer;


    return 0;
}
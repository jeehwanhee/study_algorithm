#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int index = 1;

    while (true) {
        int N;
        cin >> N;

        if(N==0) return 0;

        int** map = new int*[N];
        int** answer = new int*[N];

        for (int i=0; i<N; i++) {
            int* answerRow = new int[N]();
            int* row = new int[N]();

            for (int j=0;j<N;j++) {
                answerRow[j] = 1000000;
                cin >> row[j];
            }
            answer[i] = answerRow;
            map[i] = row;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({map[0][0],0,0});
        answer[0][0] = map[0][0];

        while (!pq.empty())
        {
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            for (int i=0; i<4; i++) {
                int nextX = x+dx[i];
                int nextY = y+dy[i];
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                    if(answer[x][y] + map[nextX][nextY] < answer[nextX][nextY]) {
                        pq.push({answer[x][y] + map[nextX][nextY], nextX, nextY});
                        answer[nextX][nextY] = answer[x][y] + map[nextX][nextY];
                    }
                }
            }
        }
        
        cout << "Problem " << index++ << ": " << answer[N-1][N-1] << "\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int** map = new int*[n];
    int*** answer = new int**[n]; //[x][y][점프 여부]
    int input;
    for (int i = 0; i < n; i++) {
        int** answerInitRow = new int*[m];
        int* mapInitRow = new int[m];
        for (int j = 0; j < m; j++){
            cin >> input;
            mapInitRow[j] = input;
            answerInitRow[j] = new int[2];
            answerInitRow[j][0] = 1e9 + 1;
            answerInitRow[j][1] = 1e9 + 1;
        }
        answer[i] = answerInitRow;
        map[i] = mapInitRow;
    }


    queue<array<int, 3>> queue;
    array<int, 3> element = {0, 0, 0}; //[x, y, 점프여부]

    answer[0][0][0] = map[0][0];
    queue.push({0,0,0});

    int level, x, y, nextLevel, minLevel, jump;
    while(!queue.empty()) {
        element = queue.front();
        queue.pop();
        x = element[0]; 
        y = element[1];
        jump = element[2];
        level = answer[x][y][jump];
        if(element[0]-1 >= 0) {
            nextLevel = map[x-1][y];
            minLevel = max(level, nextLevel);
            if(answer[x-1][y][jump] > minLevel) {
                answer[x-1][y][jump] = minLevel;
                queue.push({x-1, y, jump});
            }
        }
        if(element[0]+1 <= n-1) {
            nextLevel = map[x+1][y];
            minLevel = max(level, nextLevel);
            if(answer[x+1][y][jump] > minLevel) {
                answer[x+1][y][jump] = minLevel;
                queue.push({x+1, y, jump});
            }
        }
        if(element[1]-1 >= 0) {
            nextLevel = map[x][y-1];
            minLevel = max(level, nextLevel);
            if(answer[x][y-1][jump] > minLevel) {
                answer[x][y-1][jump] = minLevel;
                queue.push({x, y-1, jump});
            }
        }
        if(element[1]+1 <= m-1) {
            nextLevel = map[x][y+1];
            minLevel = max(level, nextLevel);
            if(answer[x][y+1][jump] > minLevel) {
                answer[x][y+1][jump] = minLevel;
                queue.push({x, y+1, jump});
            }
        }

        //점프
        if(element[2] == 0) {
            if(element[0]-2 >= 0) {
                nextLevel = map[x-2][y];
                minLevel = max(level, nextLevel);
                if(answer[x-2][y][1] > minLevel) {
                    answer[x-2][y][1] = minLevel;
                    queue.push({x-2, y, 1});
                }
            }
            if(element[0]+2 <= n-1) {
                nextLevel = map[x+2][y];
                minLevel = max(level, nextLevel);
                if(answer[x+2][y][1] > minLevel) {
                    answer[x+2][y][1] = minLevel;
                    queue.push({x+2, y, 1});
                }
            }
            if(element[1]-2 >= 0) {
                nextLevel = map[x][y-2];
                minLevel = max(level, nextLevel);
                if(answer[x][y-2][1] > minLevel) {
                    answer[x][y-2][1] = minLevel;
                    queue.push({x, y-2, 1});
                }
            }
            if(element[1]+2 <= m-1) {
                nextLevel = map[x][y+2];
                minLevel = max(level, nextLevel);
                if(answer[x][y+2][1] > minLevel) {
                    answer[x][y+2][1] = minLevel;
                    queue.push({x, y+2, 1});
                }
            }
        }
    }

    cout << min(answer[n-1][m-1][0], answer[n-1][m-1][1]);

    return 0;
}
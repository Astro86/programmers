#include <bits/stdc++.h>
using namespace std;

int total = 0;
bool check[9];
int isUsed[26];

bool cmpTwoPosition(char cmp, int a, int b, int value) {
    if (cmp == '=') {
        return abs(a - b) - 1 == value;
    } else if (cmp == '<') {
        return abs(a - b) - 1 < value;
    } else {
        return abs(a - b) - 1 > value;
    }
}

void dfs(int n, int num, vector<string>& data) {
    if (num == n) {
        total++;
        return;
    }
    char friend1 = data[num][0] - 'A';
    char friend2 = data[num][2] - 'A';
    char cmp = data[num][3];
    char value = data[num][4] - '0';

    if (isUsed[friend1] && isUsed[friend2]) {
        int friend1_idx = isUsed[friend1];
        int friend2_idx = isUsed[friend2];

        if (cmpTwoPosition(cmp, friend1_idx, friend2_idx, value)) {
            dfs(n, num + 1, data);
        }
    }

    if (isUsed[friend1] && !isUsed[friend2]) {
        int friend1_idx = isUsed[friend1];

        for (int i = 1; i <= 8; i++) {
            if (check[i] == true) {
                continue;
            }

            if (cmpTwoPosition(cmp, friend1_idx, i, value)) {
                check[i] = true;
                isUsed[friend2] = i;
                dfs(n, num + 1, data);
                isUsed[friend2] = 0;
                check[i] = false;
            }
        }
    }

    if (!isUsed[friend1] && isUsed[friend2]) {
        int friend2_idx = isUsed[friend2];

        for (int i = 1; i <= 8; i++) {
            if (check[i] == true) {
                continue;
            }

            if (cmpTwoPosition(cmp, i, friend2_idx, value)) {
                check[i] = true;
                isUsed[friend1] = i;
                dfs(n, num + 1, data);
                isUsed[friend1] = 0;
                check[i] = false;
            }
        }
    }

    if (!isUsed[friend1] && !isUsed[friend2]) {
        for (int i = 1; i <= 8; i++) {
            if (check[i] == true) {
                continue;
            }
            check[i] = true;
            isUsed[friend1] = i;

            for (int j = 1; j <= 8; j++) {
                if (check[j] == true) {
                    continue;
                }
                if (cmpTwoPosition(cmp, i, j, value)) {
                    check[j] = true;
                    isUsed[friend2] = j;
                    dfs(n, num + 1, data);
                    isUsed[friend2] = 0;
                    check[j] = false;
                }
            }
            isUsed[friend1] = 0;
            check[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    set<char> s;
    for (int i = 0; i < n; i++) {
        int char1 = data[i][0];
        int char2 = data[i][2];

        s.insert(char1);
        s.insert(char2);
    }

    int value = 8 - s.size();
    int sum = 1;
    while (value) {
        sum *= value;
        value--;
    }

    dfs(n, 0, data);

    // cout << total << " " << sum << endl;
    return total * sum;
}
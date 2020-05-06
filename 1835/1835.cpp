#include <bits/stdc++.h>
using namespace std;

int total;
bool check[9];
int isUsed[26];

bool cmpTwoIdx(char cmp, int idx1, int idx2, int value) {
    if (cmp == '=') {
        return abs(idx1 - idx2) - 1 == value;
    } else if (cmp == '<') {
        return abs(idx1 - idx2) - 1 < value;
    } else {
        return abs(idx1 - idx2) - 1 > value;
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

    // 두 문자 다 사용한 경우
    if (isUsed[friend1] && isUsed[friend2]) {
        int friend1_idx = isUsed[friend1];
        int friend2_idx = isUsed[friend2];

        if (cmpTwoIdx(cmp, friend1_idx, friend2_idx, value)) {
            dfs(n, num + 1, data);
        }
    }

    // 하나의 문자만 사용한 경우
    if (isUsed[friend1] && !isUsed[friend2]) {
        int friend1_idx = isUsed[friend1];

        for (int i = 1; i <= 8; i++) {
            if (check[i] == true) {
                continue;
            }

            if (cmpTwoIdx(cmp, friend1_idx, i, value)) {
                check[i] = true;
                isUsed[friend2] = i;
                dfs(n, num + 1, data);
                isUsed[friend2] = 0;
                check[i] = false;
            }
        }
    }

    // 하나의 문자만 사용한 경우
    if (!isUsed[friend1] && isUsed[friend2]) {
        int friend2_idx = isUsed[friend2];
        for (int i = 1; i <= 8; i++) {
            if (check[i] == true) {
                continue;
            }

            if (cmpTwoIdx(cmp, i, friend2_idx, value)) {
                check[i] = true;
                isUsed[friend1] = i;
                dfs(n, num + 1, data);
                isUsed[friend1] = 0;
                check[i] = false;
            }
        }
    }

    // 두 문자 다 사용한 적 없는 경우
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
                if (cmpTwoIdx(cmp, i, j, value)) {
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

int solution(int n, vector<string> data) {
    int answer = 0;
    total = 0;

    memset(check, false, sizeof(check));
    memset(isUsed, 0, sizeof(isUsed));

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

int main(void) {
    int n;
    cin >> n;
    vector<string> data;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        data.push_back(s);
    }

    cout << solution(n, data) << '\n';
    return 0;
}
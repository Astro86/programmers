#include <bits/stdc++.h>
using namespace std;

int total = 0;
bool isKey(vector<bool>& check, vector<vector<string>>& relation) {
    set<string> s;

    bool isAllFalse = true;
    for (int i = 0; i < check.size(); i++) {
        if (check[i] != false) {
            isAllFalse = false;
        }
    }

    if (isAllFalse) {
        return false;
    }

    for (auto& row : relation) {
        string tmp;
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == true) {
                tmp += row[i] + " ";
            }
        }
        s.insert(tmp);
    }

    if (s.size() == relation.size()) {
        return true;
    } else {
        return false;
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int relation_row = relation.size();
    int relation_col = relation[0].size();

    vector<bool> check = vector<bool>(relation_col, false);

    queue<vector<bool>> q;
    q.push(check);
    while (!q.empty()) {
        vector<bool> cnt_check;
        cnt_check.assign(q.front().begin(), q.front().end());
        q.pop();

        if (isKey(cnt_check, relation)) {
            total++;
            continue;
        }

        int last_index = 0;
        for (int i = 0; i < cnt_check.size(); i++) {
            if (cnt_check[i] == true) {
                last_index = i;
            }
        }

        for (int i = last_index; i < cnt_check.size(); i++) {
            if (cnt_check[i] == false) {
                cnt_check[i] = true;
                q.push(cnt_check);
                cnt_check[i] = false;
            }
        }
    }

    answer = total;
    return answer;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> relation(n, vector<string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> relation[i][j];
        }
    }

    cout << solution(relation) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int total = 0;
vector<int> candidates;
bool isKey(int check, vector<vector<string>>& relation) {
    set<string> s;

    if (check == 0)
        return false;

    for (auto& row : relation) {
        string tmp;
        for (int i = 0; (1 << i) <= check; i++) {
            if (check & (1 << i)) {
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

bool isKeyUsed(int check) {
    for (int i = 0; i < candidates.size(); i++) {
        int value = check & candidates[i];

        if (value == candidates[i] || value == check) {
            return true;
        }
    }
    return false;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int row = relation.size();
    int col = relation[0].size();

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int cnt_check = q.front().first;
        int start_idx = q.front().second;
        q.pop();

        if (isKeyUsed(cnt_check)) {
            continue;
        }

        if (isKey(cnt_check, relation)) {
            total++;
            candidates.push_back(cnt_check);
            continue;
        }

        for (int i = start_idx; i < col; i++) {
            int next = cnt_check | (1 << i);
            q.push({next, i + 1});
        }
    }

    return total;
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
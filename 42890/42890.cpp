#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<bool> check;
int total = 0;

bool isKey(vector<vector<string>>& relation) {
    set<string> s;

    for (auto& row : relation) {
        string tmp;
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == true) {
                tmp += row[i] + " ";
            }
        }
        cout << tmp << endl;
        s.insert(tmp);
    }

    cout << s.size() << " " << relation.size() << endl
         << endl;

    if (s.size() == relation.size()) {
        return true;
    } else {
        return false;
    }
}

void dfs(int index, int num, vector<vector<string>>& relation) {
    if (index >= check.size()) {
        return;
    }

    if (isKey(relation)) {
        total++;
        return;
    }

    for (int i = cnt; i < check.size(); i++) {
        check[i] = true;
        dfs(i + 1, relation);
        check[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    check = vector<bool>(relation[0].size(), false);

    dfs(0, relation);

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
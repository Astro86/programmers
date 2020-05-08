def solution(relation):
    answer = 0
    row_size = len(relation)
    col_size = len(relation[0])

    candidate_key = 0

    for i in range(col_size):
        s = set()
        for j in range(row_size):
            s.add(relation[j][i])

        if (len(s) == row_size):
            print(s)
            candidate_key += 1

    for i in range()

    answer = candidate_key
    return answer


n, m = map(int, input().split())

relation = [[0] * m for _ in range(n)]
for i in range(n):
    relation[i] = input().split()

print(solution(relation))

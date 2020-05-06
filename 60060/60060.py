def solution(words, queries):
    answer = []
    for cnt_query in queries:
        num = 0

        for cnt_word in words:
            if(len(cnt_query) != len(cnt_word)):
                continue

            isSame = True
            for i in range(len(cnt_query)):
                if (cnt_query[i] != '?' and cnt_query[i] != cnt_word[i]):
                    isSame = False
                    break

            if(isSame):
                num += 1

        answer.append(num)

    return answer


n = int(input())
words = []
for i in range(n):
    words.append(input())
m = int(input())
queries = []
for i in range(m):
    queries.append(input())

print(solution(words, queries))

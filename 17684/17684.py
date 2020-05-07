alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
dic = {}

for i in range(len(alphabet)):
    dic[alphabet[i]] = i+1

cnt_max_value = 26


def solution(msg):
    answer = []

    global dic
    global cnt_max_value

    start_index = 0
    while(start_index < len(msg)):
        end_index = start_index+1
        while(end_index <= len(msg) and msg[start_index: end_index] in dic):
            end_index += 1

        end_index -= 1

        answer.append(dic[msg[start_index: end_index]])
        dic[msg[start_index: end_index+1]] = len(dic) + 1

        start_index = end_index

    return answer


msg = input()
print(dic)
print(solution(msg))

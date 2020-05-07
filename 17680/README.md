# 캐시

https://programmers.co.kr/learn/courses/30/lessons/17680

## 전체 소스 코드
```python
def solution(cacheSize, cities):
    answer = 0
    cache = []

    for city in cities:
        city = city.lower()

        if (city in cache):
            index = cache.index(city)
            use_sity_name = cache.pop(index)
            cache.append(use_sity_name)
            answer += 1
        else:
            cache.append(city)

            if(len(cache) > cacheSize):
                cache.pop(0)
            answer += 5

    return answer
```
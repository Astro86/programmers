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

            if(len(cache) == cacheSize):
                cache.pop(0)
            answer += 5

    return answer


cache_size = int(input())
m = int(input())
cities = []
for i in range(m):
    cities.append(input())

print(solution(cache_size, cities))

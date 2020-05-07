def solution(cacheSize, cities):
    answer = 0
    cache = []

    for city in cities:
        if (city in cache):
            index = cache.index(city)
            use_sity_name = cache.pop(index)
            cache.append(use_sity_name)
            answer += 1
        else:
            if(len(cache) > cacheSize):
                cache.pop(0)
            cache.append(city)
            answer += 5

    return answer

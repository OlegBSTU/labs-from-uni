def factorial(k: int):
    res = 1
    while k > 0:
        res *= k
        k -= 1
    return res


def generator(j, r):
    if j == r:
        for i in range(0, n):
            print(elt[i], end=" ")
        print()
    else:
        v = ""
        for i in range(j, r):
            v = elt[j]  # обмен elt[j], elt[i]
            elt[j] = elt[i]
            elt[i] = v
            generator(j+1, r)  # вызов новой генерации
            v = elt[j]  # обмен elt[j], elt[i]
            elt[j] = elt[i]
            elt[i] = v


print("Введите n:", end=" ")
n = int(input())
if n <= 0:
    print("Неверные данные")
else:
    elt = []
    print("Введите элементы")
    for i in range(1, n + 1):
        print(str(i)+")", end=" ")
        elt.append(input())
    m = factorial(n)
    print("Всего перестановок : " + str(m))
    generator(0, n)

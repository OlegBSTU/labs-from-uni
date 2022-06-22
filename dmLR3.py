def generator(j, r):
    v = ""
    for i in range(n):
        print(elt[i], end=" ")
    print()
    for i in range(j, r):
        v = elt[j]  # обмен elt[j], elt[i]
        elt[j] = elt[i]
        elt[i] = v
        generator(j+1, r)  # вызов новой генерации
        v = elt[j]  # обмен elt[j], elt[i]
        elt[j] = elt[i]
        elt[i] = v


def factorial(k: int):
    res = 1
    while k > 0:
        res *= k
        k -= 1
    return res


print("Введите n:", end=" ")
n = int(input())
if n <= 0:
    print("Неверные данные")
else:
    elt = []
    print("Введите элементы")
    for i in range(n):
        print(str(i)+")", end=" ")
        elt.append(input())
    print("Всего перестановок : " + str(factorial(n)))
    generator(1, n)

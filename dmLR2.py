def factorial(k: int):
    res = 1
    while k > 0:
        res *= k
        k -= 1
    return res


def combination(elems: list, n: int, k: int, j: int, h: int, s: str):
    if j <= k:
        for i in range(h, n):
            combination(elems, n, k, j+1, i+1, s+elems[i]+' ')
    else:
        print(s)


elements = list()
print("Введите n: ")
n = int(input())
print("Введите k: ")
k = int(input())
if n < k:
    print('Данные введены некорректно')
else:
    print("Введите элементы")
    for i in range(n):
        elements.append(input())
    print('n = ', n, '\nk = ', k)
    for i in range(n):
        print(str(i + 1) + ') ' + str(elements[i]))
    print('Всего сочетаний: ', int(factorial(n) / (factorial(k) * factorial(n - k))))
    combination(elements, n, k, 1, 0, '')

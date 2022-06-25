def factorial(k: int):
    res = 1
    while k > 0:
        res *= k
        k -= 1
    return res


def razmeshenie(elt, m, n, s):
    if n == 0:
        print(s)
    else:
        for i in range(m):
            if not elt[i] in s:
                razmeshenie(elt, m, n - 1, s + elt[i] + ' ')


def degree(m, n):
    for i in range(1, n):
        m *= m
    return m


def razmesh_pov(elt, m, n, s):
    if n == 0:
        print(s)
    else:
        for i in range(0, m):
            razmesh_pov(elt, m, n - 1, s + elt[i] + ' ')


elt = list()
print('Введите m: ', end='')
m = int(input())
print('Введите n: ', end='')
n = int(input())
if n > m:
    print('Неверные данные')
else:
    print('Введите элементы')
    for i in range(0, m):
        print(str(i) + ') ', end='')
        elt.append(input())
    print('Размещения с повторениями?(да/нет)')
    choice = input()
    if choice == 'нет':
        print('Всего размещений: ' + str(factorial(m) / factorial(m - n)))
        razmeshenie(elt, m, n, '')
    else:
        print('Всего размещений: ' + str(degree(m, n)))
        razmesh_pov(elt, m, n, '')


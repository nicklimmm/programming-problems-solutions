"""
https://projecteuler.net/problem=85

To solve this, we can search the size of the grid m x n that
yields the nearest value to 2 million.

We can get the number of rectangles that are contained inside
the m x n grid by using this formula,

    (n * (n + 1) // 2) * (m * (m + 1) // 2).
"""

def count(m, n):
    return (n * (n + 1) // 2) * (m * (m + 1) // 2)

area = 0
nearest = 0
m, n = 1, 1

while count(m, 1) < 2000000:
    while True:
        rect_count = count(m, n)
        if rect_count >= 2000000:
            break
        if rect_count > nearest:
            area = m * n
            nearest = rect_count
        n += 1
    m += 1
    n = 1

print(area)
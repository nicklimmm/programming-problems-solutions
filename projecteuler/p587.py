"""
https://projecteuler.net/problem=587

My approach on this problem is very math-heavy, which uses integration, Cartesian
coordinates, algebra, etc.

Idea:
1. Use integration to find the area.
2. The function of the line is y = x / n, where n is the number of circles.
3. The function of the leftmost circle (with radius 1) is y = 1 - sqrt(2 - x^2).
4. To find the area of the concave triangle, we find the explicit formula of the area by:
        - integrating it from 0 to a, where a is the x-coordinate of the first 
          intersection between the line and the circle (triangle).
        - integrating it from a to 1 (area under the circle).
5. Calculate the ratio between the concave triangle and the L-section.
6. Increment the value of n until the ratio is 0.1%.
"""
from math import sqrt, sin, asin, pi


l_sect = 1 - pi / 4
n = 1

while True:
    # The x-coordinate of the point where the line and the first circle intersect
    a = (n * (1 - sqrt(2 * n)) + n ** 2) / (1 + n ** 2)

    # Area under the triangle from 0 until a
    area_tri = a ** 2 / 2 / n                 

    # Area under the circle from a until 1                       
    area_cir = 1 - a + 0.25 * sin(2 * asin(a - 1)) + 0.5 * asin(a - 1)   

    # Total area of concave triangle   
    area_concave_tri = area_tri + area_cir   

    # Calculate ratio                         
    percentage = area_concave_tri / l_sect * 100
    if percentage < 0.1:
        print(n)
        break
    n += 1
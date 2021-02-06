"""
https://projecteuler.net/problem=102

Below is the link for the visualization of the triangle
https://www.google.com/url?sa=i&url=https%3A%2F%2Fmath.stackexchange.com%2Fquestions%2F2722565%2Ffind-out-if-a-point-is-inside-triangle-only-data-available-are-distances&psig=AOvVaw04EcXUomCoryVMaa2V0-zD&ust=1612711254128000&source=images&cd=vfe&ved=2ahUKEwiKrNjcx9XuAhXSlEsFHXItCeAQr4kDegUIARC1AQ

Idea:
1. Calculate all the distances OA, OB, OC, AB(c), BC(a), AC(b) using
   distance of 2 points formula, where O is the origin and A, B, and C
   are the 3 points given.

2. Let gamma = angle(AOB), alpha = angle(BOC), and beta = angle(AOC).
   If the triangle contains the origin, then
        gamma + alpha + beta = 2 * pi
   which can be calculated using cosine rule.

3. Count all the number of triangles that satisfies the condition.
"""

from math import acos, pi


# Distance between two points
def distance(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return ((y2 - y1) ** 2 + (x2 - x1) ** 2) ** 0.5


# Checks if the triangle contains the origin
def origin_is_inside_triangle(p1, p2, p3):
    origin = (0, 0)

    # Relevant distances
    c, a, b = distance(p1, p2), distance(p2, p3), distance(p1, p3)
    oa, ob, oc = distance(origin, p1), distance(origin, p2), distance(origin, p3)

    # Angles inside the triangle
    gamma = acos((oa ** 2 + ob ** 2 - c ** 2) / (2 * oa * ob))
    alpha = acos((oc ** 2 + ob ** 2 - a ** 2) / (2 * oc * ob))
    beta = acos((oa ** 2 + oc ** 2 - b ** 2) / (2 * oa * oc))

    # total angle == 2 * pi if it contains the origin
    total_angle = gamma + alpha + beta

    # Returns True if the total angle == 2*pi, otherwise False
    if round(total_angle, 5) == round(2 * pi, 5):
        return True
    else:
        return False


# Input cleaning
file = open("p102_triangles.txt", "r").read().replace("\n", ",").split(",")

count = 0
for i in range(0, 6000, 6):
    a = (int(file[i]), int(file[i + 1]))
    b = (int(file[i + 2]), int(file[i + 3]))
    c = (int(file[i + 4]), int(file[i + 5]))
    if origin_is_inside_triangle(a, b, c):
        count += 1

print(count)

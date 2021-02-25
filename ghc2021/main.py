itl = {}

d, i, s, v, f = list(map(int, input().split()))
for _ in range(s):
    b, e, name, l = input().split()
    b, e, l = int(b), int(e), int(l)
    
for _ in range(v):
    buffer = input().split()
    p = int(buffer[0])
    p_list = buffer[1:]
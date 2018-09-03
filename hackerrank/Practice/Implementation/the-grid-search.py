def is_complete_pattern(G, P, i, j, r, c):
    for k in range(r):
        for l in range(c):
            if G[k+i][l+j] != P[k][l]:
                return False
    return True

def search_grid(G, P, R, C, r, c):
    for i in range(R-r+1):
        for j in range(C-c+1):
            if is_complete_pattern(G, P, i, j, r, c):
                return True
    return False

t = int(input().strip())
for a0 in range(t):
    R,C = input().strip().split(' ')
    R,C = [int(R),int(C)]
    G = list()
    for G_i in range(R):
        G.append(list(input().strip()))
    r,c = input().strip().split(' ')
    r,c = [int(r),int(c)]
    P = list()
    for P_i in range(r):
        P.append(list(input().strip()))

    if search_grid(G, P, R, C, r, c):
        print("YES")
    else:
        print("NO")

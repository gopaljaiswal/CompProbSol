def fast_mul(A, B, a, limit):
    x, y = a, A
    while B > 0:
        if B & 1:
            x = x * y
            if x > limit: return True	
        y = y * y
        B >>= 1
    return False


def bs(a, k, limit):
    low, high = 0, 58
    res = -1
    while low <= high:
        mid = (low + high) >> 1
        if fast_mul(k, mid, a, limit):
            high -= 1
        else:
            res = mid
            low = mid + 1
    return res


for __ in range(input()):
    a, k, limit = map(int, raw_input().split())
    print bs(a, k, limit)
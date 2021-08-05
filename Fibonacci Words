import os
def find_digit(A, B, n):
    lengths = [len(A)]
    if n <= len(A):
        return A[n-1]
    lengths.append(len(B))
    if n <= len(B):
        return B[n-1]

    idx = 1
    while True:
        idx = idx + 1
        lengths.append(lengths[idx-2] + lengths[idx-1])
        if lengths[idx]  >= n:
            break
    len_diff = n
    while idx > 1:
        if lengths[idx-2] < len_diff:
            len_diff = len_diff - lengths[idx-2]
            idx = idx - 1
        else:
            idx = idx - 2

    if idx == 0:
        return A[len_diff-1]
    else:
        return B[len_diff-1]


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    num_tests = int(input().strip())
    tests = []
    for i in range(num_tests):
        A, B, n_str = input().rstrip().split()
        num = find_digit(A, B, int(n_str))
        fptr.write(str(num) + '\n')

    fptr.close()

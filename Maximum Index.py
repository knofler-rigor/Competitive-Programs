def maximumIndex(N, B):
    
    max_index = 0
    for i in range(1, N + 1):
        max_index += i

    current_index = max_index
    step = N

    while (1):

        while (current_index > 0 and N > 0):

            current_index -= N

            if (current_index == B):

                current_index += N

            N -= 1

        if (current_index <= 0):
            
            print(max_index)
            break
        else:
            N = step
            current_index = max_index - 1
            max_index -= 1

            
            if (current_index == B):
                current_index = max_index - 1
                max_index -= 1


    
N=int(input())
B=int(input())
maximumIndex(N, B)

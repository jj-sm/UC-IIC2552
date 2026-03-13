import sys

input = sys.stdin.readline

def main():
    n_elements: int = int(input())
    n_vec: list[int] = [int(x) for x in input().strip().split()]  
    
    n_numbs: set[int] = set(n_vec)

    if len(n_numbs) == n_elements:
        print(1)

    elif len(n_numbs) == 1:
        print(0)

    else:
        last_pos: list[int] = [-1 for _ in range(n_elements + 1)]
        operations: list[int] = [0 for _ in range(n_elements + 1)]

        for i in range(n_elements):
            x: int = n_vec[i]

            if last_pos[x] == -1:
                if i > 0:
                    operations[x] += 1

            else:
                if i - last_pos[x] > 1:
                    operations[x] += 1

            last_pos[x] = i

        min_operations: int = n_elements * 2

        for x in n_numbs:
            # print(x, n_numbs)
            if last_pos[x] < n_elements - 1:
                operations[x] += 1

            if operations[x] < min_operations:
                min_operations = operations[x]

        print(min_operations)

        


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        main()

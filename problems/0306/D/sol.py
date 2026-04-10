import sys

input = sys.stdin.readline

def main() -> None:
    n, k = input().strip().split(' ')
    n = int(n)
    k = int(k)

    h = input().strip().split(' ')
    h = [int(x) for x in h]

    last_sum: int = sum(h[:k])
    min: int = last_sum
    idx_min: int = 1

    for i in range(k, n):
        last_sum += h[i] - h[i-k]

        if last_sum < min:
            min = last_sum
            idx_min = i + 2 - k

    print(idx_min)

if __name__ == "__main__":
    main()

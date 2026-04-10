import sys

input = sys.stdin.readline

def main() -> None:
    n = int(input())
    a = []
    best = 0
    
    ans= []

    in_2 = input().split()
    a.extend(map(int, in_2))

    for i in range(n):
        a_i = a[i]
        e = []
        case = 0

        for k in range(i+1, n):
            a_k = a[k]
            mid = a_i + a_k

            if a_k < a_i:
                e.append(mid * 2)
                case += 1
            elif a_k > a_i:
                e.append(mid * 2 + 1)

        e.sort()

        current = case;
        best = current

        for x in e:
            if x & 1:
                current +=1;
            else:
                current -= 1

            best = max(best, current)

        ans.append(best)
    print(*ans)

if __name__ == "__main__":
    t = 1
    t = int(input())
    for _ in range(t):
        main()
    

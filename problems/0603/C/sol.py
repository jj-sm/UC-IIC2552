import sys

input = sys.stdin.readline

def main():
    n = input()
    frug: str = input()
    prev: str = ''
    count = 0

    for char in frug:
        if prev == char:
            count += 1
        else:
            prev = char

    print(count)

if __name__ == "__main__":
    main()

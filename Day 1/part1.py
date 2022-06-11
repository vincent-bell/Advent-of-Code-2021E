from typing import List


def solve(input: List[int]):
    largerThanPrevCounter = 0
    prev_data = None

    for item in input:
        if prev_data and item > prev_data:
            largerThanPrevCounter += 1
        prev_data = int(item)

    return largerThanPrevCounter


def main():
    with open("day1.txt", 'r') as f:
        data = list(map(lambda x: int(x.strip()), f.readlines()))

    result = solve(input=data)

    print(f'largerThanPrevCounter = {result}')


if __name__ == '__main__':
    main()

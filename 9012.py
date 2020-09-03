from enum import Enum

class TokenType(Enum):
    OPEN = 0
    CLOSE = 1
    PAIR = 2

def tokenize(string):
    i = 0
    while i < len(string):
        if i < len(string) - 1 and string[i:i+2] == '()':
            i += 2
            yield TokenType.PAIR
        elif string[i] == "(":
            i += 1
            yield TokenType.OPEN
        else:
            i += 1
            yield TokenType.CLOSE
    return False

class Pair:
    def __str__(self):
        return "()"

class Concat:
    def __init__(self, left, right):
        self.left = left
        self.right = right
    def __str__(self):
        return str(self.left) + str(self.right)

class EnclPar:
    def __init__(self, child):
        self.child = child
    def __str__(self):
        return "("+str(self.child)+")"

def parse(tokens):
    tokCnt = 0
    left = None
    right = None
    if tokens[0] == TokenType.PAIR:
        tokCnt += 1
        left = Pair()
    elif tokens[0] == TokenType.OPEN:
        tokCnt += 1
        (tmp, left) = parse(tokens[1:])
        if tmp < 0:
            return -1, -1
        tokCnt += tmp
        if (tokCnt == len(tokens)) or (tokens[tokCnt] != TokenType.CLOSE):
            return -1,-1
        tokCnt += 1
        left = EnclPar(left)
    else:
        return -1, -1

    if tokCnt == len(tokens):
        return tokCnt, left

    tmp, right = parse(tokens[tokCnt:])
    if tmp < 0:
        return tokCnt, left
    else:
        tokCnt += tmp
        return tokCnt, Concat(left, right)

def solve(string):
    tokens = list(tokenize(string))
    ret, ast = parse(tokens)
    if ret != -1 and ret == len(tokens):
        return True
    else:
        return False

def main():
    T = int(input())
    for _ in range(T):
        if solve(input()):
            print("YES")
        else:
            print("NO")

main()
#if __name__ == "__main__":
#    tokens = list(tokenize("()()(()"))
#    print(parse(tokens))
#    print(len(tokens))
#    tokens = list(tokenize("()()(())"))
#    print(parse(tokens))
#    print(len(tokens))
#    tokens = list(tokenize("()()(()))"))
#    print(parse(tokens))
#    print(len(tokens))

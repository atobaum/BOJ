def c2i(c):
    return ord(c) - ord('a')

# type:
# not, or, and ,xor, var, open cls
class Token:
    def __init__(self, typ, data = None):
        self.type = typ
        self.data = data

class Node(Token):
    pass

def Tokenizer(string):
    for c in string:
        if c.isalpha():
            yield Token("var", c)
        elif c == '~':
            yield Token("not")
        elif c == '|':
            yield Token("or")
        elif c == '&':
            yield Token("and")
        elif c == '^':
            yield Token("xor")
        elif c == '(':
            yield Token("open")
        elif c == ')':
            yield Token("cls")
        elif c == ' ':
            continue
        else:
            print("Error: in Tokenizer ", c)
            return False

def parse(Tokens):
    if len(Tokens) == 0:
        return None

    curToken = Tokens.pop(0)
    tokType = curToken.type
    print(tokType, curToken.data)
    if tokType == "not":
        expr = parse(tokens)
        prev = Node('not', data)
    elif tokType == "open":
        expr = parse(tokens)
        if tokens.pop(0).type == "cls":
            prev = expr
        else:
            print("Error while parsing ",tokType, curToken.data)
            return False
    elif tokType == "var":
        prev = Node('var', c2i(curToken.data))

    if len(Tokens) == 0:
        return prev
    
    curToken = Tokens[0]
    tokType = curToken.type

    if tokType in ['xor', 'and', 'or']:
        Tokens.pop(0)
        expr = parse(Tokens)
        return Node(tokType, [prev, expr])
    return prev

def normalize(ast):
    pass

def solve(string):
    (a_tok, end) = parse(string);
    (b_tok, ) = parse(string, end)
    a_normal = normalize(parse(tokenize(a_tok)))
    b_normal = normalize(parse(tokenize(b_tok)))
    return a_normal == b_normal

def main():
    T = int(input())
    for _ in range(T):
        result = "Data set "+(_+1)+": "
        if solve(input()):
            result += "Equivalent"
        else:
            result += "Different"
        print(result)

if __name__ == "__main__":
    #print([(t.type, t.data) for t in Tokenizer("a ^b&(b|a)~b^ a")])
    tokens = list(Tokenizer("a ^b&(b|a)~b^ a"))
    a = parse(tokens)
    print([(t.type, t.data) for t in tokens])
    b = parse(tokens)
    print(len(tokens))


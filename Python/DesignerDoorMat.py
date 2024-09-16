user_input = input()
n, m = map(int, user_input.split())

half = n//2
mat = ".|."
out = "-"
wordLength = 7

def create_pattern(m: int, x: int, word: bool) -> str:
    if (word):
        outNum = (m-x)//2
        return out*outNum+"WELCOME"+out*outNum
        
    else:
        matNum = 1+(x*2)
        outNum = (m-matNum*3)//2
        return out*outNum+mat*matNum+out*outNum

for x in range(half):
    print(create_pattern(m, x, False))

print(create_pattern(m, wordLength, True))

for x in reversed(range(half)):
    print(create_pattern(m, x, False))
    
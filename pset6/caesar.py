import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide cmd line arguments!")
        exit(1)
    
    n = int(sys.argv[1])
    translated = []
    msg = cs50.get_string()
    for symbol in msg:
        if symbol.isalpha():
            translated.append(caesar(symbol, n))
        else:
            translated.append(symbol)
                
    print("".join(translated))
    exit(0)

def caesar(char, n):
    if char.isupper():
        return chr(((ord(char) - 65 + n) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + n) % 26) + 97)
        
if __name__ == "__main__":
    main()
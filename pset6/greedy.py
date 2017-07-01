import cs50

def main():
    while True:
        print("O hai! How much change is owed?")
        amount = cs50.get_float()
        if amount >= 0:
            break
    
    leftover = 0
    a = int(round(amount * 100))
    
    leftover += a // 25
    a %= 25
    
    leftover += a // 10
    a %= 10
    
    leftover += a // 5
    a %= 5
    
    leftover += a
    
    print("{}".format(leftover))
    
if __name__ == "__main__":
    main()
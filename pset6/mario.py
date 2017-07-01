import cs50

def main():
    while True:
        print("Height: ", end = "")
        a = cs50.get_int()
        if a >= 0 and a <= 23:
            break
        
    for i in range(a):
        for j in range(a - i - 1):
            print(" ", end = "")
        for k in range(i+2):
            print("#", end = "")
        print("")
            
if __name__ == "_main_":
    main()
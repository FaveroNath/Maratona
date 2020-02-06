num1 = input()
mod = int(num1) % 4
mod1 = int(num1) % 9
mod2 = int(num1) % 25
if mod == 0 :
    print ("S")
else: 
    print("N")
if mod1 == 0:
    print("S")
else: 
    print("N")
if mod2 == 0:
    print("S")
else:
    print("N")


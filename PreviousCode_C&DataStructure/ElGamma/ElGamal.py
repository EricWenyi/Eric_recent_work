import random
import time

#to get the greatest common dividor of a and b
def gcd(a,b):
    while b != 0:
        a, b = b, a % b
    return a

def test_of_prime(num):
    a = 2
    flag = True
    while(a<=(num ** 0.5) and a % 2 != 0):
        if(num % a == 0):
            flag = False
        a += 1
    return flag

def multiplicate_inverse(e,phi):
    d = 0
    x1 = 0
    x2 = 1
    y1 = 1
    temp_phi = phi

    while e > 0:
        temp1 = temp_phi/e
        temp2 = temp_phi - temp1 * e
        temp_phi = e
        e = temp2

        x = x2- temp1* x1
        y = d - temp1 * y1

        x2 = x1
        x1 = x
        d = y1
        y1 = y

    if temp_phi == 1:
        return d + phi

def getGenerateor(p):
    list1 = range(1,p)
    for i in list1:
        list2 = []
        for j in range(0,p-1):
            list2.append((i ** j) % p) #We create a list2 contains all the element i creates
        if len(set(list2)) == (p - 1): #if the element i creates are unique, return i
            return i
    return 1


def encrypt(g,x,p):#This is the encryption process
    k = random.randrange(1,p)
    r = (g**k)%p
    s = (x*b**k)%p
    return r,s

def discrypt(r,s,a):
    ra = (r ** a)%p
    reRev = 0
    for i in range(1,p):
        if (i * ra)%p == 1:
            raRev = i
    if raRev == 0:
        print("No reverse found")
    else:
        message = (s * raRev)%p
        return message



print "ELGamal Encrypter/ Decrypter"
p = int(raw_input("Enter a prime number (17, 19, 23, etc): "))
g = getGenerateor(p)
a = random.randrange(1,p)
b = (g ** a)%p
x = int(raw_input("Please enter the message you wanna transfer: (Should be a number)"))
print "Encrypting, please hold on"
time.sleep(3)
r,s = encrypt(g,x,p)
print "The encrypted message is r:%d and s:%d" %(r,s)
print "Decrypting, please hold on"
time.sleep(3)
message = discrypt(r,s,a)
print ("The message you transfer is :%d") %message



'''
print "Generating your public/private keypairs now . . ."
private, public = generate_key(p, q)
print "Your public key is ", public ," and your private key is ", private
message = int(raw_input("Enter a message to encrypt with your public key: "))
encrypted_msg = encrypt(public, message)
print "Your encrypted message is: ",encrypted_msg
print "Decrypting message with private key ", private ," . . ."
original_msg = discrypt(private,encrypted_msg)
print "Your original message is ",original_msg
print "Thank you for watching"
'''







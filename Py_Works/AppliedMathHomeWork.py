import random

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





def generate_key(p,q):
    if not(test_of_prime(p) and test_of_prime(q)):
        raise ValueError('Both have to be prime')
    elif(p == q):
        raise ValueError('P and Q shall not be equal!!')
    #n = p * q
    n = p * q

    #phi is totient of n
    phi = (p - 1)*(q - 1)

    #choose e and d that are co-prime with phi
    e = random.randrange(1,phi)

    #Use Euclid's Algorithm to verify that e and phi are co-prime

    g = gcd(e,phi)
    while g != 1:
        e = random.randrange(1,phi)
        g = gcd(e,phi)

    #use extended Euclid's Algorithm to generate the key
    d = multiplicate_inverse(e,phi)


    return ((e,n),(d,n))

def encrypt(pk,message):
    public_key ,n = pk
    #generate a encryted message C in the form of a ^ b % c
    c = (message ** public_key) % n
    return c

def discrypt(sk,c):
    private_key,n = sk

    message = (c ** private_key) % n
    return message

print "RSA Encrypter/ Decrypter"
p = int(raw_input("Enter a prime number (17, 19, 23, etc): "))
q = int(raw_input("Enter another prime number (Not one you entered above): "))
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








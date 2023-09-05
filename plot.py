def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_prime():
    while True:
        num = random.randint(1, 415)
        if is_prime(num):
            return num

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def mod_exp(base, exponent, modulus):
    result = 1
    base = base % modulus
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent >>= 1
        base = (base * base) % modulus
    return result

def main():
    p = generate_prime()
    q = generate_prime()

    print(f"Here is the value for p: {p}")
    print(f"Here is the value for q: {q}")
    print("------------------------")

    n = p * q
    print(f"Here is the value for n: {n}")
    print("------------------------")

    tot = (p - 1) * (q - 1)
    print(f"Here is the totient value for n: {tot}")
    print("------------------------")

    copr = 3  # Assuming 3 as the coprime value
    print(f"Here is the coprime value for n: {copr}")
    print("------------------------")

    priv_key = mod_inverse(copr, tot)
    print(f"Here is the private key value for n: {priv_key}")
    print("------------------------")

    m = int(input("Now enter the message to be encrypted: "))
    encryption = mod_exp(m, copr, n)
    decryption = mod_exp(encryption, priv_key, n)

    print(f"Here is the encrypted value: {encryption}")
    print(f"Here is the decrypted value: {decryption}")

if __name__ == "__main__":
    import random
    main()

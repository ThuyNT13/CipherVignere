# Cryptography - Vigenère Cipher

practice **C++** and creating **Encryption Algorithms**

initially created on [repl.it](https://repl.it/@ThuyNT13/CipherVignerecpp)

---

**encrypt**: `Ci = (Pi + Kj) mod 26`
  - implicit typecast conversion to ASCII code
  - add up values 
  - mod 26 converting sum to 0-25 

**decrypt**: `Pi = (Ci – Kj) mod 26`
  - implicit typecast conversion to ASCII code
  - subtract values and add 26 (for neg nums)
  - mod 26 converting to 0-25 
  - int decipherIndex = (cipherText[i] - key[i] + 26) % 26; 

**C** = *cipher text*

**P** = *plain text*

**K** = *key* char - alpha key to derive *cipher text* offset

**i** = the *ith* character in the *plain text*, corresponding with *cipher text* index

**j** = *jth* character of the *key*

`mod 26` returns an index within alphabetic range, 0-25 

## ASCII 

Utilizing [**ASCII table's**](http://www.asciitable.com/) mapping of *character* to *decimal code* to convert alphabet to integer, and vice versa.


## [Issues](https://github.com/ThuyNT13/CipherVignere/issues)

Present issues with code [here](https://github.com/ThuyNT13/CipherVignere/issues).
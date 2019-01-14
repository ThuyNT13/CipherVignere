#include <iostream>
#include <algorithm>
using namespace std;

string convertAsciiToChar(char ascii, int indexAlphaLower, int indexAlphaUpper, string cipherText)
{

  if (isalpha(ascii))
  {
    if (isupper(ascii))
    {
      indexAlphaUpper += 'A';
      cipherText.push_back(indexAlphaUpper);
    }
    else if (islower(ascii))
    {
      indexAlphaLower += 'a';
      cipherText.push_back(indexAlphaLower);
    }
  }
  else
  {
    cipherText.push_back(ascii);
  }

  return cipherText;
}

string generateKey(string plainText, string key)
{
  transform(key.begin(), key.end(), key.begin(), ::toupper);
  cout << key << endl;
  int i = 0;

  while (key.size() < plainText.size())
  {
    // cout << "key size: " << key.size() << ", i: " << i << ", key:" << key[i] << "\n";
    // init i=0 for key[i] -> beginning of key cycle
    key.push_back(key[i]);
    i++;
  }

  return key;
}

string encryptText(string plainText, string key)
{
  string cipherText;

  for (int i = 0; i < plainText.size(); i++)
  {
    char ascii = plainText[i];
    char offset = key[i];
    int indexAlphaLower = (ascii + 7 + offset) % 26;
    int indexAlphaUpper = (ascii - 13 + offset) % 26;

    cipherText = convertAsciiToChar(ascii, indexAlphaLower, indexAlphaUpper, cipherText);
  }

  return cipherText;
}

string decryptText(string cipherText, string key)
{
  string origText;

  for (int i = 0; i < cipherText.size(); i++)
  {
    char ascii = cipherText[i];
    char offset = key[i];
    int indexAlphaLower = (ascii + 7 - offset + 26) % 26;
    int indexAlphaUpper = (ascii - 13 - offset + 26) % 26;

    origText = convertAsciiToChar(ascii, indexAlphaLower, indexAlphaUpper, origText);
  }

  return origText;
}

int main()
{
  string cipher = "THUATOANHTHUYTHUTHUYTHOATHINH"; // string size 25
  string keyword = "BYGOMBT";

  // string cipher = "vwduwljudeehghyhubwklqjlfrxogilqgsohdvhuhwxuqdqbeoxhsulqwviruydxowdqgdodupghvljqedvhgrqzklfkedqnbrxghflghrqldpvhwwlqjxsvdihkrxvhfr";

  // string cipherText = "Kldinqlcytfysryucocphgbdizzfcmjwkuchzyeswfogmmetwwossdchrzyldsbwnydednzwnefydthtddbojicemlucdygicczhoadrzcylwadsxpilpiecskomoltejtkmqqymehpmmjxyolwpeewjckznpccpsvsxauyodhalmriocwpelwbcniyfxmwjcemcyrazdqlsomdbfljwnbijxpddsyoehxpceswtoxwbleecsaxcnuetzywfn";
  // string keyword = "skull";

  // string cipher = "Michig@n Techn0logical Univ3rsiTy!";
  // string keyword = "Houghton";

  string key = generateKey(cipher, keyword);
  // cout << "key: " << key << ", size: " << key.size() << "\n";

  string cipherText = encryptText(cipher, key);

  cout << "Encrypted Text: " << cipherText << "\n";
  cout << "Decrypted Text: " << decryptText(cipherText, key);

  return 0;
}
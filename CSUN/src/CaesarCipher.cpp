#include <iostream>
#include <algorithm>
class CaesarCipher {
 private:
  std::string text;
  int shift;
 public:
  CaesarCipher(std::string text, int shift);
  void Encrypt();
  void Decrypt();
  void PrintString();
};
CaesarCipher::CaesarCipher(std::string text, int shift) {
    this->text = text;
    this->shift = shift;
}
void CaesarCipher::Encrypt() {
  std::transform(text.begin(), text.end(), text.begin(), ::toupper);
  for (int i = 0; i < text.length(); i++) {
    if (text[i] != ' ') {
      if (shift < 0 && text[i] + shift < 'A') {
        text[i] = text[i] + 26;
      }
      text[i] = (text[i] - 'A' + static_cast<char>(shift)) % 26 + 'A';
    }
  }
}
void CaesarCipher::Decrypt() {
  shift = -1 * shift;
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  for (int i = 0; i < text.length(); i++) {
    if (text[i] != ' ') {
      if (shift < 0 && text[i] + shift < 'a'){
        text[i] = text[i] + 26;
      }
      text[i] = (text[i] - 'a' + static_cast<char>(shift)) % 26 + 'a';
    }
  }
}
void CaesarCipher::PrintString() {
    std::cout << text << std::endl;
}
int main() {
  std::string str;
  int shift = 0;
  std::cout << "enter a string to encrypt with Caesar Cipher!" << std::endl;
  std::getline(std::cin, str);
  std::cout << "enter shift value" << std::endl;
  std::cin >> shift;
  CaesarCipher test(str, shift);
  test.Encrypt();
  test.PrintString();
  test.Decrypt();
  test.PrintString();
  std::cout << std::endl;
  return 0;
}

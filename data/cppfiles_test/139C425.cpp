#include <bits/stdc++.h>
int main() {
  int count;
  std::string input;
  bool yep;
  std::cin >> count;
  std::string answer[count];
  for (int i = 0; i < count; i++) {
    yep = false;
    std::cin >> input;
    if (input.length() % 2 != 0)
      yep = false;
    else {
      for (int j = 0; j < input.length() / 2; j++) {
        if (input[j] == input[j + (input.length() / 2)])
          yep = true;
        else {
          yep = false;
          break;
        }
      }
    }
    if (yep == true) {
      answer[i] = "YES";
    } else
      answer[i] = "NO";
  }
  for (int i = 0; i < count; i++) {
    std::cout << answer[i] << std::endl;
  }
}

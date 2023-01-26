#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, firstNum, secondNum;
  int n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int numOfWays = 1;
    firstNum = 0;
    secondNum = 0;
    cin >> n;
    for (int j = 1; j <= 10; j++) {
      if (j % 2 == 0) {
        firstNum += n % 10 * pow(10, j / 2 - 1);
        n = n / 10;
      } else {
        secondNum += n % 10 * pow(10, (j - 1) / 2);
        n = n / 10;
      }
    }
    if (firstNum == 0 && secondNum == 0) {
      cout << 0 << endl;
    } else {
      cout << (firstNum + 1) * (secondNum + 1) - 2 << endl;
    }
  }
}

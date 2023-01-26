#include <bits/stdc++.h>
using namespace std;
int main() {
  int number1;
  cin >> number1;
  while (number1) {
    long long sum;
    cin >> sum;
    long long a, b;
    long long temp = sum / 3;
    if (sum % 3 == 0) {
      a = temp;
      b = temp;
    } else if (sum % 3 == 1) {
      a = temp + 1;
      b = temp;
    } else {
      b = temp + 1;
      a = temp;
    }
    cout << a << " " << b << endl;
    number1--;
  }
  return 0;
}

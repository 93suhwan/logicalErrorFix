#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (t--) {
    int r, l;
    cin >> r >> l;
    int num1 = 1, num2 = 1;
    while (num1 < r) {
      num1 = num1 * 2;
    }
    while (num2 < r) {
      num2 = num2 * 2;
    }
    int i = 0;
    while (num2 < num1) {
      num2 = num2 / 2;
      i++;
    }
    cout << i;
  }
}

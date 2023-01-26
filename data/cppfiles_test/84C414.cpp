#include <bits/stdc++.h>
using namespace std;
int fl() {
  int a;
  cin >> a;
  return a;
}
int main() {
  int t = fl();
  while (t--) {
    int a = fl(), b = fl();
    if (a == 1) {
      cout << b;
    } else if (a == 2) {
      cout << b / 2;
    } else
      cout << b / (a / 2 + 1);
    cout << endl;
  }
}

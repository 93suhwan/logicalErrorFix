#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    for (int j = 0; j < i; j++) {
      s += "(";
    }
    for (int j = 0; j < i; j++) {
      s += ")";
    }
    for (int j = 0; j < (2 * n - 2 * i); j += 2) {
      s += "()";
    }
    cout << s << endl;
  }
  return 0;
}

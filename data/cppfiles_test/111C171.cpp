#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void func(string s, int i) {
  for (int j = 0; j < i; j++) cout << s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int k = 2 * n;
      func("(", i);
      func(")", i);
      k = k - (2 * i);
      func("()", k / 2);
      cout << endl;
    }
  }
  return 0;
}

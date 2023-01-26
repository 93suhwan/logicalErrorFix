#include <bits/stdc++.h>
using namespace std;
void test() {
  string s;
  cin >> s;
  if (s.length() % 2 == 1) {
    cout << "NO" << endl;
  } else {
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[i + s.length() / 2]) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    test();
  }
}

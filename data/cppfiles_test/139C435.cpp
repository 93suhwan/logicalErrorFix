#include <bits/stdc++.h>
using namespace std;
void work() {
  string s;
  cin >> s;
  if (s.size() % 2 == 1) {
    cout << "NO"
         << "\n";
    return;
  } else {
    int f = 0;
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[i + len / 2]) {
        f = 1;
      }
    }
    if (f) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << " \n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    work();
  }
}

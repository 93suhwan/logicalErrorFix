#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string aba;
    cin >> aba;
    if (aba[0] != aba[aba.size() - 1]) {
      char first = aba[0];
      char last = aba[1];
      int compare[2] = {};
      for (int i = 0; i < aba.size(); i++) {
        if (aba[i] == last) {
          compare[0] = i + 1;
          break;
        }
      }
      for (int i = aba.size() - 1; i >= 0; i--) {
        if (aba[i] == first) {
          compare[1] = aba.size() - i;
          break;
        }
      }
      int foo;
      foo = min(compare[0], compare[1]);
      if (foo == compare[0]) {
        for (int i = 0; i < foo; i++) {
          aba[i] = last;
        }
      } else {
        for (int i = aba.size() - 1; i >= 0; i++) {
          aba[i] = first;
        }
      }
    }
    for (auto a : aba) {
      cout << a;
    }
    cout << '\n';
  }
}

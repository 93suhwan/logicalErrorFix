#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string aba;
    cin >> aba;
    int ab = 0;
    int ba = 0;
    if (aba[0] != aba[aba.size() - 1]) {
      aba[0] = aba[aba.size() - 1];
      for (int i = 0; i < aba.size() - 1; i++) {
        if (aba[i] == 'a' && aba[i + 1] == 'b') {
          ab += 1;
        } else if (aba[i] == 'b' && aba[i + 1] == 'a') {
          ba += 1;
        }
      }
      if (ab == ba) {
        for (char c : aba) {
          cout << c;
        }
      } else {
        aba[aba.size() - 1] = aba[0];
        for (char c : aba) {
          cout << c;
        }
      }
    } else {
      for (char c : aba) {
        cout << c;
      }
    }
    cout << '\n';
  }
}

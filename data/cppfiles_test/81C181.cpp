#include <bits/stdc++.h>
using namespace std;
template <typename Head>
inline void dout(Head in) {
  cerr << in << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) {
      if (i % 2 == 1) {
        if (s[i] == '+') {
          s[i] = '-';
        } else {
          s[i] = '+';
        }
      }
      ps[i + 1] = ps[i] + (s[i] == '+' ? 1 : -1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if ((r - l + 1) & 1) {
        cout << 1 << "\n";
      } else {
        if (ps[r] - ps[l - 1] == 0) {
          cout << 0 << "\n";
        } else {
          cout << 2 << "\n";
        }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> out(n + 1, 0);
  int fr, to;
  int ans = n;
  for (int i = 0; i < m; ++i) {
    cin >> fr >> to;
    if (fr > to) {
      fr = to;
    }
    if (!out[fr]++) {
      --ans;
    }
  }
  int t, q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> t;
    if (t == 3) {
      cout << ans << '\n';
    } else {
      cin >> fr >> to;
      if (fr > to) {
        fr = to;
      }
      if (t == 1) {
        if (!out[fr]++) {
          --ans;
        }
      } else {
        if (!--out[fr]) {
          ++ans;
        }
      }
    }
  }
  return 0;
}

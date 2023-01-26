#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  int res = 0;
  for (int kt = 0;; kt += 25) {
    string ta = to_string(kt);
    if (((int)((ta).size())) < ((int)((s).size()))) {
      continue;
    }
    if (((int)((ta).size())) > ((int)((s).size()))) {
      break;
    }
    int onX = -1;
    bool bad = false;
    for (int i = (0); i < (((int)((s).size()))); ++i) {
      if (s[i] == 'X') {
        if (onX == -1) {
          onX = ta[i];
        } else {
          if (ta[i] != onX) {
            bad = true;
            break;
          } else {
          }
        }
      } else if (s[i] == '_') {
      } else {
        if (s[i] != ta[i]) {
          bad = true;
          break;
        }
      }
    }
    if (bad) {
      continue;
    }
    ++res;
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}

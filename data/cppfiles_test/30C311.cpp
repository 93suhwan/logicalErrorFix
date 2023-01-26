#include <bits/stdc++.h>
using namespace std;
int t, n, q;
string s;
void solve() {
  int mim = 1000000000;
  for (int i = 'a'; i <= 'z'; i++) {
    int er = 0;
    int le = 0, ri = n - 1;
    bool flg = 1;
    while (le < ri && flg) {
      if (s[le] == s[ri]) {
        le++, ri--;
      } else {
        if (s[le] == i) {
          while (s[le] == i) le++, er++;
        } else if (s[ri] == i) {
          while (s[ri] == i) ri--, er++;
        } else {
          flg = 0;
        }
      }
    }
    if (flg) mim = min(mim, er);
  }
  cout << (mim == 1000000000 ? -1 : mim) << "\n";
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> pos(n, 0), neg(n, 0);
  char ch = '+';
  for (int i = 0; i < n; i++) {
    if (ch == '+' and s[i] == '-') {
      neg[i] = 1;
    } else if (ch == '-' and s[i] == '-') {
      pos[i] = 1;
    } else if (ch == '+' and s[i] == '+') {
      pos[i] = 1;
    } else if (ch == '-' and s[i] == '+') {
      neg[i] = 1;
    }
    ch = (ch == '+' ? '-' : '+');
  }
  for (int i = 1; i < n; i++) {
    pos[i] += pos[i - 1];
    neg[i] += neg[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l == r) {
      cout << 1 << endl;
    } else if ((r - l + 1) % 2 == 1) {
      cout << 1 << endl;
    } else {
      int x = pos[r] - (l - 1 >= 0 ? pos[l - 1] : 0);
      int y = neg[r] - (l - 1 >= 0 ? neg[l - 1] : 0);
      int dif = abs(x - y);
      if (dif == 0) {
        cout << 0 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

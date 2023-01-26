#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 998244353, INF = 1e9 + 7;
const long long BIG = 1e18;
const int block = 316;
const int base = 1000000000;
const int base_digits = 9;
const int tox[] = {0, 0, 1, -1}, toy[] = {1, -1, 0, 0};
string a, s;
void solve() {
  cin >> a >> s;
  string b = "";
  int ptr = (int)s.size() - 1;
  reverse(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    int cur = a[i] - '0';
    int num = s[ptr] - '0';
    if (num < cur) {
      ptr--;
      if (ptr < 0) {
        cout << -1 << endl;
        return;
      }
      num = num + (s[ptr] - '0') * 10;
    }
    if (num - cur >= 10) {
      cout << -1 << endl;
      return;
    }
    b.push_back(num - cur + '0');
    ptr--;
  }
  while (ptr >= 0) {
    b.push_back(s[ptr]);
    ptr--;
  }
  while (b.size() > 1 and b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  cout << b << endl;
}
void clear() {}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
    clear();
  }
}

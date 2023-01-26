#include <bits/stdc++.h>
using namespace std;
void SolveA() {
  int64_t n;
  cin >> n;
  int64_t sum = 1, diff = 2;
  while (!(n & 1)) {
    diff <<= 1;
    n >>= 1;
  }
  sum = n;
  diff--;
  int64_t u = (sum - diff) / 2;
  int64_t v = (sum + diff) / 2;
  cout << u << " " << v << "\n";
}
void SolveC() {
  int n;
  cin >> n;
  string c;
  cin >> c;
  string s;
  cin >> s;
  int cnt = 0, index = -1;
  bool can = false;
  for (int i = 1; i <= n; i++) {
    cnt += s[i - 1] != c[0];
    bool flag = true;
    for (int j = i; j <= n; j += i) {
      flag &= (s[j - 1] == c[0]);
    }
    if (flag) {
      can = true;
      index = i;
    }
  }
  if (cnt == 0) {
    cout << 0 << "\n";
    return;
  }
  if (can) {
    cout << 1 << "\n" << index << "\n";
    return;
  }
  cout << 2 << "\n";
  cout << n << " " << n - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) SolveC();
  return 0;
}

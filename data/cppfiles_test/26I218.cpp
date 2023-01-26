#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e9;
int calc(string s) {
  int a = 0, b = 0, n = s.size();
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      if (s[i] == '1') b++;
    } else {
      if (s[i] == '1') a++;
    }
    if (i % 2 && abs(a - b) > (n - i - 1) / 2) return max(6, i);
  }
  return 10;
}
vector<string> v;
void gen(int p, string t) {
  if (p == t.size()) {
    v.push_back(t);
    return;
  }
  if (t[p] == '?') {
    t[p] = '1';
    gen(p + 1, t);
    t[p] = '0';
    gen(p + 1, t);
  } else
    gen(p + 1, t);
}
int32_t main() {
  ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
  int tst;
  cin >> tst;
  while (tst--) {
    string s;
    cin >> s;
    int n = s.size();
    v.clear();
    gen(0, s);
    int ans = 10;
    for (auto ss : v) {
      ans = min(ans, calc(ss));
    }
    cout << ans << '\n';
  }
  return 0;
}

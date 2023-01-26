#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e9;
int calc(string s) {
  int a = 0, b = 0, n = s.size();
  int am = 5, bm = 5;
  for (int i = 0; i < n; i++) {
    if (i % 2)
      b += (s[i] == '1'), bm--;
    else
      a += (s[i] == '1'), am--;
    if (a > b + bm || b > a + am) return i + 1;
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
    string f;
    cin >> f;
    int n = f.size();
    v.clear();
    gen(0, f);
    int ans = 10;
    for (auto ss : v) {
      ans = min(ans, calc(ss));
    }
    cout << ans << '\n';
  }
  return 0;
}

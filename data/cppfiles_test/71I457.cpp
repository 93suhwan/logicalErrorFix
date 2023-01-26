#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k;
int to_i32(string s) {
  int ret = 0;
  for (char ch : s) ret = ret * 10 + (ch - '0');
  return ret;
}
int get(string l, string r) {
  set<char> s;
  string ret = l;
  for (char ch : l) s.insert(ch);
  if (s.size() > k) return INT_MAX;
  if (r.empty()) return to_i32(ret);
  if (r[0] == '9') return INT_MAX;
  auto it = s.upper_bound(r[0]);
  if (it == s.end()) {
    if (s.size() == k) return INT_MAX;
    s.insert(r[0] + 1);
  }
  ret += *s.upper_bound(r[0]);
  set<char> t = s;
  t.insert('0');
  if (t.size() < k) s = t;
  while (ret.size() < l.size() + r.size()) ret += *s.begin();
  ;
  return to_i32(ret);
}
void solve(int Case) {
  scanf("%d %d", &n, &k);
  string s = to_string(n);
  ;
  int ans = INT_MAX;
  ans = min(ans, get("", s));
  ans = min(ans, get(s, ""));
  for (int i = 1; i <= s.size() - 1; ++i)
    ans = min(ans, get(s.substr(0, i), s.substr(i, s.size() - i)));
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) solve(t);
  return 0;
}

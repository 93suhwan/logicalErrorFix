#include <bits/stdc++.h>
using namespace std;
void _print(int64_t t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void run_case() {
  int64_t n;
  cin >> n;
  vector<string> a(n - 2);
  for (auto &it : a) cin >> it;
  string s;
  s += a[0];
  for (int64_t i = 1; i < n - 2; ++i) {
    if (a[i][0] != a[i - 1][1]) s += a[i][0];
    s += a[i][1];
  }
  while ((int64_t)(s).size() < n) s.push_back('a');
  cout << s << '\n';
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(false);
  int64_t T;
  cin >> T;
  while (T--) {
    run_case();
  }
  return 0;
}

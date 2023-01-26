#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wsign-compare"
int64_t divCeil(int64_t x, int64_t y) { return (x + y - 1) / y; }
vector<int64_t> readVec(int64_t n) {
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) cin >> a[i];
  return a;
}
int64_t M = 1000000007;
bool canBeG(const string& s, char c, int64_t g) {
  for (int64_t i = g - 1; i < s.length(); i += g)
    if (s[i] != c) return false;
  return true;
}
void solve() {
  int64_t n;
  char c;
  string s;
  cin >> n >> c >> s;
  bool cz = true;
  for (char d : s)
    if (d != c) cz = false;
  if (cz) {
    cout << "0\n";
    return;
  }
  for (int64_t g = 2; g <= n; g++) {
    if (canBeG(s, c, g)) {
      cout << "1\n" << g << "\n";
      return;
    }
  }
  cout << "2\n" << (n - 1) << " " << n << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t casesNum = 1;
  cin >> casesNum;
  for (int64_t caseId = 1; caseId <= casesNum; caseId++) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int T, n;
vector<int> v;
map<int, bool> m;
bool check(int a, int b, int c) {
  for (int i = 0; i < v.size(); i++) {
    int val = v[i];
    m.clear();
    for (int A = 0; A <= a; A++) {
      for (int B = 0; B <= b; B++) {
        for (int C = max(val / 3 - 2, 0); C <= min(val / 3, c); C++) {
          m[A + B * 2 + C * 3] = true;
        }
      }
    }
    if (!m[val]) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  v.clear();
  m.clear();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!m[x]) v.push_back(x);
    m[x] = true;
  }
  int ans = 1e9;
  n = v.size();
  sort(v.begin(), v.end());
  for (int a = 0; a <= 2; a++) {
    for (int b = 0; b <= 2; b++) {
      for (int c = max(v.back() / 3 - 2, 0); c <= v.back() / 3; c++) {
        if (check(a, b, c)) {
          ans = min(ans, a + b + c);
        }
      }
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> T;
  while (T--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int N = 2e5 + 5;
int n;
string s[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  int ans = 0;
  for (int k = 0; k < 26; ++k) {
    vector<int> A;
    for (int i = 1; i <= n; ++i) {
      int x = 0;
      for (char c : s[i]) {
        if (c - 'a' == k)
          ++x;
        else
          --x;
      }
      A.emplace_back(x);
    }
    sort(A.begin(), A.end());
    int t = 0, y = 0;
    while (!A.empty() && t + A.back() > 0) {
      t += A.back();
      A.pop_back();
      ++y;
    }
    ans = max(ans, y);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

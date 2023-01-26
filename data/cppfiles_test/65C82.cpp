#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {}
template <typename T>
inline void maxa(T& a, T b) {
  a = max(a, b);
}
template <typename T>
inline void mina(T& a, T b) {
  a = min(a, b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 2e5 + 5;
const int mod = 1e9 + 7;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<char> ans(n);
  for (int& i : a) cin >> i;
  string s;
  cin >> s;
  sort(a.begin(), a.end());
  int cnt = 0;
  for (int i = 1; i < n; i++) cnt += (s[i] != s[i - 1]);
  int l = n - cnt - 1;
  int r = n - cnt - 1;
  cout << a[l] << " " << s[0] << "\n";
  ans[l] = s[0];
  for (int i = 1; i < (int)(s.size()); i++) {
    if (s[i] != s[i - 1]) {
      ans[++r] = ans[r] == 'L' ? 'R' : 'L';
      cout << a[r] << " " << ans[r] << "\n";
    } else {
      ans[--l] = ans[l] == 'L' ? 'R' : 'L';
      cout << a[l] << " " << ans[l] << "\n";
    }
  }
}

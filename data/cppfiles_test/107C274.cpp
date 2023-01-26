#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int inf = 1e9;
const int N = 3e5 + 5;
bool flag;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
void mul(T& a, T b) {
  a += b;
  if (b < (T)0) a += MOD;
  if (a >= (T)MOD) a -= MOD;
}
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 or a + b + 2 > n) {
    cout << -1;
    return;
  }
  if (a == 0 and b == 0) {
    for (int i = 1; i <= n; i++) cout << i << ' ';
    return;
  }
  vector<int> ans;
  int l = 1, r = n;
  if (a > b) {
    ans.push_back(l++);
    for (int i = 1; i <= a + b; i++) {
      if (i % 2)
        ans.push_back(r--);
      else
        ans.push_back(l++);
    }
    for (int i = a + b + 1; i < n; i++) ans.push_back(r--);
  } else {
    ans.push_back(r--);
    for (int i = 1; i <= a + b; i++) {
      if (i % 2 == 0)
        ans.push_back(r--);
      else
        ans.push_back(l++);
    }
    for (int i = a + b + 1; i < n; i++) ans.push_back(a == b ? r-- : l++);
  }
  for (auto now : ans) cout << now << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    flag = 0;
    solve();
    cout << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
const int N = 1010;
int n;
int a[N][6];
int cnt[6];
vector<map<int, int>> st(N);
bool check(int d1, int d2) {
  if (cnt[d1] < n / 2 || cnt[d2] < n / 2) return false;
  if (cnt[d1] < cnt[d2]) swap(d1, d2);
  int dd = cnt[d1] - n / 2;
  if (dd >= n / 2 - st[d2][d1]) return true;
  return false;
}
void solve() {
  cin >> n;
  st.clear();
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
      cnt[j] += a[i][j];
    }
  }
  if (n & 1) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      for (int d = 1; d <= 5; d++) {
        if (i != d) st[j][d] += !a[i][d];
      }
    }
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if (i != j) {
        if (check(i, j)) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

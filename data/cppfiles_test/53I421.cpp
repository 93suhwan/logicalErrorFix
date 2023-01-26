#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, k;
int a[MAX];
vector<int> v[MAX];
void solve() {
  v->clear();
  int t = 0;
  v[t].push_back(a[1]);
  for (int i = 2; i <= n; ++i) {
    if (a[i] >= a[i - 1]) {
      while (1) {
        if (a[i] < a[i - 1])
          break;
        else {
          v[t].push_back(a[i]);
          ++i;
        }
      }
      --i;
    } else {
      ++t;
      v[t].push_back(a[i]);
    }
  }
  if (t + 1 == k)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();
  }
  return 0;
}

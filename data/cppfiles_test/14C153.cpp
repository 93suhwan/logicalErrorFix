#include <bits/stdc++.h>
using namespace std;
int a[55], b[55];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  vector<pair<pair<int, int>, int> > ans;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      for (int j = i + 1; j < n; j++) {
        if (a[j] == b[i]) {
          int num = a[j];
          ans.push_back(make_pair(make_pair(i + 1, j + 1), j - i));
          for (int k = j; k > i; k--) {
            a[k] = a[k - 1];
          }
          a[i] = a[j];
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, d;
  cin >> n >> d;
  int ans = -1;
  vector<int> arr(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  vector<bool> vis(2 * n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vector<int> v;
    {
      int j = i;
      while (j != i || v.empty()) {
        vis[j] = true;
        v.push_back(arr[j]);
        j = (j + d) % n;
      }
    }
    int len = v.size();
    vector<int> p(v);
    for (int j : p) v.push_back(j);
    int cal = 0;
    for (int j = 0; j < len; j++) {
      int k = j;
      int cnt = 0;
      while (k < j + len && v[k] == 1) {
        cnt++;
        k++;
      }
      cal = max(cal, cnt);
      j = k;
    }
    if (cal == len) {
      cout << "-1\n";
      return;
    }
    ans = max(ans, cal);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

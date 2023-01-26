#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n), ids;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n;) {
    int r = i;
    while (r < n && arr[r] == arr[i]) r++;
    if (arr[i] == 1) {
      int len = r - i;
      if (len & 1) {
        cout << "NO\n";
        return;
      }
      if (i - 1 >= 0 && arr[i - 1] == 0) {
        for (int j = i - 1; j < r - 2; j += 2) ids.push_back(j);
      } else if (r < n && arr[r] == 0) {
        for (int j = r - 2; j >= i; j -= 2) ids.push_back(j);
      }
      for (int j = i; j < r; j++) arr[j] = 0;
    }
    i = r;
  }
  cout << "YES\n";
  if (ids.empty()) {
    cout << "0\n";
    return;
  }
  cout << (int)ids.size() << "\n";
  for (int id : ids) cout << id + 1 << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}

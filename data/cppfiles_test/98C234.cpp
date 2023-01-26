#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a = {0};
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a.push_back(a[a.size() - 1] + (c == 'a' ? 1 : -1));
  }
  for (int i = 0; i < a.size(); ++i) {
    for (int j = i + 1; j < a.size(); ++j)
      if (a[j] == a[i]) {
        cout << i + 1 << " " << j << "\n";
        return;
      }
  }
  cout << "-1 -1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

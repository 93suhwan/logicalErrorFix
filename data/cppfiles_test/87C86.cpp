#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m - 1; i++)
      for (int j = i + 1; j < m; j++)
        if (a[i] < a[j]) ans++;
    cout << ans << "\n";
  }
  return 0;
}

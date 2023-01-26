#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int n, cnt, cnt1, i;
  string a, b;
  bool ok;
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    cnt = ok = cnt1 = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != b[i]) cnt++;
      if (a[i] == '1') ok = true;
    }
    if (ok || cnt == 0) {
      reverse(b.begin(), b.end());
      for (i = 0; i < n; i++)
        if (a[i] != b[i]) cnt1++;
      cout << min(min(cnt, n - cnt), min(cnt1, n - cnt1)) << '\n';
    } else
      cout << -1 << '\n';
  }
}

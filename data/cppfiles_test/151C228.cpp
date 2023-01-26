#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5;
int repl[MAX + 1];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  for (int i = 0; i <= MAX; i++) repl[i] = i;
  int q, n = 0;
  cin >> q;
  pair<int, int> qq[q];
  for (int i = 0; i < q; i++) {
    int t, x, y = 0;
    cin >> t >> x;
    if (t == 1)
      n++;
    else
      cin >> y;
    qq[i] = {x, y};
  }
  int ans[n], j = n;
  for (int i = q - 1; i >= 0; i--) {
    if (qq[i].second)
      repl[qq[i].first] = repl[qq[i].second];
    else
      ans[--j] = repl[qq[i].first];
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}

#include <bits/stdc++.h>
using namespace std;
void t_main() {
  int n, diff = 1;
  cin >> n;
  vector<string> st(n - 2);
  cin >> st[0];
  if (n == 3) {
    cout << 'b' << st[0];
    return;
  }
  for (int i = 1; i < n - 2; i++) {
    cin >> st[i];
    if (st[i - 1][1] != st[i][0]) diff = i;
  }
  for (int i = 0; i < n - 2; i++) {
    if (i == diff) cout << st[i - 1][1];
    cout << st[i][0];
  }
  cout << st[n - 3][1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    t_main();
    cout << '\n';
  }
  return 0;
}

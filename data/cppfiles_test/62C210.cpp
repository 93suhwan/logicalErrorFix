#include <bits/stdc++.h>
using namespace std;
using namespace std;
void solve() {
  int n, i;
  cin >> n;
  vector<int> roads(n);
  for (i = 0; i < n; i++) cin >> roads[i];
  if (roads[0] == 1) {
    cout << n + 1;
    for (i = 0; i < n; i++) cout << " " << i + 1;
    cout << endl;
    return;
  }
  if (roads[n - 1] == 0) {
    for (i = 0; i < n; i++) cout << i + 1 << " ";
    cout << n + 1 << endl;
    return;
  }
  int leave = -1;
  for (i = 0; i < n - 1; i++) {
    if (roads[i] == 0 and roads[i + 1] == 1) {
      leave = i + 1;
      break;
    }
  }
  if (leave == -1) {
    cout << "-1\n";
    return;
  }
  for (i = 0; i < leave; i++) cout << i + 1 << " ";
  cout << n + 1;
  for (i = leave; i < n; i++) cout << " " << i + 1;
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int temp;
  int pos = -1;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << n << " ";
    }
    cout << i << endl;
    cin >> temp;
    if (temp == 0) {
      continue;
    } else {
      pos = temp;
      ans[temp] = 1;
      break;
    }
  }
  if (pos == -1) {
    pos = n;
    ans[pos] = 1;
  }
  for (int i = 2; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j <= n; j++) {
      if (j == pos) {
        cout << i << " ";
      } else {
        cout << "1 ";
      }
    }
    cout << endl;
    cin >> temp;
    ans[temp] = i;
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}

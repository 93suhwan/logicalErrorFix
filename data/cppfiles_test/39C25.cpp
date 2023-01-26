#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
void hope() {
  int n;
  cin >> n;
  vector<int> next(n + 1), pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j <= n; j++)
      if (j == i)
        cout << "2 ";
      else
        cout << "1 ";
    cout << "\n";
    int k;
    cin >> k;
    if (k != 0 and k != i) {
      next[i] = k;
      pre[k] = i;
    }
    fflush(stdout);
  }
  for (int i = 1; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j <= n; j++)
      if (j == i)
        cout << "1 ";
      else
        cout << "2 ";
    cout << "\n";
    int k;
    cin >> k;
    if (k != 0 and k != i) {
      next[k] = i;
      pre[i] = k;
    }
    fflush(stdout);
  }
  int ind = 1;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (pre[i] == 0) {
      while (i != 0) {
        ans[i] = ind++;
        i = next[i];
      }
      break;
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    hope();
  }
  return 0;
}

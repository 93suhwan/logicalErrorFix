#include <bits/stdc++.h>
using namespace std;
int n, jxt, tmp = 1, gb[105], ans[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = n; i > 1; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << i << " ";
    }
    cout << 1 << endl;
    fflush(stdout);
    cin >> jxt;
    if (jxt > 0) {
      gb[tmp] = jxt;
      tmp++;
    }
  }
  if (tmp == 1 || tmp == n) {
    gb[tmp] = n;
  }
  if (tmp == n) {
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      ans[gb[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
  }
  gb[tmp] = n;
  tmp++;
  for (int i = n - 1; i >= 1; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << i << " ";
    }
    cout << n << endl;
    fflush(stdout);
    cin >> jxt;
    if (jxt > 0) {
      ans[tmp] = jxt;
      tmp++;
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    ans[gb[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

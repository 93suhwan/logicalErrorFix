#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
int arr[N];
int n;
void solve() {
  cin >> n;
  if (n == 1) {
    cin >> arr[0];
    if (arr[0] == 1)
      cout << 2 << " " << 1 << endl;
    else
      cout << 1 << " " << 2 << endl;
    return;
  }
  int flag = 0;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      a = arr[0];
    else if (a != arr[i])
      flag = 1;
  }
  if (flag == 0) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (arr[0] == 1) {
        cout << n + 1 << " ";
        for (int j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        return;
      }
    } else {
      int from;
      if (arr[i - 1] == 0 && arr[i] == 1) {
        from = i;
        for (int j = 1; j <= n; j++) {
          if (j == from) {
            cout << j << " " << n + 1 << " " << j + 1 << " ";
            j = j + 1;
          } else
            cout << j << " ";
        }
        cout << endl;
        return;
      }
    }
  }
  if (arr[n - 1] == 1) {
    for (int j = 1; j <= n; j++) cout << j << " ";
    cout << n + 1 << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

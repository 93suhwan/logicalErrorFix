#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
int arr[N];
int n;
int val;
void solve() {
  cin >> n;
  int a;
  int from, to, mid;
  int flag = 0;
  if (n == 1) {
    cin >> a;
    if (a == 1) {
      cout << 2 << " " << 1 << endl;
    } else {
      cout << 1 << " " << 2 << endl;
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      a = arr[i];
      if (arr[i] == 0) {
        mid = n + 1;
        from = i + 1;
      } else {
        mid = n + 1;
        to = i + 1;
      }
      continue;
    }
    if (a != arr[i] && flag == 0) {
      flag = 1;
      if (arr[i] == 1) {
        to = i + 1;
      } else {
        from = i + 1;
      }
    }
  }
  if (flag == 0) {
    cout << -1 << endl;
    return;
  }
  cout << from << " " << mid << " " << to << " ";
  for (int i = 1; i <= n; i++) {
    if (i != to && i != from) cout << i << " ";
  }
  cout << endl;
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

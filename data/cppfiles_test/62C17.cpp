#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 7;
int a[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    if (a[1] == 0) {
      cout << 1 << " " << 2 << "\n";
    } else {
      cout << 2 << " " << 1 << "\n";
    }
    return;
  }
  if (a[n] == 0) {
    for (int i = 1; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  int dex = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0 && a[i + 1] != 0) {
      dex = i;
    }
  }
  if (dex != -1) {
    for (int i = 1; i <= dex; i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (int i = dex + 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    if (a[1] != 0) {
      cout << n + 1 << " ";
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

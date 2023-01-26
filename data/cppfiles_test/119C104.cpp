#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum % n == 0) {
    cout << 0 << "\n";
  } else {
    cout << 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) solve();
}

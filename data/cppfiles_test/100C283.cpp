#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    return;
  }
  sort(a, a + n);
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (max < (a[i] - a[i - 1])) {
      max = a[i] - a[i - 1];
    }
  }
  cout << max << endl;
}

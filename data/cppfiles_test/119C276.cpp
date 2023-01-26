#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  long long avg = sum / n;
  sort(a, a + n);
  if (sum % n == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    return;
  }
  sort(a, a + n);
  if (n == 2) {
    cout << max(min(a[0], a[1]), a[1] - a[0]) << endl;
    return;
  }
  long long largest = a[n - 1], secondlargest = a[n - 2], third = a[n - 3];
  largest -= third;
  secondlargest -= third;
  cout << max(min(largest, secondlargest), largest - secondlargest) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

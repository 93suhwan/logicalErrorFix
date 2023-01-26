#include <bits/stdc++.h>
using namespace std;
bool issorted(long long arr[], int n) {
  if (n == 1) return true;
  return (arr[0] < arr[1] and issorted(arr + 1, n - 1));
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n], sum = 0;
  k++;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = powl(10LL, a[i]);
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    long long tmp = k;
    k -= ((a[i] / a[i - 1]) - 1);
    if (k >= 0) {
      sum += ((a[i] / a[i - 1]) - 1) * a[i - 1];
    } else {
      sum += a[i - 1] * tmp;
      break;
    }
  }
  if (k >= 0) {
    sum += a[n - 1] * k;
  }
  cout << sum << '\n';
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

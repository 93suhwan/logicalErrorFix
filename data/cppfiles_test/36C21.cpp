#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void go() {
  long long int n, sum = 0;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (isprime(sum) == false) {
    cout << n << "\n";
    for (long long int i = 0; i < n; i++) cout << i + 1 << " ";
    cout << "\n";
    return;
  }
  long long int t = 0;
  for (long long int i = 0; i < n; i++) {
    if (isprime(sum - a[i]) == false) {
      t = i;
      break;
    }
  }
  cout << n - 1 << "\n";
  for (long long int j = 0; j < n; j++) {
    if (j != t) cout << j + 1 << " ";
  }
  cout << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}

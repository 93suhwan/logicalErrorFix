#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<long long> a(n + 1, 0);
    long long odd = -1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] & 1) odd = i;
    }
    if (isPrime(sum)) {
      cout << n - 1 << endl;
      for (int i = 1; i <= n; i++) {
        if (i == odd) continue;
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

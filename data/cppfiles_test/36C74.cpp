#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = 0;
    long long int odd = 0;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      sum += x;
      if (x % 2) odd = i;
    }
    if (!isPrime(sum)) {
      cout << n << "\n";
      for (long long int i = 0; i < n; i++) cout << (i + 1) << " ";
    } else {
      cout << (n - 1) << "\n";
      for (long long int i = 0; i < n; i++)
        if (i != odd) cout << (i + 1) << " ";
    }
    cout << "\n";
  }
  return 0;
}

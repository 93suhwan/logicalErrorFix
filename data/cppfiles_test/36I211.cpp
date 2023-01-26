#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
void mix() {
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  int k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum = sum + a[i];
    if (a[i] % 2 != 0) {
      k = i;
    }
  }
  if (sum % 2 == 0) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
  } else {
    if (isprime(sum)) {
      cout << n - 1 << endl;
      for (int i = 0; i < n; i++) {
        if (i != k) {
          cout << a[i] << " ";
        }
      }
    } else {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
      }
    }
  }
  cout << endl;
}
signed main() {
  int t;
  cin >> t;
  for (int i1 = 0; i1 < t; i1++) {
    mix();
  }
}

#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b != 0) {
    long long int c = a % b;
    a = b;
    b = c;
  }
  return a;
}
bool is_Prime(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  long long int largest = b[n - 1];
  long long int second_largest = b[n - 2];
  long long int k = 1, current = a[n - 1];
  if (current == largest) {
    cout << 0 << endl;
    return;
  }
  for (long long int i = n - 2; i >= 0; i--) {
    if (a[i] > current) {
      if (a[i] == largest) {
        cout << k << endl;
        return;
      } else if (a[i] == second_largest) {
        cout << k + 1 << endl;
        return;
      } else {
        current = a[i];
        k++;
      }
    }
  }
  cout << k << endl;
}
void testcase() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  testcase();
}

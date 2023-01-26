#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int pow_mod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
long long int inv_mod(long long int a) { return pow_mod(a, mod - 2); }
void input(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cin >> a[i];
}
void output(long long int a[], long long int n, bool spaces = true) {
  for (long long int i = 0; i < n; i++) {
    cout << a[i];
    if (!spaces)
      cout << "\n";
    else
      cout << " ";
  }
  if (spaces) cout << endl;
}
long long int n;
void add(long long int &ptr) {
  ptr = (ptr + 1) % n;
  if (ptr == 0) ptr = n;
}
void solve() {
  long long int m, k;
  cin >> n >> m >> k;
  long long int big = n % m;
  long long int small = m - big;
  long long int ptr = 1;
  long long int main_ptr = 1;
  for (long long int i = 0; i < k; i++) {
    vector<long long int> v[m];
    main_ptr = ptr;
    for (long long int i = 1; i <= big; i++) {
      cout << (n + m - 1) / m << " ";
      for (long long int j = 1; j <= (n + m - 1) / m; j++) {
        cout << main_ptr << " ";
        add(main_ptr);
      }
      cout << endl;
    }
    ptr = main_ptr;
    for (long long int i = big + 1; i <= m; i++) {
      cout << (n / m) << " ";
      for (long long int j = 1; j <= n / m; j++) {
        cout << main_ptr << " ";
        add(main_ptr);
      }
      cout << endl;
    }
  }
  cout << endl;
}
int main() {
  long long int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

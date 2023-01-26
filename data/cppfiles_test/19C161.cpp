#include <bits/stdc++.h>
using namespace std;
set<long long> s;
bool contain_zero = false;
void sumsubset(long long a[], long long l, long long r, long long sum = 0) {
  if (l > r) {
    s.insert(sum);
    return;
  }
  sumsubset(a, l + 1, r, sum + a[l]);
  sumsubset(a, l + 1, r, sum);
}
void solve() {
  long long n;
  bool possible = false;
  cin >> n;
  long long a[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) contain_zero = true;
  }
  sumsubset(a, 0, n - 1);
  long long x = pow(2, n);
  if (contain_zero || s.size() < x)
    cout << "YES\n";
  else
    cout << "NO\n";
  s.clear();
  contain_zero = false;
}
int main() {
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
}

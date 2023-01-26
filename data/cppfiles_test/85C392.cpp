#include <bits/stdc++.h>
using namespace std;
void invector(vector<long long> p) {
  cout << " in p : ";
  for (auto x : p) {
    cout << x << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void in(long long n) { cout << n << "\n"; }
void solve() {
  string a;
  cin >> a;
  long long n = a.size();
  long long dem = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0') {
      dem++;
      while (i < n && a[i] == '0') i++;
      i--;
    }
  }
  if (dem >= 2)
    cout << 2 << "\n";
  else {
    if (dem == 0)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
}
signed main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

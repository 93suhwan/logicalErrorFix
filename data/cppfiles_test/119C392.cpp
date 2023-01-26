#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long NINF = -1 * 1e18;
void display(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
long long sum(vector<long long> &v) {
  int n = v.size();
  long long sum = 0;
  for (long long i = (0); i < (n); ++i) {
    sum += v[i];
  }
  return sum;
}
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
long long fast_power(long long x, long long p) {
  long long re = 1;
  while (p) {
    if (p & 1) re = re * x;
    x = x * x;
    p >>= 1;
  }
  return re;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    ;
    if (sum(a) % n == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}

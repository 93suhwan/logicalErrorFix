#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
void prin(long long int a, long long int b, long long int c,
          long long int maxi) {
  if (a == max(b, c))
    cout << "1 ";
  else if (a == maxi)
    cout << "0 ";
  else
    cout << max(b, c) - a + 1 << " ";
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < (n); i++) cin >> a[i];
  int flag = 1;
  long long int egcd = a[0], ogcd = a[1];
  for (long long int i = 0; i < (n); i++) {
    if (i % 2 == 0) {
      egcd = gcd(egcd, a[i]);
    } else
      ogcd = gcd(ogcd, a[i]);
  }
  if (ogcd == egcd) {
    cout << 0 << endl;
    return;
  }
  long long int mgcd = max(egcd, ogcd) / gcd(egcd, ogcd);
  for (long long int i = 0; i < (n - 1); i++) {
    if (a[i] % mgcd == 0 && a[i + 1] % mgcd == 0) {
      cout << 0 << endl;
      return;
    }
  }
  cout << mgcd << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, x;
  cin >> t;
  while (t--) {
    solve();
  }
}

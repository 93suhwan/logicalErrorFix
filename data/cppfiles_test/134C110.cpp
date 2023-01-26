#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long g1 = a[0];
    for (int i = 2; i < n; i += 2) {
      g1 = gcd(g1, a[i]);
    }
    int c = 1;
    for (int i = 1; i < n; i += 2) {
      if (a[i] % g1 == 0) {
        c = 0;
        break;
      }
    }
    if (c) {
      cout << g1 << endl;
      continue;
    }
    long long g2 = a[1];
    c = 1;
    for (int i = 3; i < n; i += 2) {
      g2 = gcd(g2, a[i]);
    }
    for (int i = 0; i < n; i += 2) {
      if (a[i] % g2 == 0) {
        c = 0;
        break;
      }
    }
    if (c) {
      cout << g2 << endl;
      continue;
    }
    cout << "0\n";
  }
}

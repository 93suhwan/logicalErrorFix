#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n];
    long long g1 = 0, g2 = 0;
    int s1[n];
    int s2[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        g1 = gcd(g1, arr[i]);
      } else
        g2 = gcd(g2, arr[i]);
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] % g1 == 0)
        s1[i] = 1;
      else
        s1[i] = 0;
      if (arr[i] % g2 == 0)
        s2[i] = 1;
      else
        s2[i] = 0;
    }
    bool ok1 = true;
    bool ok2 = true;
    for (int i = 0; i < n - 1; i++) {
      if (s1[i] == s1[i + 1]) ok1 = false;
      if (s2[i] == s2[i + 1]) ok2 = false;
    }
    if (ok1)
      cout << g1 << '\n';
    else if (ok2)
      cout << g2 << '\n';
    else
      cout << "0\n";
  }
}

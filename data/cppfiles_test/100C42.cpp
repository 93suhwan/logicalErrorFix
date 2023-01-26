#include <bits/stdc++.h>
using namespace std;
long long int m = 998244353;
struct hey {
  long long int x, y, g;
};
struct hey inv1(long long int a, long long int b) {
  if (b == 0) {
    struct hey ans;
    ans.g = a;
    ans.y = 0;
    ans.x = 1;
    return ans;
  } else {
    struct hey p = inv1(b, a % b);
    struct hey ans;
    ans.g = p.g;
    ans.x = p.y;
    ans.y = p.x - ((a / b) * (p.y));
    return ans;
  }
}
long long int inv(long long int b) {
  struct hey ans = inv1(b, m);
  return ((ans.x) + m) % m;
}
long long int bin(long long int a, long long int b, long long int fact[]) {
  if (b < 0 || a < 0) return 0;
  return (((fact[a] * inv(fact[b])) % m * inv(fact[a - b])) % m + m) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, n1 = 2e5, c, d, ans;
  long long int fact[n1 + 1];
  fact[0] = 1;
  for (long long int i = 1; i <= n1; i++) {
    fact[i] = (i * fact[i - 1]) % m;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] > (a[n - 2] + 1)) {
      cout << "0\n";
      continue;
    }
    if (a[n - 1] == a[n - 2]) {
      cout << (fact[n]) << "\n";
      continue;
    }
    c = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == (a[n - 2])) c++;
    }
    ans = fact[n];
    for (int i = 0; i < n; i++) {
      if (i < c) continue;
      d = ((((bin(i, c, fact) * fact[c])) % m) * fact[n - c - 1]) % m;
      ans = (ans - d) % m;
      if (ans < 0) {
        ans = ans + m;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long int modpower(long long int b, long long int e, long long int q) {
  long long int MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long int> v) {
  for (long long int i = 0; i < (v.empty() ? 0 : v.size()); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
long long int ceil1(long long int x, long long int y) {
  long long int r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
void fuck() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[n - 1] == '0') {
    cout << 1 << " " << n << " " << 1 << " " << n - 1 << "\n";
    return;
  } else {
    long long int st = 0;
    long long int end = n - 1;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '0') {
        long long int len1 = i + 1;
        long long int len2 = (end - i + 1);
        if (len1 > (n / 2)) {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
          return;
        } else {
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
          return;
        }
      }
    }
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
    return;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    fuck();
  }
  return 0;
}

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
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a;
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    m[x]++;
    a.push_back(x);
  }
  long long int ans = 0;
  sort(a.begin(), a.end());
  long long int j = lower_bound(a.begin(), a.end(), 0) - a.begin();
  for (long long int i = j; i < n; i++) {
    long long int k1 = k;
    long long int f = i;
    long long int cur = a[f];
    while (k1) {
      if (f + 1 < n and a[f] == a[f + 1]) {
        cur = a[f];
        f++;
        k1--;
      } else if (f + 1 < n and a[f] != a[f + 1]) {
        if (k1 == 1) {
          cur = a[f];
          break;
        } else {
          if (k1 - 1 >= m[a[f + 1]]) {
            cur = a[f + 1];
            f++;
            k1--;
          } else {
            break;
          }
        }
      } else {
        cur = a[f];
        k1--;
        break;
      }
    }
    i = f;
    ans += 2 * cur;
  }
  for (long long int i = j - 1; i >= 0; i--) {
    long long int k1 = k;
    long long int f = i;
    long long int cur = a[f];
    while (k1) {
      if (f + 1 < n and a[f] == a[f + 1]) {
        cur = a[f];
        f--;
        k1--;
      } else if (f + 1 < n and a[f] != a[f + 1]) {
        if (k1 == 1) {
          cur = a[f];
          break;
        } else {
          if (k1 - 1 >= m[a[f + 1]]) {
            cur = a[f + 1];
            f--;
            k1--;
          } else {
            break;
          }
        }
      } else {
        cur = a[f];
        k1--;
        break;
      }
    }
    i = f;
    ans += 2 * abs(cur);
  }
  cout << ans - max(abs(a[0]), abs(a[(a.empty() ? 0 : a.size()) - 1])) << "\n";
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

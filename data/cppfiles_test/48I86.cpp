#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
map<pair<long long, long long>, long long> pos;
void P(long long i, long long j, long long k,
       vector<pair<long long, long long>>& a) {
  pair<long long, long long> t = a[k];
  a[k] = a[j];
  a[j] = a[i];
  a[i] = t;
  pos[a[i]] = i;
  pos[a[j]] = j;
  pos[a[k]] = k;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a;
    map<long long, long long> now;
    for (long long i = 0; i < n; i++) {
      long long b;
      cin >> b;
      a.push_back({b, now[b]++});
    }
    vector<pair<long long, long long>> b = a;
    sort(b.begin(), b.end());
    for (long long i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    bool f = false;
    for (long long i = 0; i < n; i++) {
      if (a[i] == b[i]) continue;
      if (pos[b[i]] != i + 1) {
        P(i, i + 1, pos[b[i]], a);
      } else {
        if (i + 1 == n - 1) {
          if (a[i].first == a[i + 1].first) break;
          if (a[i + 1].second) {
            P(i, i + 1, pos[{a[i + 1].first, a[i + 1].second - 1}], a);
            break;
          }
          f = true;
          break;
        }
        P(i, i + 2, pos[b[i]], a);
      }
    }
    if (f)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}

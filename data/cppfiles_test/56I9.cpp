#include <bits/stdc++.h>
using namespace std;
map<long long, int> mp;
long long n, k;
map<long long, int> done;
long long bigmod(long long x, long long p) {
  if (p == 0) return 1LL;
  long long y = bigmod(x, p / 2);
  if (p % 2 == 1) {
    return ((((y % 1000000007) * (y % 1000000007)) % 1000000007) *
            (x % 1000000007)) %
           1000000007;
  }
  return (y % 1000000007) * (y % 1000000007) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> k >> n;
  while (n--) {
    long long x;
    string color;
    cin >> x >> color;
    if (color[0] == 'w' || color[0] == 'y') mp[x] = 1;
    if (color[0] == 'g' || color[0] == 'b') mp[x] = 2;
    if (color[0] == 'r' || color[0] == 'o') mp[x] = 3;
    done[x] = 1;
  }
  long long ans = 1;
  long long node = (1LL << k) - 1;
  for (auto i : mp) {
    for (auto j : mp) {
      long long u = i.first, v = j.first;
      long long x1 = i.second, x2 = j.second;
      if (u == v) continue;
      if (u > v) {
        swap(u, v);
        swap(x1, x2);
      }
      long long pu = u / 2;
      long long pv = v / 2;
      if (pv == u) {
        if (x1 == x2) {
          cout << 0 << endl;
          return 0;
        }
        continue;
      }
      if (pu == pv) {
        if (mp[pu] == mp[u] || mp[pv] == mp[v]) {
          cout << 0 << endl;
          return 0;
        }
        if (done[pu]) continue;
        long long pp = pu / 2;
        if (mp[pp]) {
          int x3 = mp[pp];
          if (x1 == x2 && x2 == x3 && x3 == x1)
            ans *= 4;
          else if (x1 != x2 && x2 != x3 && x3 != x1) {
            cout << 0 << endl;
            return 0;
          } else
            ans *= 2;
          ans %= 1000000007;
          done[pu] = 1;
        } else {
          if (x1 == x2) {
            ans *= 4LL;
            ans %= 1000000007;
            done[pu] = 1;
          } else {
            ans *= 2LL;
            ans %= 1000000007;
            done[pu] = 1;
          }
        }
        continue;
      }
      long long pp = pv / 2;
      if (pp == u) {
        if (mp[pv] == mp[v] || mp[pv] == mp[u]) {
          cout << 0 << endl;
          return 0;
        }
        if (done[pv]) continue;
        long long child = pv * 2;
        if (child == v) child++;
        if (mp[child]) {
          int x3 = mp[child];
          if (x1 == x2 && x2 == x3 && x3 == x1)
            ans *= 4;
          else if (x1 != x2 && x2 != x3 && x3 != x1) {
            cout << 0 << endl;
            return 0;
          } else
            ans *= 2;
          ans %= 1000000007;
          done[pv] = 1;
        } else {
          if (x1 == x2) {
            ans *= 4LL;
            ans %= 1000000007;
            done[pv] = 1;
          } else {
            ans *= 2LL;
            ans %= 1000000007;
            done[pv] = 1;
          }
        }
      }
    }
  }
  for (auto i : done) {
    if (i.second) node--;
  }
  if (done[1]) {
    ans *= bigmod(4, node);
    ans %= 1000000007;
  } else {
    ans *= bigmod(4, node - 1);
    ans %= 1000000007;
    if (mp[2] || mp[3])
      ans *= 4;
    else
      ans *= 6;
    ans %= 1000000007;
  }
  cout << ans << endl;
}

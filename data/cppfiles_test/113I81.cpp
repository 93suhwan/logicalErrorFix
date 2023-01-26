#include <bits/stdc++.h>
using namespace std;
long long powMod(long long x, long long y) {
  long long p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % ((long long)1e9 + 7);
    }
    y /= 2;
    x = (x * x) % ((long long)1e9 + 7);
  }
  return p;
}
long long CpowMod(long long x, long long y, long long w) {
  long long p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % w;
    }
    y /= 2;
    x = (x * x) % w;
  }
  return p;
}
long long invMod(long long x) { return powMod(x, ((long long)1e9 + 7) - 2); }
long long CinvMod(long long x, long long w) { return CpowMod(x, w - 2, w); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  int n;
  cin >> n;
  vector<long long> hero(n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> hero[i];
    total += hero[i];
  }
  int m;
  cin >> m;
  vector<pair<long long, long long>> dragon(m);
  for (int i = 0; i < m; i++) {
    cin >> dragon[i].first >> dragon[i].second;
  }
  long long x, y;
  sort(begin(hero), end(hero));
  for (int i = 0; i < m; i++) {
    x = dragon[i].first;
    y = dragon[i].second;
    int l = lower_bound(begin(hero), end(hero), x) - hero.begin();
    long long coin = 0;
    if (l == 0) {
      if (hero[l] < x) coin += (abs(x - hero[l]));
      if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
      cout << coin;
      if (i < m - 1) cout << endl;
      continue;
    } else {
      long long mn = pow(10, 17);
      if (hero[l] > x) {
        if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
        mn = min(mn, coin);
      } else {
        if (hero[l] < x) coin += (abs(x - hero[l]));
        if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
        mn = min(mn, coin);
      }
      coin = 0;
      if (hero[l - 1] > x) {
        if (total - hero[l - 1] < y) coin += (abs(y - (total - hero[l - 1])));
        mn = min(mn, coin);
      } else {
        if (hero[l - 1] < x) coin += (abs(x - hero[l - 1]));
        if (total - hero[l - 1] < y) coin += (abs(y - (total - hero[l - 1])));
        mn = min(mn, coin);
      }
      cout << mn;
      if (i < m - 1) cout << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int T = 1;
  while (T--) {
    solve();
    if (T) cout << endl;
  }
  return 0;
}

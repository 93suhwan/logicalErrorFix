#include <bits/stdc++.h>
using namespace std;
long long int powMod(long long int x, long long int y) {
  long long int p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % ((long long int)1e9 + 7);
    }
    y /= 2;
    x = (x * x) % ((long long int)1e9 + 7);
  }
  return p;
}
long long int CpowMod(long long int x, long long int y, long long int w) {
  long long int p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % w;
    }
    y /= 2;
    x = (x * x) % w;
  }
  return p;
}
long long int invMod(long long int x) {
  return powMod(x, ((long long int)1e9 + 7) - 2);
}
long long int CinvMod(long long int x, long long int w) {
  return CpowMod(x, w - 2, w);
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  vector<long long int> hero(n);
  long long int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> hero[i];
    total += hero[i];
  }
  int m;
  cin >> m;
  vector<pair<long long int, long long int>> dragon(m);
  for (int i = 0; i < m; i++) {
    cin >> dragon[i].first >> dragon[i].second;
  }
  long long int x, y;
  sort(begin(hero), end(hero));
  for (int i = 0; i < m; i++) {
    x = dragon[i].first;
    y = dragon[i].second;
    int l = lower_bound(begin(hero), end(hero), x) - hero.begin();
    long long int coin = 0;
    if (l == 0) {
      if (hero[l] < x) coin += (abs(x - hero[l]));
      if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
      cout << coin;
      if (i < m - 1) cout << endl;
      continue;
    } else {
      long long int mn = 1800000000000000000;
      coin = 0;
      if (hero[l] >= x) {
        if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
        mn = min(mn, coin);
      } else {
        if (hero[l] < x) coin += (abs(x - hero[l]));
        if (total - hero[l] < y) coin += (abs(y - (total - hero[l])));
        mn = min(mn, coin);
      }
      coin = 0;
      if (hero[l - 1] >= x) {
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

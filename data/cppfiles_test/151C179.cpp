#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
long long int N = 1e9 + 7;
long long int Z = 998244353;
long long int power(long long int x, unsigned int y, int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modinv(long long int x, int p) { return (power(x, p - 2, p)); }
bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
  return (p1.first < p2.first);
}
void precompute() {}
int parent[M];
map<int, int> mp, rmp;
int find(int x) {
  if (x == parent[x]) {
    return x;
  }
  return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
  if (x == y) {
    return;
  }
  if (mp.find(x) == mp.end()) {
    return;
  }
  int px = find(mp[x]);
  if (mp.find(y) == mp.end()) {
    rmp[px] = y;
    mp.erase(x);
    mp[y] = px;
    return;
  }
  int py = find(mp[y]);
  mp.erase(x);
  parent[px] = py;
}
void solve() {
  int q;
  cin >> q;
  int sz = 0;
  while (q--) {
    int type, x, y;
    cin >> type;
    if (type == 1) {
      cin >> x;
      if (mp.find(x) != mp.end()) {
        parent[sz] = mp[x];
      } else {
        mp[x] = sz;
        rmp[sz] = x;
        parent[sz] = sz;
      }
      sz++;
    } else {
      cin >> x >> y;
      merge(x, y);
    }
  }
  for (int i = 0; i < sz; i++) {
    cout << rmp[find(i)] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  int tt = t;
  precompute();
  while (t--) {
    solve();
  }
  return 0;
}

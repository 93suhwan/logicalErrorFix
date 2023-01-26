#include <bits/stdc++.h>
using namespace std;
long long BE(int a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
long long get(long long n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return i;
  return n;
}
void pro() {
  bool ok = 0, gf = 1, flag = 0;
  long long n, h = 0, p = 0, k = 0, x = 0, m;
  vector<long long> v;
  cin >> n >> m;
  map<int, int> mp;
  set<long long> sp;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      mp[x]++;
      sp.insert(x);
      if (sp.find(y) != sp.end()) k++;
    } else {
      mp[y]++;
      sp.insert(y);
      if (sp.find(x) != sp.end()) k++;
    }
  }
  int first;
  cin >> first;
  while (first--) {
    int h;
    cin >> h;
    if (h == 3)
      cout << sp.size() - k << endl, k = sp.size() - k;
    else {
      int y, u;
      cin >> y >> u;
      if (h == 1) {
        if (y > u) {
          if (sp.find(y) == sp.end()) k++;
        } else {
          if (sp.find(u) == sp.end()) k++;
        }
      } else {
        if (y > u) {
          if (mp[u] >= 1) k++;
          if (sp.find(y) == sp.end()) k++;
        } else {
          if (mp[y] >= 1) k++;
          if (sp.find(u) == sp.end()) k++;
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pro();
}

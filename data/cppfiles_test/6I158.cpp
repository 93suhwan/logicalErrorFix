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
  long long first;
  cin >> first;
  p = sp.size() - k;
  while (first--) {
    int h;
    cin >> h;
    k = 0;
    if (h == 3)
      cout << p << endl, k = p;
    else {
      long long y, u;
      cin >> y >> u;
      k = 0;
      if (h == 1) {
        if (y > u) {
          if (sp.find(u) != sp.end()) x--, mp[u]--;
          if (sp.find(y) != sp.end())
            k += 0;
          else
            k++, mp[y]++;
        } else {
          if (sp.find(y) != sp.end()) x--, mp[y]--;
          if (sp.find(u) != sp.end())
            k += 0;
          else
            k++, mp[u]++;
        }
        p += x + k;
      } else {
        if (y > u) {
          if (mp[u] >= 1) k++, mp[u]--;
          if (sp.find(y) == sp.end()) k++, mp[y]++;
        } else {
          if (mp[y] >= 1) k++, mp[y]--;
          if (sp.find(u) == sp.end()) k++, mp[u]++;
        }
        p += k;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pro();
}

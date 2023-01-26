#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
struct node {
  int l, r, id;
};
bool operator<(node A, node B) {
  if (A.r == B.r) {
    if (A.l == B.l) return A.id < B.id;
    return A.l < B.l;
  }
  return A.r < B.r;
}
map<int, vector<node>> ump;
int aa[maxn], a[maxn], b[maxn], m[maxn];
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    ump.clear();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &a[i], &b[i], &m[i]);
      int l = max({a[i] - m[i], 0}), r = min(a[i], a[i] - (m[i] - b[i]));
      ump[a[i] + b[i] - m[i]].push_back({l, r, i});
    }
    int ans = 0;
    for (auto it : ump) {
      vector<node> ve = it.second;
      sort(ve.begin(), ve.end());
      int num = 0;
      for (int i = 0; i < ve.size(); i++) {
        num++;
        int r = ve[i].r;
        int j = i;
        while (j < ve.size() && ve[j].l <= r) j++;
        for (int k = i; k < j; k++) {
          aa[ve[k].id] = r;
        }
        i = j - 1;
      }
      ans += num;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      int tm = a[i] - aa[i];
      printf("%d %d\n", tm, m[i] - tm);
    }
  }
}

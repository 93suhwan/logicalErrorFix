#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, a[N];
ll gen(ll x) {
  const ll k = 0x9ddfea08eb382d69ull;
  for (int i = (1); i <= (3); i++) x *= k, x ^= x >> 47;
  return x * k;
}
int rnd() {
  static ll s = 2;
  return (s += gen(s)) & INT_MAX;
}
int chk(ll n) {
  int ct = 0, p;
  for (int i = 2; (ll)i * i <= n; i++)
    while (n % i == 0) n /= i, p = i, ct++;
  return ct == 1 && n > 1 ? p : 0;
}
ll qry(int x, int y) {
  printf("? %d %d\n", x, y), fflush(stdout);
  ll z;
  scanf("%lld", &z);
  return z;
}
void solve() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) a[i] = 0;
  if (n == 3) {
    vector<int> v{1, 2, 3};
    while (1) {
      random_shuffle(v.begin(), v.end());
      ll q0 = qry(v[0], v[1]), q1 = qry(v[1], v[2]), x = sqrt(q1);
      if (x * (x - 1) == q0 && x * (x + 1) == q1) {
        a[v[0]] = x - 1, a[v[1]] = x, a[v[2]] = x + 1;
        break;
      }
    }
  } else if (n < 114) {
    int x, y;
    while (1) {
      do x = rnd() % n + 1, y = rnd() % n + 1;
      while (x == y);
      if (qry(x, y) & 1) break;
    }
    vector<int> o{x}, e;
    for (int i = (1); i <= (n); i++)
      if (i ^ x) qry(x, i) & 1 ? o.push_back(i) : e.push_back(i);
    vector<tuple<ll, int, int>> v;
    for (int x : o)
      for (int y : e) v.emplace_back(qry(x, y), x, y);
    sort(v.rbegin(), v.rend());
    for (auto [z, x, y] : v) {
      if (a[x] || a[y]) continue;
      z = sqrt(z) + 1;
      if (z & 1)
        a[x] = z;
      else
        a[y] = z;
    }
  } else {
    int x, y;
    while (1) {
      do x = rnd() % n + 1, y = rnd() % n + 1;
      while (x == y);
      if (chk(qry(x, y))) break;
    }
    int z;
    while (1) {
      do z = rnd() % n + 1;
      while (z == x || z == y);
      ll qx = qry(x, z), qy = qry(y, z);
      if (qx == qy) continue;
      if (qx > qy) swap(x, y), swap(qx, qy);
      a[x] = qy % qx ? chk(qry(x, y)) : qry(x, y) / (qy / qx);
      break;
    }
    for (int i = (1); i <= (n); i++)
      if (i ^ x) a[i] = qry(i, x) / a[x];
  }
  printf("! ");
  for (int i = (1); i <= (n); i++) printf("%d ", a[i]);
  puts(""), fflush(stdout);
}
int main() {
  int T;
  for (cin >> T; T--; solve())
    ;
}

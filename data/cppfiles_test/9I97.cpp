#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:360777216")
using LL = long long;
using ld = long double;
const int INF = 2 * 1000 * 1000 * 1000;
LL MOD = 1e9 + 7;
LL LINF = (LL)4e18;
double EPS = 1e-7;
using namespace std;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
const LL max_er = 1e2;
vector<LL> min_div(max_er + 1, 0);
vector<int> pp(max_er + 1, 1);
vector<LL> res(max_er + 1, -1);
vector<LL> primes;
void eratosfen() {
  pp[0] = pp[1] = 0;
  for (LL i = 2; i <= max_er; ++i) {
    if (!pp[i]) continue;
    primes.push_back(i);
    min_div[i] = i;
    for (LL j = i * i; j <= max_er; j += i) {
      pp[j] = 0;
      if (!min_div[j]) min_div[j] = i;
    }
  }
}
vector<pair<int, int>> divs;
void get_divs(LL n) {
  while (n != 1) {
    LL cur = min_div[n];
    LL cnt = 0;
    while (n % cur == 0) {
      n /= cur;
      cnt++;
    }
    divs.push_back({cur, cnt});
  }
}
LL T[1][4 * 200];
void build(int idx, vector<int>& a, int v, int tl, int tr) {
  if (tl == tr)
    T[idx][v] = a[tl] == 0;
  else {
    int tm = (tl + tr) / 2;
    build(idx, a, v * 2, tl, tm);
    build(idx, a, v * 2 + 1, tm + 1, tr);
    T[idx][v] = T[idx][v * 2] + T[idx][v * 2 + 1];
  }
}
void update(int idx, int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    T[idx][v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(idx, 2 * v, tl, tm, pos, val);
    else
      update(idx, 2 * v + 1, tm + 1, tr, pos, val);
    T[idx][v] = T[idx][2 * v] + T[idx][2 * v + 1];
  }
}
int get(int idx, int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return T[idx][v];
  int tm = (tl + tr) / 2;
  return get(idx, 2 * v, tl, tm, l, min(tm, r)) +
         get(idx, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}
LL binpow(LL a, LL n, LL mod) {
  if (n == 0) return 1ll;
  if (n % 2 == 1)
    return (binpow(a, n - 1, mod) % mod * a) % mod;
  else {
    LL b = binpow(a, n / 2, mod) % mod;
    return (b * b) % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  srand(time(nullptr));
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> v(m);
  vector<vector<int>> pol(n, vector<int>(m));
  for (int(i) = 0; (i) < n; (i)++) {
    for (int(j) = 0; (j) < m; (j)++) {
      cin >> pol[i][j];
    }
  }
  for (int(i) = 0; (i) < m; (i)++) {
    for (int(j) = 0; (j) < n; (j)++) {
      if (pol[j][i] != 2) v[i].insert(pol[j][i]);
    }
  }
  for (int(ha) = 0; (ha) < k; (ha)++) {
    int x;
    cin >> x;
    x--;
    int y = 0;
    while (1) {
      if (v[x].size() == 0 || y > *v[x].rbegin()) {
        cout << x + 1 << " ";
        break;
      } else {
        int i = 0;
        for (auto it = v[x].begin(); it != v[x].end(); ++it) {
          if (*it >= y) {
            y = i;
            int cl = *it;
            v[x].erase(it);
            if (cl == 1)
              x++;
            else
              x--;
            break;
          }
          i++;
        }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T>
void read(T &x) {
  x = 0;
  int c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
bool checkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int mod = 1000000000 + 7, inv2 = (mod + 1) / 2, inv3 = (mod + 1) / 3,
          inv6 = (mod + 1) / 6;
struct Z {
  int x;
  Z(int x = 0) : x(x) {}
};
bool operator==(const Z &a, const Z &b) { return a.x == b.x; }
Z operator+(const Z &a, const Z &b) {
  int o = a.x + b.x;
  return o >= mod ? o - mod : o;
}
Z operator-(const Z &a, const Z &b) {
  int o = a.x - b.x;
  return o < 0 ? o + mod : o;
}
Z operator*(const Z &a, const Z &b) { return (long long)a.x * b.x % mod; }
Z &operator+=(Z &a, const Z &b) { return a = a + b; }
Z &operator-=(Z &a, const Z &b) { return a = a - b; }
Z &operator*=(Z &a, const Z &b) { return a = a * b; }
Z qpow(Z a, int b) {
  Z ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    b >>= 1;
    a = a * a;
  }
  return ans;
}
Z operator/(const Z &a, const Z &b) { return a * qpow(b, mod - 2); }
Z &operator/=(Z &a, const Z &b) { return a = a / b; }
ostream &operator<<(ostream &out, const Z &a) {
  out << a.x;
  return out;
}
const int N = 200005;
int n, q;
int ans[N];
int lst[N];
int L[N], R[N], D[N];
Z c[N], temp[4], sum[N][4];
struct xyx {
  int id, co, lim;
  xyx() {}
  xyx(int i, int c, int l) : id(i), co(c), lim(l) {}
};
vector<xyx> buc[N];
void init() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i].x);
  map<int, int> Map;
  for (int i = 1; i <= n; ++i) {
    lst[i] = Map[c[i].x];
    Map[c[i].x] = i;
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &L[i], &R[i], &D[i]);
    buc[R[i]].push_back(xyx(i, 1, L[i]));
    buc[L[i] - 1].push_back(xyx(i, -1, L[i]));
  }
}
struct seg {
  Z sum[N << 2][4];
  void push_up(int x) {
    for (int i = 0; i < 4; ++i) sum[x][i] = sum[x << 1][i] + sum[x << 1 | 1][i];
  }
  void update(int x, int l, int r, int p, Z v) {
    if (l == r) {
      sum[x][0] += 1;
      sum[x][1] += v;
      sum[x][2] += v * v;
      sum[x][3] += v * v * v;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(x << 1, l, mid, p, v);
    else
      update(x << 1 | 1, mid + 1, r, p, v);
    push_up(x);
  }
  void query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      for (int i = 0; i < 4; ++i) temp[i] += sum[x][i];
      return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) query(x << 1, l, mid, L, R);
    if (R > mid) query(x << 1 | 1, mid + 1, r, L, R);
  }
  void ask(int lim) {
    if (lim == 0) return;
    query(1, 0, n, 0, lim - 1);
  }
} T;
bool check(int x) {
  Z m = sum[x][0];
  Z s1 = sum[x][1], s2 = sum[x][2], s3 = sum[x][3];
  if (m.x == 1) return 1;
  Z d = D[x];
  Z su1 = m * (m - 1) * inv2;
  Z su2 = (m - 1) * m * (m + m - 1) * inv6;
  Z su3 = su1 * su1;
  Z w = (s1 - su1 * d) / m;
  if (m * w * w + su1 * 2 * d * w + d * d * su2 == s2) {
    if (m * w * w * w + 3 * w * w * d * su1 + 3 * w * d * d * su2 +
            d * d * d * su3 ==
        s3) {
      return 1;
    }
  }
  return 0;
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    T.update(1, 0, n, lst[i], c[i]);
    for (auto &ele : buc[i]) {
      T.ask(ele.lim);
      for (int i = 0; i < 4; ++i) {
        sum[ele.id][i] += ele.co * temp[i];
        temp[i] = 0;
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (check(i)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}

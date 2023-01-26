#include <bits/stdc++.h>
using namespace std;
mt19937 mr(time(0));
struct LL {
  static const long long int m = 1000000007;
  long long int val;
  LL(long long int v) { val = reduce(v); };
  LL(int v) { val = reduce((long long int)v); };
  LL() { val = 0; };
  ~LL(){};
  LL(const LL& l) { val = l.val; };
  LL& operator=(int l) {
    val = l;
    return *this;
  }
  LL& operator=(long long int l) {
    val = l;
    return *this;
  }
  LL& operator=(LL l) {
    val = l.val;
    return *this;
  }
  static long long int reduce(long long int x, long long int md = m) {
    x %= md;
    while (x >= md) x -= md;
    while (x < 0) x += md;
    return x;
  }
  bool operator<(const LL& b) { return val < b.val; }
  bool operator<=(const LL& b) { return val <= b.val; }
  bool operator==(const LL& b) { return val == b.val; }
  bool operator>=(const LL& b) { return val >= b.val; }
  bool operator>(const LL& b) { return val > b.val; }
  LL operator+(const LL& b) { return LL(val + b.val); }
  LL operator+(const long long int& b) { return (*this + LL(b)); }
  LL& operator+=(const LL& b) { return (*this = *this + b); }
  LL& operator+=(const long long int& b) { return (*this = *this + b); }
  LL operator-(const LL& b) { return LL(val - b.val); }
  LL operator-(const long long int& b) { return (*this - LL(b)); }
  LL& operator-=(const LL& b) { return (*this = *this - b); }
  LL& operator-=(const long long int& b) { return (*this = *this - b); }
  LL operator*(const LL& b) { return LL(val * b.val); }
  LL operator*(const long long int& b) { return (*this * LL(b)); }
  LL& operator*=(const LL& b) { return (*this = *this * b); }
  LL& operator*=(const long long int& b) { return (*this = *this * b); }
  static LL exp(const LL& x, const long long int& y) {
    long long int z = y;
    z = reduce(z, m - 1);
    LL ret = 1;
    LL w = x;
    while (z) {
      if (z & 1) ret *= w;
      z >>= 1;
      w *= w;
    }
    return ret;
  }
  LL& operator^=(long long int y) { return (*this = LL(val ^ y)); }
  LL operator/(const LL& b) { return ((*this) * exp(b, -1)); }
  LL operator/(const long long int& b) { return (*this / LL(b)); }
  LL operator/=(const LL& b) { return ((*this) *= exp(b, -1)); }
  LL& operator/=(const long long int& b) { return (*this = *this / LL(b)); }
};
ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
long long int T, N, M, K, Q, X, Y;
long long int rd() {
  long long int x;
  scanf("%lld", &x);
  return x;
}
void fl() { cout.flush(); }
int seg[100010];
int lazy[100010];
bool mark[100010];
struct Cheese {
  long long int F(long long int a, long long int b) { return a + b; }
  int n;
  Cheese(int n) { start(n); }
  void start(int n) {
    this->n = n;
    for (int i = 0; i < 4 * n + 5; i++) {
      seg[i] = 0;
      lazy[i] = 0;
      mark[i] = 0;
    }
  }
  void push(int v, int tl, int tr) {
    if (mark[v]) {
      lazy[2 * v] = lazy[v];
      lazy[2 * v + 1] = lazy[v];
      mark[2 * v] = true;
      mark[2 * v + 1] = true;
      int tm = (tl + tr) / 2;
      seg[2 * v] = lazy[2 * v] * (tm - tl + 1);
      seg[2 * v + 1] = lazy[2 * v + 1] * (tr - tm);
      mark[v] = false;
    }
  }
  void update(int v, int tl, int tr, int l, int r, int rep) {
    if (l > r) return;
    if (l == tl && r == tr) {
      lazy[v] = rep;
      mark[v] = true;
      seg[v] = rep * (tr - tl + 1);
    } else {
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      update(2 * v, tl, tm, l, min(r, tm), rep);
      update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
      seg[v] = seg[2 * v + 1] + seg[2 * v];
    }
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    push(v, tl, tr);
    if (l <= tl && r >= tr) return seg[v];
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) +
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void update(int l, int r, int rep) { update(1, 0, n - 1, l, r, rep); }
  int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
  return result;
}
vector<int> exp(vector<int> const& a, int b) {
  vector<int> atemp = a;
  vector<int> ret = vector<int>();
  ret.push_back(1);
  while (b) {
    if (b & 1) ret = multiply(atemp, ret);
    b >>= 1;
    atemp = multiply(atemp, atemp);
  }
  return ret;
}
vector<vector<int>> adj;
stack<int> color2;
int color[100010];
struct DSU {
  int n;
  vector<int> P;
  vector<int> S;
  void start(int n) {
    for (int i = 0; i <= n + 5; i++) {
      P.push_back(i);
      S.push_back(1);
    }
  }
  int SZ(int x) { return S[pp(x)]; }
  int pp(int x) {
    if (P[x] == x) return x;
    return (P[x] = pp(P[x]));
  }
  bool un(int a, int b) {
    a = pp(a);
    b = pp(b);
    if (a == b) return 0;
    if (S[a] > S[b]) swap(a, b);
    S[b] += S[a];
    P[a] = b;
    return 1;
  }
};
int temp[100010];
int q = 0;
string ask(int cx, int cy) {
  q++;
  if (q == 130) return "Done";
  string second;
  cout << cx << " " << cy << endl;
  fl();
  char buf[15];
  scanf("%s", buf);
  second = buf;
  assert(second.size() > 0);
  return second;
}
bool solve() {
  int cx = 1;
  int cy = 1;
  string second;
  for (; cx < 8;) {
    for (; cy < 9;) {
      second = ask(cx, cy++);
      if (second == "Done") return 1;
      if (second.find("Left") != string::npos) cy = ((cy - 1 == 1) ? 2 : 1);
      if (second.find("Right") != string::npos) break;
    }
    cx++;
    if (cy > 3) {
      second = ask(cx, cy = max(1, cy - 1));
      if (second == "Done") return 1;
    }
    cy = 1;
  }
  return 0;
}
int main() {
  bool trials = 1;
  if (trials)
    T = rd();
  else
    T = 1;
  while (T--) solve();
  return 0;
}

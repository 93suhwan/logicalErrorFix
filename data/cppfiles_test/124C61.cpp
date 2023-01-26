#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
template <typename T>
void makeunique(vector<T>& vx) {
  sort(vx.begin(), vx.end());
  auto it = unique(vx.begin(), vx.end());
  vx.resize(std::distance(vx.begin(), it));
}
int rint();
char rch();
long long rlong();
struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x < 0) x += MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {
    sig = _norm(sig);
    x = sig;
  }
  mint(signed long long sig) {
    sig = _norm(sig % MOD);
    x = sig;
  }
  int get() const { return (int)x; }
  mint& operator+=(mint that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(mint that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(mint that) {
    x = ((unsigned long long)x * that.x) % MOD;
    return *this;
  }
  mint& operator/=(mint that) { return *this *= that.inverse(); }
  mint& operator+=(int that) {
    that = _norm(that);
    if ((x += that) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(int that) {
    that = _norm(that);
    if ((x += MOD - that) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(int that) {
    that = _norm(that);
    x = ((unsigned long long)x * that) % MOD;
    return *this;
  }
  mint& operator/=(int that) {
    that = _norm(that);
    return *this *= mint(that).inverse();
  }
  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }
  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }
  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while (b) {
      signed t = a / b;
      a -= t * b;
      std::swap(a, b);
      u -= t * v;
      std::swap(u, v);
    }
    if (u < 0) u += MOD;
    mint res;
    res.x = (unsigned)u;
    return res;
  }
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const {
    mint t;
    t.x = x == 0 ? 0 : MOD - x;
    return t;
  }
  mint operator^(long long k) const {
    mint a = (*this);
    if (k < 0) {
      k = -k;
      a = a.inverse();
    }
    mint r = 1;
    while (k) {
      if (k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};
struct S {
  S() : occ(0), val(0) {}
  S(mint const& _occ, mint const& _val) : occ(_occ), val(_val) {}
  S(int const& _occ, int const& _val) : occ(_occ), val(_val) {}
  S& operator+=(S const& rhs) {
    this->occ += rhs.occ;
    this->val += rhs.val;
    return *this;
  }
  S operator+(S const& that) const { return S(*this) += that; }
  S& operator+=(int const& rhs) {
    this->val += mint(rhs) * this->occ;
    return *this;
  }
  S operator+(int const& that) const { return S(*this) += that; }
  mint occ = 0, val = 0;
};
string inpsrc, inptarget;
int n;
vector<vector<pair<int, int> > > dp;
S f(int pos, int k) {
  if (pos == -1) {
    if (k == 0)
      return S(1, 0);
    else
      return S(0, 0);
  }
  if (pos < dp.size() && k + n + 2 < dp[pos].size()) {
    pair<int, int> dpval = dp[pos][k + n + 2];
    if (dpval.first != -1) {
      return S(dpval.first, dpval.second);
    }
  }
  char src = inpsrc[pos], target = inptarget[pos];
  S final(0, 0);
  if ((src == '0' || src == '?') && (target == '0' || target == '?')) {
    final += (f(pos - 1, -k) + abs(k));
  }
  if ((src == '1' || src == '?') && (target == '1' || target == '?')) {
    final += (f(pos - 1, -k) + abs(k));
  }
  if ((src == '0' || src == '?') && (target == '1' || target == '?')) {
    final += (f(pos - 1, -(k - 1)) + abs(k));
  }
  if ((src == '1' || src == '?') && (target == '0' || target == '?')) {
    final += (f(pos - 1, -(k + 1)) + abs(k));
  }
  dp[pos][k + n + 2] = make_pair(final.occ.get(), final.val.get());
  return final;
}
void go() {
  cin >> n >> inpsrc >> inptarget;
  dp.clear();
  dp.resize(n + 4, vector<pair<int, int> >(2 * n + 8, make_pair(-1, -1)));
  S ans = f(n - 1, 0);
  printf("%d\n", ans.val.get());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) go();
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}

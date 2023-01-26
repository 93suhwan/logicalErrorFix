#include <bits/stdc++.h>
using namespace std;
mt19937 mr(time(0));
struct LL {
  static const long long int m = 998244353;
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
  bool operator!=(const LL& b) { return val != b.val; }
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
using namespace std;
long long int cases, N, M, Q, K;
long long int rd() {
  long long int x;
  cin >> x;
  return x;
}
void fl() { cout.flush(); }
void panic(long long int out) {
  cout << out << endl;
  exit(0);
}
map<pair<int, int>, int> key;
int A[1000010 + 100010];
int X[1000010 + 100010];
LL PX = 1;
int X0 = 0;
int CX[1000010 + 100010][2];
int Y[1000010 + 100010];
LL PY = 1;
int Y0 = 0;
int CY[1000010 + 100010][2];
int B[2];
int ovr = 2;
void wash(int x, int y) {
  ovr = 2 - (B[0] > 0) - (B[1] > 0);
  if (X[x])
    PX /= X[x];
  else
    X0--;
  X[x] = 2 - (CX[x][0] > 0) - (CX[x][1] > 0);
  if (X[x])
    PX *= X[x];
  else
    X0++;
  if (Y[y])
    PY /= Y[y];
  else
    Y0--;
  Y[y] = 2 - (CY[y][0] > 0) - (CY[y][1] > 0);
  if (Y[y])
    PY *= Y[y];
  else
    Y0++;
}
void clr(int x, int y) {
  int md = (x + y + A[key[{x, y}]]) & 1;
  B[md]--;
  CX[x][md]--;
  CY[y][md]--;
  wash(x, y);
  A[key[{x, y}]] = -1;
}
void add(int x, int y, int top) {
  int md = (x + y + top) & 1;
  B[md]++;
  CX[x][md]++;
  CY[y][md]++;
  wash(x, y);
  A[key[{x, y}]] = top;
}
void read() {
  N = rd();
  M = rd();
  K = rd();
  Q = 0;
  for (int i = 0; i < N; ++i) {
    X[i] = 2;
    PX *= 2;
    CX[i][0] = CX[i][1] = 0;
  }
  for (int i = 0; i < M; ++i) {
    Y[i] = 2;
    PY *= 2;
    CY[i][0] = CY[i][1] = 0;
  }
  B[0] = 0;
  B[1] = 0;
  for (int q = 0; q < K; ++q) {
    int x = rd() - 1;
    int y = rd() - 1;
    int top = rd();
    if (key.find({x, y}) == key.end()) {
      key[{x, y}] = Q;
      A[Q++] = -1;
    }
    if (A[key[{x, y}]] != -1) clr(x, y);
    if (top >= 0) add(x, y, top);
    cout << (X0 ? 0 : PX) + (Y0 ? 0 : PY) - ovr << endl;
  }
}
int main() {
  bool trials = 0;
  bool interactive = 0;
  if (!interactive) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  if (trials)
    cases = rd();
  else
    cases = 1;
  while (cases--) {
    read();
  }
}

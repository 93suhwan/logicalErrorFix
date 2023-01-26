#include <bits/stdc++.h>
using namespace std;
mt19937 mr(time(0));
struct LL {
  static long long int m;
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
  static void setMod(long long int m) {
    assert(m);
    LL::m = m;
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
long long int LL::m = 1000000007;
using namespace std;
long long int cases, N, M, Q, K, X, Y;
long long int rd() {
  long long int x;
  cin >> x;
  return x;
}
double rdd() {
  double x;
  cin >> x;
  return x;
}
string rds() {
  string x;
  cin >> x;
  return x;
}
template <class T>
void rds(char* S, T* sz) {
  *sz = strlen(strcpy(S, rds().c_str()));
}
template <class T>
void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
  if (E == -18852946) E = sz - 1;
  adj.clear();
  for (long long int i = 0; i < sz + 1; ++i) adj.push_back(vector<T>());
  for (long long int i = 0; i < E; ++i) {
    T a = rd();
    T b = rd();
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}
void fl() { cout.flush(); }
template <class T>
void ds(vector<T> v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
template <class T>
void panic(T out) {
  cout << out << endl;
  exit(0);
}
template <class S, class T>
bool updmin(S& a, T b) {
  S B = (S)b;
  if (B < a) {
    a = B;
    return 1;
  }
  return 0;
}
template <class S, class T>
bool updmax(S& a, T b) {
  S B = (S)b;
  if (B > a) {
    a = B;
    return 1;
  }
  return 0;
}
template <class S, class T>
S min(S a, T b) {
  S c = a;
  updmin(c, b);
  return c;
}
template <class S, class T>
S max(S a, T b) {
  S c = a;
  updmax(c, b);
  return c;
}
long long int cnt[30];
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int DP[2 * 100010];
struct SegTree {
  long long int F(long long int a, long long int b) { return min(a, b); }
  int sz;
  vector<long long int> ST;
  void start(int n) {
    sz = n;
    for (int i = 0; i < 2 * n; i++) ST.push_back(5e18);
  }
  void lift(int idx) { ST[idx] = F(ST[2 * idx], ST[2 * idx + 1]); }
  void update(int idx, long long int x) {
    idx += sz;
    ST[idx] = x;
    idx >>= 1;
    while (idx) {
      lift(idx);
      idx >>= 1;
    }
  }
  long long int query(int lp, int rp) {
    long long int a = 5e18;
    long long int b = 5e18;
    lp += sz;
    rp += sz + 1;
    while (lp < rp) {
      if (lp & 1) a = F(a, ST[lp++]);
      if (rp & 1) b = F(ST[--rp], b);
      lp >>= 1;
      rp >>= 1;
    }
    return F(a, b);
  }
} ST;
long long int PR[2 * 100010];
long long int A[2 * 100010];
long long int B[2 * 100010];
void precalc() {}
void reset() {}
bool cmp(pair<int, int> a, pair<int, int> b) {}
void read() {
  N = rd();
  ST.start(N + 5);
  ST.update(0, 0);
  A[0] = 0;
  B[0] = 0;
  DP[0] = 0;
  for (long long int i = 1; i <= N; ++i) A[i] = rd();
  for (long long int i = 1; i <= N; ++i) B[i] = rd();
  for (long long int i = 1; i <= N; ++i) DP[i] = 5e18;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      PQ;
  for (long long int i = 1; i <= N; ++i) {
    DP[i] = 1 + ST.query(i - A[i], i - 1);
    PQ.push({i + B[i], i});
    while (PQ.size()) {
      if (PQ.top().first <= i) {
        ST.update(PQ.top().second, DP[PQ.top().first]);
        PQ.pop();
      } else
        break;
    }
  }
  if (DP[N] >= 5e18) panic(-1);
  stack<int> S;
  cout << DP[N] << endl;
  S.push(N);
  int curr = DP[N];
  while (S.top()) {
    int x = S.top();
    for (long long int i = x - A[x]; i < x; ++i) {
      if (curr - 1 == DP[i + B[i]]) {
        cout << i << " ";
        S.push(i + B[i]);
        --curr;
        break;
      }
    }
  }
  cout << endl;
}
int main() {
  precalc();
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

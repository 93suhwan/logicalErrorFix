#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const long long mod = 998244353;
struct mint {
  long long x = 0;
  mint(long long y = 0) {
    x = y;
    if (x < 0 || x >= mod) x = (x % mod + mod) % mod;
  }
  mint(const mint& ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint& ope) { return mint(x) += ope; }
  mint operator-(const mint& ope) { return mint(x) -= ope; }
  mint operator*(const mint& ope) { return mint(x) *= ope; }
  mint operator/(const mint& ope) { return mint(x) /= ope; }
  mint& operator+=(const mint& ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& ope) {
    x *= ope.x, x %= mod;
    return *this;
  }
  mint& operator/=(const mint& ope) {
    long long n = mod - 2;
    mint mul = ope;
    while (n) {
      if (n & 1) *this *= mul;
      mul *= mul;
      n >>= 1;
    }
    return *this;
  }
  mint inverse() { return mint(1) / *this; }
  bool operator==(const mint& ope) { return x == ope.x; }
  bool operator!=(const mint& ope) { return x != ope.x; }
};
istream& operator>>(istream& is, mint& ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream& operator<<(ostream& os, mint& ope) { return os << ope.x; }
ostream& operator<<(ostream& os, const mint& ope) { return os << ope.x; }
bool exceed(long long x, long long y, long long m) { return x >= m / y + 1; }
void mark() { cout << "*" << endl; }
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2)
    return ((a % mod) * (modpow(a, n - 1) % mod)) % mod;
  else
    return modpow((a * a) % mod, n / 2) % mod;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (int i = 0; i < deq.size(); i++) {
    os << deq[i] << (i + 1 == deq.size() ? "" : " ");
  }
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
  for (typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end();
       itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ",";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
  for (typename set<T>::iterator itr = set_var.begin(); itr != set_var.end();
       itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
void outa(T a[], long long s, long long t) {
  for (long long i = s; i <= t; i++) {
    cout << a[i];
    if (i < t) cout << " ";
  }
  cout << endl;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
long long n;
long long a[500005];
mint dp[2][500005], dpsum[2][500005], sum[2];
stack<pair<long long, long long> > stk;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> a[i + 1];
  n++;
  stk.push(pair<long long, long long>(-1e18, 1));
  dp[0][0] = dpsum[0][0] = 1;
  for (long long(i) = (2); (i) <= (n); (i)++) {
    while (stk.top().first >= a[i]) {
      long long r = stk.top().second, x = stk.top().first;
      stk.pop();
      long long l = stk.top().second;
      for (long long(j) = (0); (j) <= (1); (j)++)
        sum[j] -= mint(x) * (dpsum[j][r - 1] - dpsum[j][l - 1]);
    }
    long long l = stk.top().second;
    stk.push(pair<long long, long long>(a[i], i));
    for (long long(j) = (0); (j) <= (1); (j)++)
      sum[j] += mint(a[i]) * (dpsum[j][i - 1] - dpsum[j][l - 1]);
    for (long long(j) = (0); (j) <= (1); (j)++) dp[j][i] = sum[1 - j];
    for (long long(j) = (0); (j) <= (1); (j)++)
      dpsum[j][i] = dpsum[j][i - 1] + dp[j][i];
  }
  mint ans = sum[(n + 1) % 2] - sum[n % 2];
  dump_func(ans);
  return 0;
}

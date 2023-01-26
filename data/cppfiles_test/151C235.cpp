#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
using mint = ModInt<MOD>;
long long mod_pow(long long x, long long n) {
  if (n == 0) return 1;
  long long res = mod_pow(x * x % MOD, n / 2);
  if (n & 1) res = res * x % MOD;
  return res;
}
long long power(long long num, long long pw) {
  if (pw == 0) return 1;
  long long res = power(num * num, pw / 2);
  if (pw & 1) res *= pw;
  return res;
}
long long ln(long long num, long long base) {
  int steps = 0;
  while (num > 1) {
    num /= base;
    steps++;
  }
  return steps;
}
int S = 100001;
vector<int> Seive(S);
void seive() {
  fill(Seive.begin(), Seive.end(), 0);
  Seive[0] = 0;
  Seive[1] = 0;
  for (long long i = 2; i <= S; i++) {
    if (Seive[i]) continue;
    for (long long j = i * i; j <= S; j += i) Seive[j] = 1;
  }
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool sortbysec(const pair<long long, char> &a, const pair<long long, char> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
  for (int i = 0; i < a.first.length(); i++) {
    if (i % 2 == 0) {
      if (a.first[i] < b.first[i]) return true;
      if (a.first[i] > b.first[i]) return false;
    } else {
      if (a.first[i] > b.first[i]) return true;
      if (a.first[i] < b.first[i]) return false;
    }
  }
}
int binarySearch(vector<pair<int, int>> a) {
  int r = a.size();
  int l = 1;
  int ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    int rem = mid, curr = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i].first >= rem - 1) {
        if (a[i].second >= curr) {
          curr++;
          rem--;
        }
      }
    }
    if (rem <= 0) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
void toggle(bool &x) { x ^= 1; }
void solve() {
  int q;
  cin >> q;
  map<int, list<int>> m;
  int i = 0;
  while (q--) {
    int num;
    cin >> num;
    if (num == 1) {
      int x;
      cin >> x;
      m[x].push_back(i);
      i++;
    } else {
      int x, y;
      cin >> x >> y;
      if (x == y) continue;
      if (m[x].size() > m[y].size()) m[x].swap(m[y]);
      for (auto &i : m[x]) {
        m[y].push_back(i);
      }
      m.erase(x);
    }
  }
  vector<int> v(i);
  for (auto x : m) {
    for (auto y : x.second) {
      v[y] = x.first;
    }
  }
  for (auto x : v) {
    cout << x << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int T = 1; T <= t; T++) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int abss(long long int a) {
  if (a < 0) return -a;
  return a;
}
long long int ones(long long int a) {
  long long int cnt = 0;
  while (a > 0) {
    if (a & 1) cnt++;
    a >>= 1;
  }
  return cnt;
}
long long int fast_pow(long long int b, long long int e,
                       long long int width = 998244353) {
  if (e == 0) {
    return 1;
  } else if (e == 1) {
    return b % width;
  }
  b = b % width;
  long long int ans = 1;
  while (e > 0) {
    if ((e & 1) == 1) {
      ans = (ans * b) % width;
    }
    e >>= 1;
    b = (b * b) % width;
  }
  return ans;
}
long long int mod_inv(long long int a, long long int width = 998244353) {
  return fast_pow(a, width - 2, width);
}
template <typename Number, Number width>
class ModularArithmetic {
 private:
  Number n;

 public:
  friend ostream &operator<<(ostream &os, ModularArithmetic const &num) {
    return os << num.n;
  }
  friend istream &operator>>(istream &is, ModularArithmetic &num) {
    is >> num.n;
    return is;
  }
  ModularArithmetic() : n(0) {}
  ModularArithmetic(Number n) : n(n % width) {
    if (this->n < 0) this->n += width;
  }
  Number get() const { return n; }
  ModularArithmetic operator+(const ModularArithmetic &b) {
    Number t = (n + b.get()) % width;
    if (t < 0) return ModularArithmetic(width + t);
    return ModularArithmetic(t);
  }
  ModularArithmetic operator-(const ModularArithmetic &b) {
    Number t = (n - b.get()) % width;
    if (t < 0) return ModularArithmetic(width + t);
    return ModularArithmetic(t);
  }
  ModularArithmetic operator*(const ModularArithmetic &b) {
    Number t = (n * b.get()) % width;
    if (t < 0) return ModularArithmetic(width + t);
    return ModularArithmetic(t);
  }
  ModularArithmetic operator/(const ModularArithmetic &b) {
    assert(b.get() != 0);
    Number ans = n * mod_inv(b.get(), width);
    if ((ans) < 0) return ModularArithmetic(width + (ans) % width);
    return ModularArithmetic(ans % width);
  }
  ModularArithmetic &operator+=(const ModularArithmetic &b) {
    n = (n + b.get()) % width;
    if (n < 0) n = n + width;
    return *this;
  }
  ModularArithmetic &operator-=(const ModularArithmetic &b) {
    n = (n - b.get()) % width;
    if (n < 0) n = n + width;
    return *this;
  }
  ModularArithmetic &operator*=(const ModularArithmetic &b) {
    n = (n * b.get()) % width;
    if (n < 0) n = n + width;
    return *this;
  }
  ModularArithmetic &operator/=(const ModularArithmetic &b) {
    assert(b.get() != 0);
    n = (n * mod_inv(b.get(), width)) % width;
    if (n < 0) n = n + width;
    return *this;
  }
};
template <class T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &p) {
  os << "<";
  for (auto &it : p) os << it << " ";
  return os << ">";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class S, class T>
istream &operator>>(istream &is, pair<S, T> &p) {
  return is >> p.first >> p.second;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T, typename Cmp>
ostream &operator<<(ostream &os, const set<T, Cmp> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T, typename Cmp>
ostream &operator<<(ostream &os, const map<S, T, Cmp> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
istream &operator>>(istream &is, const pair<S, T> &p) {
  return is >> p.first >> p.second;
}
template <class T>
istream &operator>>(istream &is, vector<T> &p) {
  for (auto &itr : p) is >> itr;
  return is;
}
template <class T>
void dbs(string str, T t) {
  cerr << str << ":" << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... second) {
  long long int idx = str.find(',');
  cerr << str.substr(0, idx) << ":" << t << ",";
  dbs(str.substr(idx + 1), second...);
}
bool isComposite(long long int a, long long int d, long long int n) {
  long long int res = fast_pow(a, d, n);
  if (res == 1 || res == n - 1) return false;
  while (d != (n - 1)) {
    res = (res * res) % n;
    if (res == n - 1) {
      return false;
    }
  }
  return true;
}
bool MillerRabinDet(long long int n) {
  if (n < 4) return n == 2 || n == 3;
  long long int d = n - 1;
  while (d & 1 == 0) {
    d >>= 1;
  }
  for (long long int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (a == n) return true;
    if (isComposite(a, d, n)) {
      return false;
    }
  }
  return true;
}
bool MillerRabinNonDet(long long int n, long long int k = 1000) {
  if (n < 4) return n == 2 || n == 3;
  long long int d = n - 1;
  long long int second = 0;
  while (d & 1 == 0) {
    d >>= 1;
    second++;
  }
  long long int a;
  for (long long int i = 0; i < k; i++) {
    a = 2 + rand() % (n - 3);
    if (isComposite(a, d, n)) {
      return false;
    }
  }
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long int n, m;
vector<pair<long long int, long long int>> arr;
vector<ModularArithmetic<long long int, 998244353>> F, S;
const long long int sz = 100005;
ModularArithmetic<long long int, 998244353> compute(long long int d) {
  long long int dm = m / d;
  vector<ModularArithmetic<long long int, 998244353>> dp1(dm + 1, 0),
      dp2(dm + 1, 0);
  dp1[0] = 1;
  for (long long int i = 0; i < n; i++) {
    long long int lf = (arr[i].first + d - 1) / d;
    long long int rt = (arr[i].second) / d;
    if (lf > rt) return 0;
    dp2[0] = dp1[0];
    for (long long int j = 1; j <= dm; j++) dp2[j] = dp1[j] + dp2[j - 1];
    {};
    for (long long int j = 0; j <= dm; j++) {
      dp1[j] =
          ((j - lf >= 0) ? dp2[j - lf]
                         : ModularArithmetic<long long int, 998244353>(0)) -
          (((j - (rt + 1)) >= 0)
               ? dp2[j - (rt + 1)]
               : ModularArithmetic<long long int, 998244353>(0));
    }
  }
  ModularArithmetic<long long int, 998244353> ans = 0;
  for (auto itr : dp1) ans += itr;
  ans -= dp1[0];
  return ans;
}
void solve() {
  cin >> n >> m;
  vector<pair<long long int, long long int>>(n).swap(arr);
  for (long long int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
  vector<ModularArithmetic<long long int, 998244353>>(m + 1, 0).swap(F);
  vector<ModularArithmetic<long long int, 998244353>>(m + 1, 0).swap(S);
  for (long long int i = m; i > 0; i--) F[i] = compute(i);
  for (long long int i = m; i > 0; i--) {
    S[i] = F[i];
    for (long long int j = i * 2; j <= m; j += i) S[i] -= S[j];
  }
  cout << S[1] << "\n";
}
int main() {
  freopen("err.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }
  friend const Type& abs(const Modular& x) { return x.value; }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
vector<vector<Mint>> fastmulti(vector<vector<Mint>>& a,
                               vector<vector<Mint>>& b) {
  vector<vector<Mint>> ans(a.size(), vector<Mint>(b[0].size(), Mint(0)));
  for (int i = 0; i < (a.size()); ++i) {
    for (int j = 0; j < (a[0].size()); ++j) {
      for (int k = 0; k < (b[0].size()); ++k) {
        ans[i][k] += a[i][j] * b[j][k];
      }
    }
  }
  return ans;
}
vector<Mint> fac, ifac;
Mint C(int m, int n) { return fac[m] * ifac[n] * ifac[m - n]; }
void initFac(int n) {
  fac.resize(n + 1);
  ifac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  ifac[n] = 1 / fac[n];
  for (int i = n - 1; i >= 0; --i) {
    ifac[i] = ifac[i + 1] * (i + 1);
  }
}
class Fenw {
 public:
  Fenw(int n) : v(2 * n, 0) {}
  int lowbit(int x) { return x & -x; }
  long long query(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      ans += v[i];
    }
    return ans;
  }
  void update(int x, int t) {
    for (int i = x; i < v.size(); i += lowbit(i)) {
      v[i] += t;
    }
  }

 private:
  vector<long long> v;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<vector<int>> sub(n);
    for (int i = 0; i < (n); ++i) cin >> v[i];
    for (int i = 0; i < (n - 1); ++i) {
      int p;
      cin >> p;
      sub[--p].push_back(i + 1);
    }
    vector<vector<vector<int>>> query(q);
    for (int i = 0; i < (q); ++i) {
      int p, l, k;
      cin >> p >> l >> k;
      query[--p].push_back({l, k, i});
    }
    vector<int> ans(q, -1);
    unordered_map<int, int> num_count;
    unordered_map<int, unordered_set<int>> freq;
    Fenw f(1000005);
    function<void(int)> dfs = [&](int cur) {
      int count = num_count[v[cur]];
      if (count > 0) {
        freq.erase(cur);
        f.update(count, -1);
      }
      ++count;
      num_count[v[cur]] = count;
      freq[count].insert(v[cur]);
      f.update(count, 1);
      for (auto& ask : query[cur]) {
        int ql = ask[0], qk = ask[1];
        int left = f.query(ql - 1), all = f.query(n) - left;
        if (all < qk) continue;
        int l = ql - 1, r = n;
        while (l + 1 < r) {
          int mid = (l + r) >> 1;
          int sum = f.query(mid) - left;
          if (sum >= qk)
            r = mid;
          else
            l = mid;
        }
        ans[ask[2]] = *freq[r].begin();
      }
      for (auto& son : sub[cur]) {
        dfs(son);
      }
      num_count[v[cur]]--;
      freq[count].erase(v[cur]);
      f.update(count, -1);
      --count;
      if (count > 0) {
        freq[count].insert(v[cur]);
        f.update(count, 1);
      }
    };
    dfs(0);
    for (int i = 0; i < (q); ++i) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}

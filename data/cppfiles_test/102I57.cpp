#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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
  assert(m == 1);
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
using ModType = int;
struct VarMod {
  static ModType value;
};
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
Mint p[33];
bool Solve(int k, int h) {
  vector<int> x;
  for (int i = 1; i <= (1 << k); ++i) {
    x.push_back(i);
  }
  do {
    Mint ans = 0;
    if (k == 1) {
      ans = x[0] * p[1] + x[1] * p[2];
    } else if (k == 2) {
      ans = x[0] * p[1] + x[1] * p[2] + (x[2] + x[3]) * p[3];
    } else {
      ans = x[0] * p[1] + x[1] * p[2] + (x[2] + x[3]) * p[3] +
            (x[4] + x[5] + x[6] + x[7]) * p[5];
    }
    if (ans == h) {
      vector<int> ans(1 << k);
      if (k == 1) {
        ans[x[0] - 1] = 1;
        ans[x[1] - 1] = 2;
      } else if (k == 2) {
        ans[x[0] - 1] = 1;
        ans[x[1] - 1] = 2;
        ans[x[2] - 1] = ans[x[3] - 1] = 3;
      } else {
        ans[x[0] - 1] = 1;
        ans[x[1] - 1] = 2;
        ans[x[2] - 1] = ans[x[3] - 1] = 3;
        for (int i = 4; i < 8; ++i) ans[x[i] - 1] = 5;
      }
      for (int i = 0; i < (1 << k); ++i) cout << ans[i] << " ";
      cout << endl;
      return true;
    }
  } while (next_permutation(x.begin(), x.end()));
  return false;
}
bool z[530];
int pr[530];
bool Verify5(int a, int b, int c, int d, int e, int f) {
  for (int i = 1; i <= 32; ++i) {
    if (i == a || i == b) continue;
    if (c - i == a || c - i == b || c - i == i) continue;
    for (int d1 = 1; d1 <= 32; ++d1) {
      if (d1 == a || d1 == b || d1 == i || d1 == c - i) continue;
      for (int d2 = d1 + 1; d2 <= 32; ++d2) {
        if (d2 == a || d2 == b || d2 == i || d2 == c - i) continue;
        for (int d3 = d2 + 1; d3 <= 32; ++d3) {
          if (d3 == a || d3 == b || d3 == i || d3 == c - i) continue;
          int d4 = d - d1 - d2 - d3;
          if (d4 <= d3 || d4 >= 33) continue;
          if (d4 == a || d4 == b || d4 == i || d4 == c - i) continue;
          memset(z, 0, sizeof(z));
          z[0] = true;
          int sum = 0;
          for (int t = 1; t <= 32; ++t) {
            if (t == a || t == b || t == i || t == c - i || t == d1 ||
                t == d2 || t == d3 || t == d4)
              continue;
            for (int j = sum; j >= 0; --j) {
              if (z[j]) {
                z[j + t] = true;
                pr[j + t] = j;
              }
            }
            sum += t;
          }
          if (z[e]) {
            vector<int> ans(32, 17);
            while (e != 0) {
              ans[e - pr[e] - 1] = 9;
              e = pr[e];
            }
            ans[d1 - 1] = ans[d2 - 1] = ans[d3 - 1] = ans[d4 - 1] = 5;
            ans[i] = ans[c - i] = 3;
            ans[b] = 2;
            ans[a] = 1;
            for (int i : ans) cout << i << " ";
            cout << endl;
            return true;
          }
        }
      }
    }
  }
  return false;
}
bool Solve5(Mint h) {
  int sum = (1 + 32) * 32 / 2;
  Mint now = 0;
  for (int i = 1; i <= 32; ++i) {
    now += i * p[1];
    sum -= i;
    for (int j = 1; j <= 32; ++j) {
      if (j == i) continue;
      now += j * p[2];
      sum -= j;
      for (int k = 3; k <= 63; ++k) {
        now += k * p[3];
        sum -= k;
        for (int l = 10; l <= 122; ++l) {
          now += l * p[5];
          sum -= l;
          int mstart = max(36, sum - 392);
          Mint temp = now + mstart * p[9] - (sum - mstart) * p[17];
          Mint diff = p[17] - p[9];
          for (int m = max(36, sum - 392); m <= min(228, sum - 136); ++m) {
            if (temp == h) {
              if (Verify5(i, j, k, l, m, sum - m)) return true;
            }
            temp += diff;
          }
          sum += l;
          now -= l * p[5];
        }
        sum += k;
        now -= k * p[3];
      }
      sum += j;
      now -= j * p[2];
    }
    sum += i;
    now -= i * p[1];
  }
  return false;
}
bool Verify4(int a, int b, int c, int d, int e) {
  for (int i = 1; i <= 32; ++i) {
    if (i == a || i == b) continue;
    if (c - i == a || c - i == b || c - i == i) continue;
    for (int d1 = 1; d1 <= 32; ++d1) {
      if (d1 == a || d1 == b || d1 == i || d1 == c - i) continue;
      for (int d2 = d1 + 1; d2 <= 32; ++d2) {
        if (d2 == a || d2 == b || d2 == i || d2 == c - i) continue;
        for (int d3 = d2 + 1; d3 <= 32; ++d3) {
          if (d3 == a || d3 == b || d3 == i || d3 == c - i) continue;
          int d4 = d - d1 - d2 - d3;
          if (d4 <= d3 || d4 >= 33) continue;
          if (d4 == a || d4 == b || d4 == i || d4 == c - i) continue;
          vector<int> ans(16, 9);
          ans[d1 - 1] = ans[d2 - 1] = ans[d3 - 1] = ans[d4 - 1] = 5;
          ans[i] = ans[c - i] = 3;
          ans[b] = 2;
          ans[a] = 1;
          for (int i : ans) cout << i << " ";
          cout << endl;
          return 0;
        }
      }
    }
  }
  return false;
}
bool Solve4(int h) {
  int sum = (1 + 16) * 16 / 2;
  Mint now = 0;
  for (int i = 1; i <= 16; ++i) {
    now += i * p[1];
    sum -= i;
    for (int j = 1; j <= 16; ++j) {
      if (j == i) continue;
      now += j * p[2];
      sum -= j;
      for (int k = 3; k <= 31; ++k) {
        now += k * p[3];
        sum -= k;
        for (int l = max(10, sum - 108); l <= min(58, sum - 36); ++l) {
          if (now + l * p[5] + (sum - l) * p[9] == h) {
            if (Verify4(i, j, k, l, sum - l)) return true;
          }
        }
        sum += k;
        now -= k * p[3];
      }
      sum += j;
      now -= j * p[2];
    }
    sum += i;
    now -= i * p[1];
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  md = 998244353;
  int k, A, h;
  cin >> k >> A >> h;
  p[0] = 1;
  for (int i = 1; i <= 32; ++i) p[i] = p[i - 1] * A;
  if (k == 5) {
    if (!Solve5(h)) {
      cout << -1 << endl;
    }
  } else if (k == 4) {
    if (!Solve4(h)) {
      cout << -1 << endl;
    }
  } else {
    if (!Solve(k, h)) {
      cout << -1 << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
struct random {
  unsigned long long seed;
  std::mt19937 value;
  random() {
    void *mem = malloc(1);
    free(mem);
    seed = (unsigned long long)mem;
    value.seed(seed);
  }
} rd;
int add(int x, int y, int p) { return (x += y) >= p ? x - p : x; }
int sub(int x, int y, int p) { return (x -= y) < 0 ? x + p : x; }
int mul(int x, int y, int p) { return (long long)x * y % p; }
int power(int x, int y, int p) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = mul(ans, x, p);
    x = mul(x, x, p);
  }
  return ans;
}
bool Miller_Rabin(int n) {
  constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
  if (n == 1) return false;
  for (int i : primes) {
    if (n == i) return true;
    if (!(n % i)) return false;
  }
  int limits = 10;
  int x = n - 1;
  int cnt = __builtin_ctz(x);
  x >>= cnt;
  while (limits--) {
    int a = rd.value() % (n - 2) + 1;
    int t = power(a, x, n);
    if (t == 1) continue;
    int i;
    for (int i = 0; i < cnt; ++i) {
      if (t == n - 1) break;
      t = mul(t, t, n);
    }
    if (i == cnt) return false;
  }
  return true;
}
int rand_prime(int l, int r) {
  int x;
  do {
    x = rd.value() % (r - l + 1) + l;
  } while (!Miller_Rabin(x));
  return x;
}
struct hash {
  static int mod[8];
  int val[8];
  static void init() {
    for (int i = 0; i < 8; ++i) mod[i] = rand_prime(9e8, 19e8);
  }
  hash() {
    for (int i = 0; i < 8; ++i) val[i] = 0;
  }
  hash(int x) {
    for (int i = 0; i < 8; ++i) val[i] = x % mod[i];
  }
  hash &operator+=(const hash &x) {
    for (int i = 0; i < 8; ++i) val[i] = add(val[i], x.val[i], mod[i]);
    return *this;
  }
  hash &operator-=(const hash &x) {
    for (int i = 0; i < 8; ++i) val[i] = sub(val[i], x.val[i], mod[i]);
    return *this;
  }
  hash &operator*=(const hash &x) {
    for (int i = 0; i < 8; ++i) val[i] = mul(val[i], x.val[i], mod[i]);
    return *this;
  }
  hash operator+(const hash &x) const {
    hash ans = *this;
    ans += x;
    return ans;
  }
  hash operator-(const hash &x) const {
    hash ans = *this;
    ans -= x;
    return ans;
  }
  hash operator*(const hash &x) const {
    hash ans = *this;
    ans *= x;
    return ans;
  }
  bool operator==(const hash &x) const {
    for (int i = 0; i < 8; ++i)
      if (val[i] != x.val[i]) return false;
    return true;
  }
};
int hash::mod[8]{};
std::vector<int> zfunction(const std::string &s) {
  int n = s.length();
  std::vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = std::min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
std::string s, t;
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  hash::init();
  std::cin >> s >> t;
  int n = s.length(), m = t.length();
  hash x{};
  for (char &i : t) (x *= 10) += i - '0';
  std::vector<hash> a(n), pow10(n);
  a.front() = s.front() - '0';
  pow10.front() = 10;
  for (int i = 1; i < n; ++i)
    a[i] = a[i - 1] * 10 + s[i] - '0', pow10[i] = pow10[i - 1] * 10;
  auto substr = [&](int l, int r) -> hash {
    assert(l <= r);
    if (l)
      return a[r] - a[l - 1] * pow10[r - l];
    else
      return a[r];
  };
  if (m > 1) {
    --m;
    for (int i = m; i + m <= n; ++i)
      if (substr(i - m, i - 1) + substr(i, i + m - 1) == x) {
        std::cout << i - m + 1 << ' ' << i << '\n'
                  << i + 1 << ' ' << i + m << '\n';
        return 0;
      }
    ++m;
  }
  std::vector<int> z = zfunction(t + '#' + s);
  for (int i = 0; i + m <= n; ++i) {
    int lcp = z[i + m + 1];
    if (lcp == m) continue;
    hash t = substr(i, i + m - 1);
    if (i + (m << 1) - lcp <= n &&
        t + substr(i + m, i + (m << 1) - lcp - 1) == x) {
      std::cout << i + 1 << ' ' << i + m << '\n'
                << i + m + 1 << ' ' << i + (m << 1) - lcp << '\n';
      return 0;
    }
    if (i - m + lcp >= 0 && t + substr(i - m + lcp, i - 1) == x) {
      std::cout << i - m + lcp + 1 << ' ' << i << '\n'
                << i + 1 << ' ' << i + m << '\n';
      return 0;
    }
    if (lcp < m - 1) {
      if (i + (m << 1) - lcp - 1 <= n &&
          t + substr(i + m, i + (m << 1) - lcp - 2) == x) {
        std::cout << i + 1 << ' ' << i + m << '\n'
                  << i + m + 1 << ' ' << i + (m << 1) - lcp - 1 << '\n';
        return 0;
      }
      if (i - m + lcp + 1 >= 0 && t + substr(i - m + lcp + 1, i - 1) == x) {
        std::cout << i - m + lcp + 2 << ' ' << i << '\n'
                  << i + 1 << ' ' << i + m << '\n';
        return 0;
      }
    }
  }
  return 0;
}

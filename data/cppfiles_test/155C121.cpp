#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma G++ optimize("Ofast,no-stack-protector")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma G++ optimize("unroll-loops")
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  printf("\n");
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <class T>
inline T bigMod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T>
inline bool isprime(T n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, i, x, len;
    vector<long long> v;
    vector<pair<long long, long long> > a, b;
    string str;
    scanf("%lld", &n);
    vector<long long> res(n);
    for (i = 0; i < n; i++) {
      scanf("%lld", &x);
      v.push_back(x);
    }
    cin >> str;
    for (i = 0; i < n; i++) {
      if (str[i] != '1')
        b.push_back({v[i], i});
      else
        a.push_back({v[i], i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    len = a.size();
    for (i = len - 1; i >= 0; i--) {
      res[a[i].second] = n--;
    }
    len = b.size();
    for (i = len - 1; i >= 0; i--) {
      res[b[i].second] = n--;
    }
    int g = res.size();
    for (int i = 0; i < g; i++) {
      printf("%lld", res[i]);
      if (i < g - 1)
        printf(" ");
      else
        printf("\n");
    };
  }
  return 0;
}

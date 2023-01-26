#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
inline long long fastpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans + a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
long long powa[21];
inline void InitPow(long long Base) {
  powa[0] = 1;
  for (long long i = 1; i <= 20; i++) powa[i] = powa[i - 1] * Base % mod;
}
long long p[50];
long long n;
vector<string> anss[10];
map<long long, string> mp1, mp2;
inline long long Value(string& s, long long l, long long r) {
  long long len = s.size(), res = 0;
  for (long long i = 0; i < len; i++)
    res = (res + (i + l) * powa[s[i] - 'A' + 1]) % mod;
  return res;
}
inline void work(long long N, long long n) {
  anss[0].clear();
  string s0;
  s0 += ((1 << (N - 1)) + 'A');
  anss[0].push_back(s0);
  for (long long i = 1; i <= n; i++) {
    anss[i].clear();
    for (auto x : anss[i - 1])
      for (auto y : anss[i - 1]) {
        string news = x + y;
        long long len = news.size();
        for (long long j = 0; j < len; j++)
          if (news[j] == (1 << (N - i)) + 'A') {
            news[j] = (i == N ? 0 : (1 << (N - i - 1))) + 'A';
            anss[i].push_back(news);
            news[j] = (1 << (N - i)) + 'A';
          }
      }
  }
  for (auto x : anss[n]) {
    long long val1 = Value(x, 1, 1 << n);
    mp1[val1] = x;
    long long val2 = Value(x, (1 << n) + 1, 1 << (n + 1));
    mp2[val2] = x;
    long long len = x.size();
    for (long long i = 0; i < len; i++)
      if (x[i] == 'B') {
        x[i] = 'A';
        break;
      }
    val1 = Value(x, 1, 1 << n);
    mp1[val1] = x;
    val2 = Value(x, (1 << n) + 1, 1 << (n + 1));
    mp2[val2] = x;
  }
}
signed main() {
  long long k, Base, Hash;
  scanf("%lld %lld %lld", &k, &Base, &Hash);
  InitPow(Base);
  work(k, k - 1);
  for (auto p : mp1) {
    long long res1 = p.first;
    long long res2 = (Hash + mod - res1) % mod;
    if (mp2.find(res2) != mp2.end()) {
      string ans = p.second + mp2[res2];
      long long len = ans.size();
      for (long long i = 0; i < len; i++) printf("%d ", ans[i] - 'A' + 1);
      putchar('\n');
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const long long INF64 = 1e18 + 7;
const int MAXN = 1e5 + 2;
const int MAXMAXN = 1e6 + 10;
const double EPS = 1e-6;
const long double PI = 3.14159265358979323846;
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
int gcd(int a, int b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
long long mypow(long long a, long long n) {
  if (n == 0) return 1;
  long long tmp = mypow(a, n / 2);
  if (n & 1) return ((tmp * tmp) % MOD) * a % MOD;
  return (tmp * tmp) % MOD;
}
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<char, vector<string> > b;
    vector<int> ans(5);
    for (char ch = 'a'; ch <= 'e'; ch++) {
      int need = 0, other = 0;
      vector<int> status(n);
      for (int i = 0; i < n; i++) {
        int k = (int)a[i].size();
        int c = count(a[i].begin(), a[i].end(), ch);
        if (c > k - c)
          ans[ch - 'a']++, need += c, other += k - c, status[i] = 1;
        else
          b[ch].push_back(a[i]);
      }
      sort(b[ch].begin(), b[ch].end(), [ch](string a, string b) {
        int c1 = count(a.begin(), a.end(), ch);
        int c2 = count(b.begin(), b.end(), ch);
        return c1 - (int)a.size() > c2 - (int)b.size();
      });
      for (int i = 0; i < n; i++) {
        int c = count(a[i].begin(), a[i].end(), ch);
        if (need + c > other + (int)a[i].size() - c && status[i] != 1)
          ans[ch - 'a']++, need += c, other += (int)a[i].size() - c;
      }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
  }
  return 0;
}

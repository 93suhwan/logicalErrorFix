#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
const double pi = 3.141592653589793238460;
template <typename T, typename T1>
T ama(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amm(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 3e6 + 5;
void fun() {
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  ;
  string s;
  cin >> s;
  ;
  long long a[10][n + 5];
  memset(a, 0, sizeof(a));
  string t = "abc";
  long long ct = 0;
  do {
    for (long long i = 0; i < n; i++) {
      a[ct][i + 1] = a[ct][i] + (s[i] != t[i % 3]);
    }
    ct++;
  } while (next_permutation((t).begin(), (t).end()));
  while (m--) {
    long long l;
    cin >> l;
    long long r;
    cin >> r;
    ;
    long long p = n;
    for (long long i = 0; i < 6; i++) {
      p = min(p, a[i][r] - a[i][l - 1]);
    }
    cout << p << '\n';
    ;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    fun();
  }
  return 0;
}

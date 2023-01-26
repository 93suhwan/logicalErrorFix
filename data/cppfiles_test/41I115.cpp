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
string t;
long long d;
long long mn = 1e18;
long long n, m;
long long ck(string x) {
  long long l = (int(x.size())) / 2 + ((int(x.size())) % 2 != 0);
  for (long long i = 0; i < d; i++) {
    if (i + 1 < d && x[i] == x[i + 1]) return -1;
    if (i + 2 < d && x[i] == x[i + 2]) return -1;
    if (i + 5 < d && x[i] == x[i + 3] && x[i + 1] == x[i + 4] &&
        x[i + 2] == x[i + 5]) {
      return -1;
    }
  }
  long long ct = 0;
  for (long long i = 0; i < d; i++) {
    if (t[i] != x[i]) ct++;
  }
  return ct;
}
void g(string x) {
  if ((int(x.size())) == d) {
    long long l = ck(x);
    if (l == -1) {
      return;
    }
    mn = min(mn, l);
    return;
  }
  g(x + "a");
  g(x + "b");
  g(x + "c");
}
void fun() {
  cin >> n >> m;
  ;
  string s;
  cin >> s;
  ;
  while (m--) {
    long long l;
    cin >> l;
    long long r;
    cin >> r;
    ;
    mn = 1e18;
    d = r - l + 1;
    t = s.substr(l - 1, d);
    string s2 = "";
    g(s2);
    cout << mn << '\n';
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

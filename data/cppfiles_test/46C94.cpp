#include <bits/stdc++.h>
using namespace std;
using str = string;
inline void __print(int x) { cerr << x; }
inline void __print(long x) { cerr << x; }
inline void __print(long long x) { cerr << x; }
inline void __print(unsigned x) { cerr << x; }
inline void __print(unsigned long x) { cerr << x; }
inline void __print(unsigned long long x) { cerr << x; }
inline void __print(float x) { cerr << x; }
inline void __print(double x) { cerr << x; }
inline void __print(long double x) { cerr << x; }
inline void __print(char x) { cerr << '\'' << x << '\''; }
inline void __print(const char *x) { cerr << '\"' << x << '\"'; }
inline void __print(const string &x) { cerr << '\"' << x << '\"'; }
inline void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T>
inline void __print(vector<T> &v) {
  for (auto x : v) {
    cerr << x << " ";
  }
}
template <typename T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const int MAXN = 1000005;
const int MOD = 1e9 + 7;
inline string IntToString(long long a) {
  char x[100];
  sprintf(x, "%lld", a);
  string second = x;
  return second;
}
inline long long StringToInt(string a) {
  char x[100];
  long long res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
inline string GetString(void) {
  char x[MAXN];
  scanf("%s", x);
  string second = x;
  return second;
}
inline string uppercase(string second) {
  int n = int((second).size());
  for (int(i) = 0; i < n; i++)
    if (second[i] >= 'a' && second[i] <= 'z') second[i] = second[i] - 'a' + 'A';
  return second;
}
inline string lowercase(string second) {
  int n = int((second).size());
  for (int(i) = 0; i < n; i++)
    if (second[i] >= 'A' && second[i] <= 'Z') second[i] = second[i] - 'A' + 'a';
  return second;
}
struct UF {
  int n;
  vector<int> par;
  UF(int _n) : n(_n) {
    for (int i = 0; i < n; i++) par.push_back(i);
  }
  int find(int a) {
    if (a != par[a]) par[a] = find(par[a]);
    return par[a];
  }
  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    par[a] = b;
    return (a != b);
  }
};
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
vector<int> lp, pr;
void sieve(int sz) {
  lp.resize(sz + 1);
  for (int i = 2; i <= sz; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= sz;
         j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &x : v) {
    cin >> x;
  }
  long long mx = v.back();
  int cnt = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] > mx) {
      mx = v[i];
      cnt++;
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

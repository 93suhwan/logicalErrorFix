#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long int INF = 1e18;
const int MX = 2e5 + 1;
template <class T>
void ckmin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T& a, T b) {
  a = max(a, b);
}
namespace io {
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
template <class T>
struct like_array : is_array<T> {};
template <class T, size_t N>
struct like_array<array<T, N>> : true_type {};
template <class T>
struct like_array<vector<T>> : true_type {};
template <class T>
bool is_like_array(const T& a) {
  return like_array<T>::value;
}
template <class T>
void re(T& x) {
  cin >> x;
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest);
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(long double& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (long long int i = 0; i < ((int)a.size()); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (long long int i = 0; i < (SZ); i++) re(a[i]);
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& a) {
  os << '{' << a.first << ", " << a.second << '}';
  return os;
}
template <class T>
ostream& printArray(ostream& os, const T& a, int SZ) {
  os << '{';
  for (long long int i = 0; i < (SZ); i++) {
    if (i) {
      os << ", ";
      if (is_like_array(a[i])) cout << "\n";
    }
    os << a[i];
  }
  os << '}';
  return os;
}
template <class T, size_t SZ>
ostream& operator<<(ostream& os, const array<T, SZ>& a) {
  return printArray(os, a, SZ);
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  return printArray(os, a, (int)a.size());
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& a) {
  os << vector<T>(a.begin(), a.end());
  return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2>& a) {
  os << vector<pair<T1, T2>>(a.begin(), a.end());
  return os;
}
template <class T>
void pr(const T& x) {
  cout << x << '\n';
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  cout << first << ' ';
  pr(rest...);
}
}  // namespace io
using namespace io;
vector<long long int> adj[MX];
vector<bool> taken;
vector<long long int> szs;
vector<pair<long long int, long long int>> oks;
long long int r, b;
int dsz(int u, int p) {
  int c = 1;
  for (auto& x : adj[u])
    if (x != p) {
      c += dsz(x, u);
    }
  szs[u] = c;
  return c;
}
void findoks(int u, int p, long long int s) {
  if (u != 0 && adj[u].size() == 1) {
    oks.push_back(make_pair(s, u));
    return;
  }
  int hea_u = -1;
  for (auto& x : adj[u])
    if (x != p) {
      if (hea_u == -1 || szs[hea_u] < szs[x]) hea_u = x;
    }
  for (auto& x : adj[u])
    if (x != p) {
      if (hea_u == x)
        findoks(x, u, max(s, szs[x]));
      else
        findoks(x, u, szs[x]);
    }
  return;
}
bool findrb(int u, int p) {
  if (u != 0 && adj[u].size() == 1) {
    if (taken[u])
      r++;
    else
      b++;
    return taken[u];
  }
  bool tak = false;
  for (auto& x : adj[u])
    if (x != p) {
      tak |= findrb(x, u);
    }
  if (tak)
    r++;
  else
    b++;
  return tak;
}
void solve() {
  long long int n, k;
  re(n, k);
  szs.resize(n);
  taken.resize(n, false);
  for (long long int i = 0; i < (n - 1); i++) {
    int x, y;
    re(x, y);
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dsz(0, -1);
  findoks(0, -1, szs[0]);
  sort(oks.begin(), oks.end());
  reverse(oks.begin(), oks.end());
  for (long long int i = 0; i < (min(k, (long long int)oks.size())); i++)
    taken[oks[i].second] = true;
  findrb(0, -1);
  r = min(r, k);
  long long int w = n - (r + b);
  long long int ans = w * (r - b);
  for (long long int i = (oks.size()); i < (k + 1); i++) {
    w = n - (i + b);
    ans = max(ans, w * (i - b));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

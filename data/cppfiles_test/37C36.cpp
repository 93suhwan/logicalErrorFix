#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << "{" << a.first << ", " << a.second << "}";
  return out;
}
const int mod = 998244353;
template <typename T>
void print(T &a) {
  for (auto &x : a) cout << x << " ";
  cout << "\n";
}
int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = res * 1ll * x % mod;
    y = y >> 1;
    x = x * 1ll * x % mod;
  }
  return res;
}
const int N = 1e5 + 10;
vector<int> adj[N];
void addedge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool notpossible;
int dfs(int v, int p, int d) {
  if (notpossible) {
    return 0;
  }
  int my = 0;
  for (auto &x : adj[v]) {
    if (x == p) continue;
    int tmp = dfs(x, v, d);
    if (tmp == 0)
      my++;
    else if (tmp + 1 == d)
      continue;
    else {
      notpossible = 1;
      return 0;
    }
  }
  return (my) % d;
}
int ans[N];
int real_ans[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < (n + 1); i++) adj[i].clear();
  for (int i = 0; i < (n - 1); i++) {
    int t1, t2;
    cin >> t1 >> t2;
    addedge(t1, t2);
  }
  ans[1] = power(2, (n - 1));
  for (int i = 2; i < (n + 1); i++) {
    if ((n - 1) % i) continue;
    notpossible = 0;
    int tmp = dfs(1, -1, i);
    if (notpossible || tmp) {
      ans[i] = 0;
    } else {
      ans[i] = 1;
    }
  }
  for (int i = 1; i < (n + 1); i++) {
    ;
  }
  for (int i = (n + 1) - 1; i >= 1; i--) {
    if ((n - 1) % i) {
      real_ans[i] = 0;
      continue;
    }
    int x = 2 * i;
    real_ans[i] = ans[i];
    while (x <= n) {
      if (i == 1) {
        ;
      }
      real_ans[i] -= real_ans[x];
      x += i;
    }
  }
  for (int i = 1; i < (n + 1); i++) cout << real_ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop1 - start1);
  return 0;
}

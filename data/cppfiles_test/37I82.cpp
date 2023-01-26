#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void deb_print(string s, Args&&... arg) {
  static const string limiter = "\n";
  cerr << s << " : ";
  cerr << (..., (cout << arg << ' ', limiter));
}
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int MAX = 1e9, MIN = -MAX, MOD = 998244353;
const ll MAX_LL = 1e18, MIN_LL = -MAX_LL;
vi adjl[100001];
bool visited[100001];
int par[100001], degree[100001], root;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline int binpow(int num, int derajat) {
  int ret = 1;
  for (int i = 1; i <= derajat; i <<= 1, num = (ll)num * num % MOD)
    if (i & derajat) ret = (ll)ret * num % MOD;
  return ret;
}
void dfs(int);
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      adjl[i].clear();
      visited[i] = par[i] = 0;
    }
    for (int i = 1; i < N; ++i) {
      int a, b;
      cin >> a >> b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
      if (adjl[i].size() > 1) root = i;
      degree[i] = adjl[i].size();
    }
    par[root] = 0;
    dfs(root);
    for (int i = 1; i <= N; ++i)
      if (degree[i] == 1 && !visited[par[i]]) {
        visited[par[i]] = true;
        q.push(par[i]);
      }
    int all_gcd = 0;
    while (q.size()) {
      int node = q.front();
      q.pop();
      all_gcd = gcd(all_gcd, degree[node]);
      for (int it : adjl[node]) degree[it]--;
      if (par[par[node]] && !visited[par[par[node]]]) {
        visited[par[par[node]]] = true;
        q.push(par[par[node]]);
      }
    }
    int ans = binpow(2, N - 1);
    if (all_gcd > 1) {
      ans = ans - 1;
      if (ans < 0) ans += MOD;
    }
    cout << ans;
    for (int i = 2; i <= N; ++i) {
      if (i != all_gcd)
        cout << " 0";
      else
        cout << " 1";
    }
    cout << '\n';
  }
}
void dfs(int node) {
  for (int it : adjl[node])
    if (it != par[node]) {
      par[it] = node;
      dfs(it);
    }
}

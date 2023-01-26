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
bool possible[100001];
int par[100001], depth[100001], degree[100001];
int binpow(int num, int derajat) {
  int ret = 1;
  for (int i = 1; i <= derajat; i <<= 1, num = (ll)num * num % MOD)
    if (i & derajat) ret = (ll)ret * num % MOD;
  return ret;
}
bool cmp(int a, int b) { return depth[a] > depth[b]; }
void dfs(int);
int main() {
  vi prime;
  bool computed[(int)1e5 + 1] = {};
  for (int i = 2; i <= 100000; ++i)
    if (!computed[i]) {
      prime.push_back(i);
      if ((ll)i * i <= 100000)
        for (int j = i * i; j <= 100000; j += i) computed[j] = true;
    }
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
      adjl[i].clear();
      possible[i] = false;
    }
    for (int i = 1; i < N; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    if (N == 2) {
      puts("2 0");
      continue;
    }
    int root;
    for (int i = 1; i <= N; ++i)
      if (adjl[i].size() > 1) {
        root = i;
        par[i] = depth[i] = 0;
        dfs(i);
        break;
      }
    int urut_node[N];
    for (int i = 0; i < N; ++i) urut_node[i] = i + 1;
    sort(urut_node, urut_node + N, cmp);
    for (int it : prime) {
      if (it > N) break;
      int mini = MAX;
      fill(degree + 1, degree + N + 1, 1);
      degree[root] = 0;
      bool sukses = true;
      for (int i = 0; i + 1 < N; ++i) {
        int h_mod = degree[urut_node[i]] % it;
        if (h_mod) {
          if (h_mod > 1) {
            sukses = false;
            break;
          }
          ++degree[par[urut_node[i]]];
          --degree[urut_node[i]];
        }
        if (degree[urut_node[i]]) mini = min(mini, degree[urut_node[i]]);
      }
      if (sukses && degree[root] % it == 0) {
        if (degree[root]) mini = min(mini, degree[root]);
        possible[mini] = true;
      }
    }
    int sum = 0;
    for (int i = 1; i <= N; ++i) sum += possible[i];
    printf("%d", (binpow(2, N - 1) - sum + MOD) % MOD);
    for (int i = 2; i <= N; ++i) printf(" %d", possible[i]);
    puts("");
  }
}
void dfs(int node) {
  for (int it : adjl[node])
    if (it != par[node]) {
      depth[it] = depth[node] + 1;
      par[it] = node;
      dfs(it);
    }
}

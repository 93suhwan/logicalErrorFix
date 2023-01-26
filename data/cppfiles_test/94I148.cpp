#include <bits/stdc++.h>
using namespace std;
void adde(vector<long long int> adj[], long long int u, long long int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void BFS(vector<long long int> adj[], long long int bfs[], long long int s,
         long long int n) {
  bool *visited = new bool[n + 1];
  for (long long int i = 0; i < n + 1; i++) visited[i] = false;
  list<long long int> queue;
  visited[s] = true;
  bfs[s] = 0;
  queue.push_back(s);
  vector<long long int>::iterator i;
  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      if (!visited[*i]) {
        visited[*i] = true;
        bfs[*i] = bfs[s] + 1;
        queue.push_back(*i);
      }
    }
  }
}
long long int nCrModp(long long int n, long long int r, long long int p) {
  if (r > n - r) r = n - r;
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long int find_center(long long int n, vector<long long int> adj[]) {
  queue<long long int> q;
  bool vis[n + 1];
  long long int cnt[n + 1];
  for (long long int i = 1; i <= n; i++) {
    vis[i] = false;
    cnt[i] = adj[i].size();
    if (cnt[i] == 1) q.push(i);
  }
  while (q.size() > 1) {
    long long int cur = q.front();
    vis[cur] = true;
    q.pop();
    for (long long int i = 0; i < adj[cur].size(); i++) {
      if (!vis[adj[cur][i]]) {
        cnt[adj[cur][i]]--;
        if (cnt[adj[cur][i]] == 1) q.push(adj[cur][i]);
      }
    }
  }
  return q.front();
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int get_rand(long long int l, long long int r) {
  uniform_int_distribution<long long int> uid(l, r);
  return uid(rng);
}
long long int a[100] = {0};
void adder(long long int i, long long int j) {
  long long int dp[2] = {0};
  long long int mul = 1, temp = 0;
  while (i > 0 || j > 0) {
    long long int ai = i % 10, aj = j % 10;
    i /= 10;
    j /= 10;
    long long int sum = ai + aj + dp[0];
    dp[0] = dp[1];
    if (sum >= 10) {
      dp[1] = 1;
    } else
      dp[1] = 0;
    sum = sum % 10;
    temp += sum * mul;
    mul *= 10;
  }
  if (dp[0] > 0) temp += mul;
  if (dp[1] > 0) temp += 10 * mul;
  if (temp < 100) a[temp]++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = 1; i < 100; i++) {
    for (long long int j = 1; j < 100; j++) adder(i, j);
  }
  while (t--) {
    long long int n;
    cin >> n;
    if (n < 100)
      cout << a[n] << "\n";
    else {
      long long int ans = sqrt(n);
      if (ans * ans == n) ans--;
      cout << ans << "\n";
    }
  }
  return 0;
}

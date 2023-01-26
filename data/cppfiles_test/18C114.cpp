#include <bits/stdc++.h>
using namespace std;
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long ncr(long long n, long long k, long long m) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res = mod_mul(res, (n - i), 1000000007);
    res = mod_div(res, i + 1, 1000000007);
  }
  return res;
}
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void bfs(vector<vector<int>> &adj, int source, int n) {
  bool visited[n + 1];
  queue<int> q;
  vector<int> distance(n), parent(n);
  q.push(source);
  parent[source] = -1;
  visited[source] = true;
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int u : adj[s]) {
      if (!visited[u]) {
        visited[u] = true;
        q.push(u);
        distance[u] = distance[s] + 1;
        parent[u] = s;
      }
    }
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> v1;
  vector<bool> mark(2 * n + 1);
  vector<long long> v;
  long long a, b;
  for (long long i = 0; i < k; i++) {
    cin >> a >> b;
    v1.push_back({min(a, b), max(a, b)});
    mark[a] = true;
    mark[b] = true;
  }
  for (long long i = 1; i <= 2 * n; i++) {
    if (mark[i] == false) v.push_back(i);
  }
  long long ck = v.size();
  for (long long i = 0; i < ck / 2; i++) {
    v1.push_back({v[i], v[ck / 2 + i]});
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (((v1[i].first < v1[j].first && v1[i].second < v1[j].second) ||
           (v1[i].first > v1[j].first && v1[i].second > v1[j].second)) &&
          ((v1[j].first <= v1[i].first && v1[j].second >= v1[i].first) ||
           (v1[j].first <= v1[i].second && v1[j].second >= v1[i].second) ||
           (v1[i].first <= v1[j].first && v1[i].second >= v1[j].first) ||
           v1[i].first <= v1[j].second && v1[i].second >= v1[j].second)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

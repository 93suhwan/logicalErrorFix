#include <bits/stdc++.h>
using namespace std;
int cal(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  long long int temp = a;
  while (b > 0) {
    if (b & 1) ans = (ans % mod * temp % mod) % mod;
    temp = (temp % mod * temp % mod) % mod;
    b = b / 2;
  }
  return ans;
}
int XOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  if (n % 4 == 3) return 0;
}
void sieve(int n) {
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = 1;
    a[0] = 0;
    a[1] = 0;
  }
  for (int i = 2; i * i < n; i++) {
    if (a[i] == 1) {
      for (int j = i * i; j < n; j = j + i) a[j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) cout << i << " ";
  }
}
bool isprime(long long int n) {
  long long int f = 0;
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      f = 1;
      break;
    }
  }
  if (f == 0)
    return true;
  else
    return false;
}
bool sortsec(const pair<long long int, long long int>& a,
             const pair<long long int, long long int>& b) {
  return (a.second < b.second);
}
bool cmp1(pair<string, long long int> a, pair<string, long long int> b) {
  if (a.second != b.second)
    return b.second < a.second;
  else
    return b.first > a.first;
}
long long int vis[100002] = {0};
long long int col[100002] = {0};
long long int dis[100002] = {0};
long long int n;
long long int c[100002];
void dfs(long long int node, vector<long long int> v[]) {
  vis[node] = 1;
  for (long long int child : v[node]) {
    if (vis[child] == 0) {
      dfs(child, v);
    }
  }
}
void bfs(long long int node, vector<long long int> v[]) {
  col[node] = c[node];
  queue<long long int> q;
  q.push(node);
  while (q.size() > 0) {
    long long int curr = q.front();
    q.pop();
    for (long long int child : v[curr]) {
      if (col[child] != col[node]) {
        q.push(child);
        col[child] = c[node];
      }
    }
  }
}
bool dfs1(long long int node, vector<long long int> v[], long long int c) {
  col[node] = c;
  for (long long int child : v[node]) {
    if (col[child] == col[node])
      return false;
    else if (col[child] == -1) {
      if (!dfs1(child, v, c ^ 1)) return false;
    }
  }
  return true;
}
bool isbipartite(long long int node, long long int col[],
                 vector<long long int> v[]) {
  col[node] = 1;
  queue<long long int> q;
  q.push(node);
  while (q.size() > 0) {
    long long int u = q.front();
    q.pop();
    for (long long int child : v[u]) {
      if (col[child] == col[u])
        return false;
      else if (col[child] == -1) {
        col[child] = 1 - col[u];
        q.push(child);
      }
    }
  }
  return true;
}
bool bipartite(vector<long long int> v[]) {
  for (long long int i = 1; i <= n; i++) {
    if (col[i] == -1)
      if (isbipartite(i, col, v) == false) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, x = 3;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      cout << x << " ";
      x = x + 2;
    }
    cout << endl;
  }
}

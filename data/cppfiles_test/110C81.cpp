#include <bits/stdc++.h>
using namespace std;
long long N = 1e9 + 7;
bool isprime(long long a) {
  for (long long i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}
long long pow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b = b / 2;
  }
  return ans;
}
long long binary(long long a, long long b) {
  long long res = 1;
  a = a;
  while (b) {
    if (b & 1) res = ((res % N) * (a % N)) % N;
    a = ((a % N) * (a % N)) % N;
    res = res % N;
    b = b >> 1;
  }
  return res;
}
long long modinverse(long long a, long long b) { return binary(a, b - 2); }
void _print(long long a) { cerr << a << " "; }
void _print(float a) { cerr << a << " "; }
void _print(char a) { cerr << a << "\n"; }
void _print(string a) { cerr << a << " "; }
void _print(bool a) { cerr << a << " "; }
void _print(double a) { cerr << a << " "; }
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
  }
  cerr << " ]";
}
template <class T, class V>
void _print(map<T, V> m) {
  for (auto u : m) {
    cerr << u.first << " " << u.second << "\n";
  }
}
template <class T, class V>
void _print(multimap<T, V> m) {
  for (auto u : m) {
    cerr << u.first << " " << u.second << "\n";
  }
}
template <class T>
void _print(set<T> s) {
  cerr << "[";
  for (auto i : s) cerr << i << " ";
  cerr << "]";
}
template <class T>
void _print(multiset<T> s) {
  cerr << "[";
  for (auto i : s) cerr << i << " ";
  cerr << "]";
}
long long gcd(long long a, long long b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
};
long long add(long long a, long long b) { return (a % N + b % N) % N; }
long long cycle_start, cycle_end;
bool dfs(long long v, vector<long long> adj[], vector<long long> &color,
         vector<long long> &parent) {
  color[v] = 1;
  for (long long u : adj[v]) {
    if (color[u] == 0) {
      parent[u] = v;
      if (dfs(u, adj, color, parent)) return true;
    } else if (color[u] == 1) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
  }
  color[v] = 2;
  return false;
}
bool find_cycle(vector<long long> adj[], long long n) {
  vector<long long> color;
  vector<long long> parent;
  color.assign(n, 0);
  parent.assign(n, -1);
  cycle_start = -1;
  for (long long v = 0; v < n; v++) {
    if (color[v] == 0 && dfs(v, adj, color, parent)) break;
  }
  if (cycle_start == -1) {
    return false;
  } else {
    return true;
  }
}
void topologicalSortUtil(long long v, vector<long long> adj[], bool visited[],
                         stack<long long> &Stack) {
  visited[v] = true;
  list<long long>::iterator i;
  for (auto u : adj[v])
    if (!visited[u]) topologicalSortUtil(u, adj, visited, Stack);
  Stack.push(v);
}
void topologicalSort(vector<long long> adj[], long long V,
                     vector<set<long long>> &s, vector<long long> &dp) {
  stack<long long> Stack;
  bool *visited = new bool[V];
  for (long long i = 0; i < V; i++) visited[i] = false;
  for (long long i = 0; i < V; i++)
    if (visited[i] == false) topologicalSortUtil(i, adj, visited, Stack);
  while (Stack.empty() == false) {
    long long a = Stack.top();
    long long ans = 1;
    for (auto u : s[a]) {
      if (u < a)
        ans = max(ans, dp[u]);
      else
        ans = max(ans, dp[u] + 1);
    }
    Stack.pop();
    dp[a] = ans;
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> adj[n];
  vector<set<long long>> s(n);
  vector<long long> dp(n, 1e14 + 2);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    if (k == 0) dp[i] = 1;
    while (k--) {
      long long a;
      cin >> a;
      a--;
      adj[a].push_back(i);
      s[i].insert(a);
    };
  }
  bool ans = find_cycle(adj, n);
  if (ans)
    cout << "-1"
         << "\n";
  else {
    topologicalSort(adj, n, s, dp);
    long long ans = 1;
    for (auto x : dp) ans = max(ans, x);
    cout << ans << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

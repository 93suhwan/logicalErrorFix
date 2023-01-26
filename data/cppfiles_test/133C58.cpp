#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void init() {}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void google(int t) { cout << "Case #" << t << ": "; }
string upper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
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
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
set<int> primeFactors(int n) {
  set<int> s;
  while (n % 2 == 0) {
    s.insert(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.insert(i);
      n = n / i;
    }
  }
  if (n > 2) s.insert(n);
  return s;
}
void sort(string &s) { sort(s.begin(), s.end()); }
void bfs(bool visited[], vector<int> adj[], int i) {
  queue<int> q;
  q.push(i);
  visited[i] = true;
  while (q.size() != 0) {
    int j = q.front();
    cout << j << " ";
    q.pop();
    for (auto k : adj[j]) {
      if (!visited[k]) {
        visited[k] = true;
        q.push(k);
      }
    }
  }
}
bool cycle(vector<int> adj[], bool vis[], int src, bool dfsvis[]) {
  vis[src] = 1;
  dfsvis[src] = 1;
  for (auto i : adj[src]) {
    if (!vis[i]) {
      if (cycle(adj, vis, i, dfsvis)) return true;
    }
    if (vis[i] && dfsvis[i]) return true;
  }
  dfsvis[src] = 0;
  return false;
}
void dfs(vector<int> adj[], bool vis[], int src) {
  vis[src] = true;
  for (auto i : adj[src]) {
    if (!vis[src]) dfs(adj, vis, i);
  }
  cout << src << " ";
}
void dijkstra(vector<pair<int, int>> adj[], int n, int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int dis[n];
  for (int i = 0; i < n; i++) dis[i] = INT_MAX;
  dis[0] = 0;
  pq.push({0, src});
  while (pq.size() != 0) {
    pair<int, int> p = pq.top();
    pq.pop();
    for (auto k : adj[p.second]) {
      if (p.first + k.second < dis[k.first]) {
        dis[k.first] = p.first + k.second;
        pq.push({dis[k.first], k.first});
      }
    }
  }
  for (auto i : dis) cout << i << " ";
  cout << "\n";
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.second.first < b.second.first;
}
int main() {
  init();
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string s = a;
    for (int i = 1; i < n - 2; i++) {
      cin >> a;
      if (s[s.size() - 1] == a[0])
        s = s + a[1];
      else
        s = s + a;
    }
    if (s.size() == n)
      cout << s << "\n";
    else
      cout << s + 'a' << "\n";
  }
}

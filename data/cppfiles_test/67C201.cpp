#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll x, ll k, ll M) {
  ll res = 1;
  while (k) {
    if (k & 1) {
      res = (res * x) % M;
      --k;
    } else {
      x = (x * x) % M;
      k >>= 1;
    }
  }
  return res;
}
ll factmod(ll n, ll p) {
  ll res = 1;
  while (n > 1) {
    res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
    for (int i = 2; i <= (n % p); ++i) res = (res * i) % p;
    n /= p;
  }
  return res % p;
}
void eratosfen(vector<ll>& lp, vector<char>& prime, ll n) {
  for (int i = 2; i * i <= n; ++i)
    if (prime[i])
      for (int j = 2; j <= n / i; j++)
        if (prime[i * j]) {
          prime[i * j] = false;
          lp[j * i] = i;
        }
}
struct Gcd {
  ll g, x, y;
};
Gcd gcd(ll a, ll b) {
  if (a == 0) return Gcd{b, 0, 1};
  auto res = gcd(b % a, a);
  return Gcd{res.g, res.y - (b / a) * res.x, res.x};
}
struct edge {
  int from, to;
};
vector<int> tout;
vector<int> tin;
int timer = 0;
vector<int> dist;
int cs = 0;
int cf = 0;
int cnt;
int to = 0;
void dfs(int v, vector<vector<int>>& g, vector<bool>& used, vector<int>& p) {
  used[v] = true;
  cnt++;
  for (int u : g[v]) {
    tin.push_back(u + 1);
    if (!used[u]) {
      p[u] = v;
      dfs(u, g, used, p);
      if (to == 0) to = u;
    }
  }
}
void bfs(int s, vector<int>& dist, vector<vector<int>>& g, vector<int>& p) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  p[s] = -1;
  cout << s + 1 << ' ';
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v]) {
      if (dist[u] > dist[v] + 1) {
        cout << u + 1 << ' ';
        dist[u] = dist[v] + 1;
        q.push(u);
        p[u] = v;
      }
    }
  }
  cout << '\n';
}
const int INF = 1e9;
struct Vector {
  long double x, y;
  long double len() { return sqrt(x * x + y * y); }
  Vector operator+(Vector& other) { return Vector{x + other.x, y + other.y}; }
  Vector operator-(Vector& other) { return {x - other.x, y - other.y}; }
  Vector& operator+=(Vector& other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  Vector& operator-=(Vector& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
  long double dot_product(Vector& other) { return x * other.x + y * other.y; }
  long double cross_product(Vector& other) { return x * other.y - y * other.x; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int o = 0; o < t; o++) {
    int a, b, c;
    cin >> a >> b >> c;
    int d = max(a, b) - min(a, b);
    int siz = d * 2;
    int cd;
    if (c > d)
      cd = c - d;
    else
      cd = c + d;
    if (siz % 2 != 0)
      cout << -1 << '\n';
    else if (max(c, cd) > siz || max(a, b) > siz)
      cout << -1 << '\n';
    else
      cout << cd << '\n';
  }
}

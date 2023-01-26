#include <bits/stdc++.h>
using namespace std;
const long long N = 100001;
const unsigned long long p = 29;
string s;
unsigned long long mhash[N];
unsigned long long mp[N];
queue<long long> q;
long long dist[10000000];
long long path[10000000];
long long used[10000000];
vector<vector<long long> > g;
void bfs(long long a) {
  q.push(a);
  dist[a] = 0;
  used[a] = true;
  long long k = 0;
  while (!q.empty()) {
    long long cur = q.front();
    q.pop();
    for (long long i = 0; i < g[cur].size(); i++) {
      if (!used[g[cur][i]]) {
        q.push(g[cur][i]);
        used[g[cur][i]] = true;
        dist[g[cur][i]] = dist[cur] + 1;
        path[g[cur][i]] = cur;
      }
    }
    k++;
  }
}
void dfs(long long v) {
  if (used[v] == 0) {
    used[v] = 1;
  }
  for (long long i = 0; i < g[v].size(); i++) {
    long long u = g[v][i];
    if (used[u] == 0) {
      dfs(u);
    }
  }
}
void compare_string_cashes() {
  cin >> s;
  mp[0] = 1;
  mhash[0] = s[0] - 'a' + 1;
  for (long long i = 1; i < s.size(); i++) {
    mp[i] = mp[i - 1] * p;
    mhash[i] = mhash[i - 1] + (s[i] - 'a' + 1) * mp[i];
  }
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--;
    r1--;
    l2--;
    r2--;
    unsigned long long h1 = mhash[r1];
    unsigned long long h2 = mhash[r2];
    if (l1 > 0) h1 = h1 - mhash[l1 - 1];
    if (l2 > 0) h2 = h2 - mhash[l2 - 1];
    if (l2 > l1)
      h1 *= mp[l2 - l1];
    else
      h2 *= mp[l1 - l2];
    if (h1 == h2)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
}
struct Node {
  long long val = 0;
  long long promise = 0;
  long long linkl;
  long long linkr;
};
vector<Node> nodes;
vector<long long> a;
long long add_node() {
  long long id = nodes.size();
  nodes.push_back(Node());
  return id;
}
void build(long long id, long long l, long long r) {
  auto& v = nodes[id];
  if (l == r) {
    nodes[id].val = a[l];
    return;
  }
  nodes[id].linkl = add_node();
  nodes[id].linkr = add_node();
  long long mid = (l + r) / 2;
  build(v.linkl, l, mid);
  build(v.linkr, mid + 1, r);
  nodes[id].val = min(nodes[v.linkl].val, nodes[v.linkr].val);
}
long long get_Sum(long long id, long long tl, long long tr, long long l,
                  long long r) {
  auto& v = nodes[id];
  if (l <= tl && tr <= r) {
    return v.val;
  }
  if (r < tl || tr < l) {
    return 1e9;
  }
  long long mid = (tr + tl) / 2;
  return min(get_Sum(v.linkl, tl, mid, l, r),
             get_Sum(v.linkr, mid + 1, tr, l, r));
}
void Update(long long id, long long tl, long long tr, long long pos,
            long long val) {
  auto& v = nodes[id];
  if (tl == tr) {
    v.val = val;
    return;
  }
  long long mid = (tl + tr) / 2;
  if (pos <= mid) {
    Update(v.linkl, tl, mid, pos, val);
  } else {
    Update(v.linkr, mid + 1, tr, pos, val);
  }
  v.val = min(nodes[v.linkl].val, nodes[v.linkr].val);
}
void build_derevo() {
  long long n;
  cin >> n;
  nodes.reserve(n * 4);
  a.resize(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long root = add_node();
  build(root, 1, n);
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    char op;
    long long a, b;
    cin >> op >> a >> b;
    if (op == '?') {
      long long ans = get_Sum(0, 1, n, a, b);
      cout << ans << '\n';
    } else {
      Update(0, 1, n, a, b);
    }
  }
}
struct my {
  long long a, b, c, d;
};
bool comp(my a, my b) { return a.b > b.b; }
long long modFact(long long n, long long p, long long a = 1, long long b = 1) {
  if (n == 0) {
    return 1;
  }
  if (n >= p) return 0;
  long long result = 1;
  for (long long i = 1; i <= n; i++) {
    if (i == a) {
      result = (result * b) % p;
      continue;
    }
    result = (result * i) % p;
  }
  return result;
}
long long binpow(long long a, long long b, long long m = 0) {
  if (m == 0) {
    long long res = 1;
    while (b > 0) {
      if (b & 1) res = res * a;
      a = a * a;
      b >>= 1;
    }
    return res;
  }
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if ((n % i == 0) || (n % (i + 2) == 0)) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      cout << "YES" << '\n';
    } else {
      long long f = 0;
      for (long long i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
          f = 1;
          break;
        }
      }
      if (f == 1) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
}

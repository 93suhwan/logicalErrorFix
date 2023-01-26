#include <bits/stdc++.h>
using namespace std;
long long M = 1000003;
long long INF = 1e18;
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void yesno(bool ans) {
  if (ans) {
    cout << "yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
vector<long long> prefix(string s) {
  long long n = s.length();
  vector<long long> pre(n);
  pre[0] = 0;
  for (long long i = 1; i < n; i++) {
    long long j = pre[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pre[j - 1];
    }
    if (s[i] == s[j]) j++;
    pre[i] = j;
  }
  return pre;
}
class doublet {
 public:
  long long x, y, z;
};
void input(vector<long long> &a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void print(vector<long long> &a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
doublet extended_gcd(long long a, long long b) {
  if (b == 0) {
    doublet base;
    base.x = 1;
    base.y = 0;
    base.z = a;
    return base;
  }
  doublet small = extended_gcd(b, a % b);
  doublet ans;
  ans.x = small.y;
  ans.y = (small.x - (a / b) * small.y);
  ans.z = small.z;
  return ans;
}
long long inverse(long long x, long long m) {
  doublet invr = extended_gcd(x, m);
  long long inv = invr.x;
  return (inv % m + m) % m;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void multiply(unsigned long long a[2][2], unsigned long long b[2][2]) {
  unsigned long long ans[2][2];
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      unsigned long long x = 0;
      for (long long k = 0; k < 2; k++) {
        x += (a[i][k] * b[k][j]) % M;
        x %= M;
      }
      ans[i][j] = x;
    }
  }
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      a[i][j] = ans[i][j];
    }
  }
  return;
}
void exopnentiation(unsigned long long a[2][2], unsigned long long x) {
  if (x == 0 || x == 1) return;
  exopnentiation(a, x / 2);
  multiply(a, a);
  if (x & 1) {
    unsigned long long m[2][2] = {{1, 1}, {1, 0}};
    multiply(a, m);
  }
}
unsigned long long fibonacci(unsigned long long x) {
  if (x == 0) return 0;
  unsigned long long m[2][2] = {{1, 1}, {1, 0}};
  exopnentiation(m, x - 1);
  return m[0][0];
}
long long modexponentation(long long x, long long n) {
  if (x == 0) return 0;
  if (n == 0) return 1;
  long long smallans = modexponentation(x, n / 2);
  smallans = (smallans * smallans) % M;
  if (n & 1) {
    smallans = (smallans * x) % M;
  }
  return smallans;
}
long long inverseprime(long long x, long long p) {
  return modexponentation(x, p - 2);
}
class segtree {
 public:
  long long *arr;
  long long n;
  long long *tree;
  segtree(long long *arr, long long n) {
    this->arr = arr;
    this->n = n;
    tree = new long long[4 * n];
  }
  void build(long long l, long long r, long long n) {
    if (l == r) {
      tree[n] = arr[l];
      return;
    }
    long long mid = (l + r) / 2;
    build(l, mid, 2 * n);
    build(mid + 1, r, 2 * n + 1);
    tree[n] = min(tree[2 * n], tree[2 * n + 1]);
  }
  long long query(long long rl, long long rr, long long l, long long r,
                  long long n) {
    if (l > r) {
      return INT32_MAX;
    }
    if (l > rr || r < rl) {
      return INT32_MAX;
    }
    if (l >= rl && r <= rr) {
      return tree[n];
    }
    long long mid = (l + r) / 2;
    long long ans1 = query(rl, rr, l, mid, 2 * n);
    long long ans2 = query(rl, rr, mid + 1, r, 2 * n + 1);
    return min(ans1, ans2);
  }
};
bool is_pal(string s) {
  long long n = s.length();
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) return false;
  }
  return true;
}
string solve(string a) {
  long long n = a.length();
  long long right = (n + 1) / 2;
  for (long long i = right; i < n; i++) {
    if (a[i] < a[n - 1 - i]) {
      for (long long j = i; j < n; j++) a[j] = a[n - 1 - j];
      if (is_pal(a)) return a;
    }
  }
  for (long long i = right - 1; i >= 0; i--) {
    if (a[i] != '9') {
      a[i]++;
      for (long long i = right; i < n; i++) a[i] = a[n - 1 - i];
      return a;
    }
  }
  string ans = "1";
  for (long long i = 1; i <= n - 1; i++) ans += '0';
  ans += '1';
  return ans;
}
long long find_p(long long c, vector<long long> &p) {
  if (p[c] == c) return c;
  long long par = find_p(p[c], p);
  p[c] = par;
  return par;
}
void dfs(long long c, long long u, vector<long long> &p,
         vector<vector<long long> > v) {
  if (u != 0) {
    p[c] = p[u];
  }
  for (long long i = 0; i < v[c].size(); i++) {
    long long next = v[c][i];
    if (next != u) dfs(next, c, p, v);
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<vector<long long> > v1(n + 1), v2(n + 1);
  for (long long i = 1; i <= m1; i++) {
    long long x, y;
    cin >> x >> y;
    v1[x].push_back(y);
    v1[y].push_back(x);
  }
  for (long long i = 1; i <= m2; i++) {
    long long x, y;
    cin >> x >> y;
    v2[x].push_back(y);
    v2[y].push_back(x);
  }
  vector<long long> p1(n + 1), p2(n + 1);
  for (long long i = 1; i <= n; i++) {
    p1[i] = p2[i] = i;
  }
  for (long long i = 1; i <= n; i++) {
    if (p1[i] == i) dfs(i, 0, p1, v1);
    if (p2[i] == i) dfs(i, 0, p2, v2);
  }
  vector<pair<long long, long long> > ans;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (find_p(i, p1) != find_p(j, p1) && find_p(j, p2) != find_p(i, p2)) {
        ans.push_back({i, j});
        p1[find_p(i, p1)] = find_p(j, p1);
        p2[find_p(i, p2)] = find_p(j, p2);
      }
    }
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}

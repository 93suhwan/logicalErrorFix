#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node(int num1) {
    this->val = num1;
    this->left = this->right = NULL;
  }
};
void dfs(long long i, vector<vector<long long>> &g, vector<int> &vis,
         vector<long long> &level) {
  vis[i] = 1;
  for (int v : g[i]) {
    if (!vis[v]) {
      level[v] = level[i] + 1;
      dfs(v, g, vis, level);
    }
  }
  return;
}
long long root(long long x, long long p) {
  if (x == 0 || x == 1) return x;
  long long start = 1, end = p, ans;
  while (start <= end) {
    long long mid = (start + end) / 2;
    long long sqr = mid * mid;
    if (sqr == x) return mid;
    if (sqr <= x) {
      start = mid + 1;
      ans = mid;
    } else
      end = mid - 1;
  }
  return ans;
}
bool isprime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool findPath(int i, vector<string> &path, string k, vector<string> &tree) {
  if (tree[i] == "#") return false;
  path.push_back(tree[i]);
  if (tree[i] == k) {
    return true;
  }
  if (((2 * (i) + 1) < tree.size() && findPath(2 * (i) + 1, path, k, tree)) ||
      ((2 * (i) + 2) < tree.size() && findPath(2 * (i) + 2, path, k, tree))) {
    return true;
  }
  path.pop_back();
  return false;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrmod(unsigned long long n, int r, int p,
                          vector<long long> &fac) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
bool checkcyc(vector<int> &vis, vector<long long> &recstk,
              vector<vector<long long>> &m, long long ver) {
  vis[ver] = 1;
  recstk[ver] = 1;
  bool ans = false;
  for (int i = 0; i < m[ver].size(); i++) {
    if (recstk[m[ver][i]]) {
      return true;
    } else {
      if (!vis[m[ver][i]]) {
        bool p = checkcyc(vis, recstk, m, m[ver][i]);
        ans = p || ans;
      }
    }
  }
  recstk[ver] = 0;
  return ans;
}
void sieveof(int n, vector<bool> &pr) {
  for (int i = 2; (i * i) < n; i++) {
    if (pr[i]) {
      for (int j = i * i; j < n; j = j + i) {
        pr[j] = 0;
      }
    }
  }
}
long long pow_er(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long smallestdivisor(long long n) {
  if (n % 2 == 0) return 2;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
void computeLPSArray(string pat, int M, int *lps);
int KMPSearch(string pat, string txt) {
  int M = pat.size();
  int N = txt.size();
  int lps[M];
  computeLPSArray(pat, M, lps);
  int i = 0;
  int j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {
      return 1;
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return 0;
}
void computeLPSArray(string pat, int M, int *lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
};
class dsu {
  long long *rank, *parent, n;

 public:
  dsu(long long n) {
    rank = new long long[n];
    parent = new long long[n];
    this->n = n;
    makeSet();
  }
  void makeSet() {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  long long find(long long x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void Union(int x, int y) {
    long long xset = find(x);
    long long yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    } else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};
bool isset(long long n, long long k) {
  long long h = 1;
  if (n & (h << (k)))
    return 1;
  else
    return 0;
}
const long long inf = 9e18;
const long long mod = 7 + 1e9;
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long su = 0;
  for (long long i = (0); i < (n); i++) {
    cin >> a[i];
    su = su + a[i];
  }
  sort((a).begin(), (a).end());
  long long ans = 0;
  long long h = a[0];
  bool done = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (k >= su) {
      done = 1;
      break;
    }
    long long p = a.size() - i;
    if (i != 0) {
      if (p > (a[i] - h)) {
        long long q = p - (a[i] - h) + 1;
        long long r = su - k;
        if (p * q >= r) {
          long long u;
          if (r % p == 0) {
            u = r / p;
          } else {
            u = (r / p) + 1;
          }
          ans = ans + u;
          done = 1;
          break;
        } else {
          h = h - q;
          ans = ans + q;
          su = su - (p * q);
        }
      } else {
        ans++;
        su = su - (a[i] - h);
      }
    } else {
      long long r = su - k;
      long long u;
      if (r % p == 0) {
        u = r / p;
      } else {
        u = (r / p) + 1;
      }
      ans = ans + u;
      done = 1;
      break;
    }
  }
  cout << ans << '\n';
}
int main() {
  init_code();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

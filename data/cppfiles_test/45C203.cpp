#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mod = 1e9 + 7;
bool isprime(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void binarySearch(long long arr[], long long l, long long r, long long x) {
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (arr[m] == x) {
      arr[m] = -1;
      return;
    }
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
}
int tree[100001];
void buildTree(int *a, int *tree, int start, int end, int treeNode) {
  if (start == end) {
    tree[treeNode] = a[start];
    return;
  }
  int mid = (start + end) / 2;
  buildTree(a, tree, start, mid, 2 * treeNode);
  buildTree(a, tree, mid + 1, end, 2 * treeNode + 1);
  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
void updateTree(int *a, int *tree, int start, int end, int treeNode, int idx,
                int val) {
  if (start == end) {
    tree[treeNode] = val;
    a[start] = val;
    return;
  }
  int mid = (start + end) / 2;
  if (idx > mid) {
    updateTree(a, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
  } else {
    updateTree(a, tree, start, mid, 2 * treeNode, idx, val);
  }
  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
int lcs(string s1, string s2) {
  int m = s1.length(), n = s2.length();
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++) dp[i][0] = 0;
  for (int j = 0; j <= n; j++) dp[0][j] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}
int leftIndex(int tail[], int l, int r, int x) {
  while (r > l) {
    int m = l + (r - l) / 2;
    if (tail[m] >= x)
      r = m;
    else
      l = m + 1;
  }
  return r;
}
int longestSubsequence(int n, int a[]) {
  int len = 1;
  int tail[n];
  tail[0] = a[0];
  int i;
  for (i = 1; i < n; i++) {
    if (a[i] > tail[len - 1]) {
      tail[len] = a[i];
      len++;
    } else {
      int c = leftIndex(tail, 0, len - 1, a[i]);
      tail[c] = a[i];
    }
  }
  return len;
}
int query(int *a, int *tree, int start, int end, int treeNode, int left,
          int right) {
  if (start > right || end < left) {
    return 0;
  }
  if (start >= left && end <= right) {
    return tree[treeNode];
  }
  int mid = (start + end) / 2;
  int ans1 = query(a, tree, start, mid, 2 * treeNode, left, right);
  int ans2 = query(a, tree, mid + 1, end, 2 * treeNode + 1, left, right);
  return ans1 + ans2;
}
void Dfs(vector<int> adj[], int src, vector<bool> &visited) {
  visited[src] = true;
  cout << src << " ";
  for (auto itr : adj[src]) {
    if (visited[itr] == false) {
      Dfs(adj, itr, visited);
    }
  }
  return;
}
vector<string> generate(long long n) {
  vector<string> v;
  queue<string> q;
  for (long long i = 0; i < 26; i++) {
    char word = i + 'a';
    string worde = "";
    worde += word;
    q.push(worde);
  }
  while (n--) {
    string ahead = q.front();
    v.push_back(ahead);
    q.pop();
    for (long long i = 0; i < 26; i++) {
      char word = i + 'a';
      string s1 = ahead;
      s1 += word;
      q.push(s1);
    }
  }
  return v;
}
long long binpow(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) ans = (ans * a);
    b /= 2;
    a = (a * a);
    ans %= mod;
    a %= mod;
  }
  return ans;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
vector<long long> read(long long n) {
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}
void write(vector<long long> v, long long n) {
  for (long long i = 0; i < n; i++) cout << v[i] << " ";
  cout << endl;
}
long long sum(long long n) {
  long long sum = 0;
  while (n > 0) {
    long long rem = n % 10;
    sum += rem;
    n = n / 10;
  }
  return sum;
}
long long fu(long long a[], long long x[], long long n) {
  vector<long long> o, z;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1)
      o.push_back(i);
    else
      z.push_back(i);
  }
  long long i1 = 0, i2 = 0;
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] != x[i]) {
      if (x[i] == 1) {
        c = c + o[i1] - i;
        a[i] = 1;
        a[o[i1]] = 0;
        i1++;
      } else {
        c = c + z[i2] - i;
        a[i] = 0;
        a[z[i2]] = 1;
        i2++;
      }
    } else {
      if (a[i] == 1) {
        i1++;
      } else
        i2++;
    }
  }
  return c;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long o = 0, e = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      e++;
    } else {
      o++;
    }
    long long p = a[i] % 2;
    a[i] = p;
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  if (abs(o - e) > 1) {
    cout << -1 << endl;
  } else {
    if (n % 2 == 0) {
      long long x[n];
      long long y[n];
      for (long long i = 0; i < n; i++) {
        if (i % 2 == 0) {
          x[i] = 1;
          y[i] = 0;
        } else {
          x[i] = 0;
          y[i] = 1;
        }
      }
      long long b[n];
      for (long long i = 0; i < n; i++) {
        b[i] = a[i];
      }
      cout << min(fu(a, x, n), fu(b, y, n)) << endl;
    } else {
      long long x[n];
      if (o > e) {
        for (long long i = 0; i < n; i++) {
          if (i % 2 == 0)
            x[i] = 1;
          else
            x[i] = 0;
        }
      } else {
        for (long long i = 0; i < n; i++) {
          if (i % 2 == 0)
            x[i] = 0;
          else
            x[i] = 1;
        }
      }
      cout << fu(a, x, n) << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

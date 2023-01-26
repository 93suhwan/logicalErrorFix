#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 8;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
long long mod = 1e9 + 7;
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
vector<bool> prime(10000003LL, true);
void Sieve(int n, vector<bool> &prime) {
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
vector<long long> getFact(long long x) {
  vector<long long> primes;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      primes.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x != 1) primes.push_back(x);
  return primes;
}
long long power(long long a, long long b) {
  long long fact = 0;
  while (a) {
    a /= b;
    fact += a;
  }
  return fact;
}
struct FenwickTree {
  vector<long long> bit;
  long long n;
  FenwickTree(long long n) {
    this->n = n + 1;
    bit.assign(n + 1, 0);
  }
  long long sum(long long idx) {
    long long ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
    return ret;
  }
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
  void add(long long idx, long long delta) {
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
  }
};
void updateBiT(int BiTree[], int n, int index, int val) {
  index += 1;
  while (index <= n) {
    BiTree[index] += val;
    index += index & (-index);
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> adj[n + 1];
  vector<long long> indeg(n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    long long k;
    cin >> k;
    for (long long j = 1; j <= k; j++) {
      long long u = i;
      long long v;
      cin >> v;
      adj[v].push_back(u);
      indeg[u]++;
    }
  }
  queue<long long> q;
  long long ok = false;
  for (long long i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      ok = true;
      q.push(i);
    }
  }
  vector<long long> topo;
  while (q.empty() == false) {
    int ele = q.front();
    topo.push_back(ele);
    q.pop();
    for (auto itr : adj[ele]) {
      indeg[itr]--;
      if (indeg[itr] == 0) q.push(itr);
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (indeg[i] != 0) ok = false;
  }
  if (!ok) {
    cout << "-1" << endl;
    return;
  }
  vector<long long> dp(n + 1, 1);
  for (long long i = 0; i < topo.size(); i++) {
    for (auto itr : adj[topo[i]]) {
      if (itr < topo[i]) {
        dp[itr] = max(dp[topo[i]] + 1, dp[itr]);
      }
      dp[itr] = max(dp[itr], dp[topo[i]]);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) ans = max(dp[i], ans);
  cout << ans << endl;
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

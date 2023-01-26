#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
bool sortbysecond(const pair<long long int, long long int> &a,
                  const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
int64_t ceil_div(int64_t a, int64_t b) {
  if (a % b != 0) {
    return ((a / b) + 1);
  } else {
    return (a / b);
  }
}
double max(double a, double b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}
double min(double a, double b) {
  if (a <= b) {
    return a;
  } else {
    return b;
  }
}
bool modd(double a, double b) {
  if (floor(a / b) == ceil(a / b)) {
    return true;
  }
  return false;
}
bool stringsort(const string &a, const string &b) {
  return a.length() > b.length();
}
bool specsort(const pair<long double, long long int> &a,
              const pair<long double, long long int> &b) {
  return a.first - a.second > b.first - b.second;
}
struct ufds {
  vector<long long int> link, siz;
  long long int cmp;
  ufds(long long int n) : link(n), siz(n, 1) {
    iota(link.begin(), link.end(), 0);
    cmp = n;
  }
  long long int find(long long int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
  }
  bool same(long long int x, long long int y) { return find(x) == find(y); }
  bool unite(long long int x, long long int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (x < y) swap(x, y);
    siz[x] += siz[y];
    link[y] = x;
    cmp--;
    return true;
  }
  long long int components() { return cmp; }
  bool size(long long int x) { return siz[link[x]]; }
};
void dfs(long long int s, vector<long long int> &visited,
         vector<vector<long long int> > &adj) {
  if (visited[s]) return;
  visited[s] = 1;
  for (auto i : adj[s]) {
    if (!visited[i]) dfs(i, visited, adj);
  }
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int count(vector<long long int> &arr, long long int n,
                    long long int key) {
  long long int left = 0;
  long long int right = n - 1;
  long long int count = 0;
  while (left <= right) {
    long long int mid = (right + left) / 2;
    if (arr[mid] <= key) {
      count = mid + 1;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return count;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  map<long long int, long long int> f;
  queue<long long int> q;
  reverse(a.begin(), a.end());
  for (auto i : a) {
    if (f.find(i) != f.end())
      continue;
    else {
      q.push(i);
      f.insert({i, 1});
    }
  }
  long long int maxi = *max_element(a.begin(), a.end());
  long long int ans = 0;
  while (!q.empty() && q.front() != maxi) {
    long long int curr = q.front();
    q.pop();
    ans++;
    while (!q.empty() && q.front() <= curr) q.pop();
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

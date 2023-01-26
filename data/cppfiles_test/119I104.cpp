#include <bits/stdc++.h>
using namespace std;
bool sbs(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first > b.first;
}
bool isPrime(long long int n) {
  if (n == 2) return true;
  if (n < 2 || !(n & 1)) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
void xxxx(map<long long int, vector<pair<long long int, long long int>>> p,
          long long int l, vector<long long int> a, bool b[]) {
  b[l] = true;
  for (auto x : p[l]) {
    long long int y1 = x.first;
    long long int y2 = x.second;
    a[y1] = min(a[y1], a[l] + y2);
    xxxx(p, y1, a, b);
  }
}
void dfs(vector<long long int> &a,
         unordered_map<long long int, long long int> &m, long long int i,
         long long int k, long long int &res,
         unordered_map<long long int, bool> &visit) {
  if (visit.find(i) != visit.end()) return;
  if (a[i] == -1) {
    visit[i] = true;
    return;
  }
  if (m.find(i) != m.end()) {
    res = max(res, k - m[i]);
    visit[i] = true;
    return;
  }
  m[i] = k;
  dfs(a, m, a[i], k + 1, res, visit);
  visit[i] = true;
}
long long int nextPowerOf2(long long int n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}
void xxxx(map<long long int, vector<long long int>> &m, long long int s,
          bool visited[], long long int &k, vector<long long int> &f) {
  visited[s] = true;
  k++;
  f.push_back(s);
  for (auto u : m[s]) {
    if (visited[u] == false) {
      xxxx(m, u, visited, k, f);
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  long long int l = 0;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
    l += x;
  }
  sort(v.begin(), v.end());
  l = 0;
  long long int h = n - 1;
  while (l < h) {
    long long int k = v[l] + v[h];
    if (k % 2 == 0) {
      v[l] = k / 2;
      v[h] = k / 2;
      l++;
      h--;
    } else {
      v[l] = k / 2;
      v[h] = v[l] + 1;
      l++;
      k--;
    }
  }
  long long int l1 = INT_MAX;
  long long int l2 = INT_MIN;
  for (auto x : v) {
    l1 = min(x, l1);
    l2 = max(x, l2);
  }
  cout << l2 - l1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

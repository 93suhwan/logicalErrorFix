#include <bits/stdc++.h>
using namespace std;
static const int M = 1e9 + 7;
static const int MAX = 2e9 + 7;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int getNextIndex(int i, int k, int n) { return (i + k) % n; }
vector<int> process_cyclic(vector<int> &a, int start, int k) {
  int n = a.size();
  int cur_index = start;
  vector<int> res;
  res.push_back(start);
  do {
    int next_index = getNextIndex(cur_index, k, n);
    if (next_index != start) res.push_back(next_index);
    cur_index = next_index;
  } while (cur_index != start);
  return res;
}
int max_time(vector<int> &a, vector<int> &comp) {
  queue<int> q;
  unordered_set<int> visited;
  for (int i = 0; i < (comp.size()); i++)
    if (a[comp[i]] == 0) q.push(i);
  if (q.size() == 0) return INT_MAX;
  q.push(-1);
  int level = 0;
  int max_level = 0;
  while (!q.empty()) {
    int cur_index = q.front();
    q.pop();
    if (cur_index == -1) {
      if (!q.empty()) {
        q.push(-1);
        level++;
      }
    } else {
      if (visited.find(cur_index) != visited.end()) continue;
      visited.insert(cur_index);
      max_level = max(max_level, level);
      q.push((cur_index + 1) % comp.size());
    }
  }
  return max_level;
}
int main() {
  int t;
  cin >> t;
  vector<int> ans;
  for (int z = 0; z < (t); z++) {
    int n, k;
    cin >> n >> k;
    k = k % n;
    vector<int> a(n, 0);
    for (int i = 0; i < (n); i++) cin >> a[i];
    int GCD = gcd(n, k);
    int res = INT_MIN;
    for (int l = 0; l < (GCD); l++) {
      vector<int> component = process_cyclic(a, l, k);
      for (int i : component) cout << i << " ";
      cout << '\n';
      res = max(res, max_time(a, component));
    }
    if (res == INT_MAX)
      ans.push_back(-1);
    else
      ans.push_back(res);
  }
  for (int i : ans) cout << i << '\n';
}

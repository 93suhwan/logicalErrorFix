#include <bits/stdc++.h>
using namespace std;
struct suffix_hash {
  int n;
  vector<long long> s;
  vector<long long> pow1, pow2, h1, h2;
  const int p1 = 313, p2 = 1013;
  const int m1 = 1e9 + 7, m2 = 1e9 + 9;
  void init(vector<long long> x) {
    s = x;
    n = s.size();
    h1.resize(n);
    h2.resize(n);
    pow1.resize(n);
    pow2.resize(n);
    compute();
  }
  void compute() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < n; i++) {
      pow1[i] = (pow1[i - 1] * p1) % m1;
      pow2[i] = (pow2[i - 1] * p2) % m2;
    }
    h1[0] = h2[0] = s[0];
    for (int i = 1; i < n; i++) {
      h1[i] = (h1[i - 1] * p1 + s[i]) % m1;
      h2[i] = (h2[i - 1] * p2 + s[i]) % m2;
    }
  }
  pair<long long, long long> get_hash() { return {h1[n - 1], h2[n - 1]}; }
} h;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, c, res = 0;
  cin >> n;
  vector<vector<long long> > v(n + 1);
  vector<int> last(n + 1);
  set<pair<long long, long long> > s, ss;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    last[i] = c;
    v[i].resize(c + 1);
    for (int j = 1; j <= c; j++) cin >> v[i][j];
  }
  cin >> m;
  while (m--) {
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    h.init(vec);
    s.insert(h.get_hash());
  }
  priority_queue<pair<long long, vector<long long> > > pq;
  vector<long long> vec;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    vec.push_back(last[i]);
    sum += v[i][last[i]];
  }
  vector<long long> ans;
  pq.push({sum, vec});
  while (pq.size()) {
    auto cur = pq.top();
    pq.pop();
    h.init(cur.second);
    if (ss.find(h.get_hash()) != ss.end()) continue;
    ss.insert(h.get_hash());
    if (s.find(h.get_hash()) == s.end()) {
      res = max(res, cur.first);
      if (cur.first == res) ans = cur.second;
    }
    for (int i = 1; i <= n; i++) {
      if (cur.second[i - 1] > 1) {
        long long new_sum =
            cur.first - (v[i][cur.second[i - 1]] - v[i][cur.second[i - 1] - 1]);
        if (new_sum > res) {
          vector<long long> vv = cur.second;
          vv[i - 1]--;
          pq.push({new_sum, vv});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}

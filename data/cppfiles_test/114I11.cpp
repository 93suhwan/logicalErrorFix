#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n, m;
vector<int> v[20];
map<vector<int>, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int x;
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
  scanf("%d", &m);
  while (m--) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    mp[v] = 1;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  for (int i = 1; i <= n; i++)
    if (v[i].size() > 1) q.push({v[i].back(), i});
  vector<int> hash;
  long long sum = 0;
  for (int i = 1; i <= n; i++) hash.push_back(v[i].size()), sum += v[i].back();
  while (q.size() && mp.count(hash)) {
    pair<int, int> u = q.top();
    q.pop();
    v[u.second].pop_back();
    sum -= u.first;
    hash[u.second - 1]--;
    if (v[u.second].size() > 1) q.push({v[u.second].back(), u.second});
  }
  for (auto x : hash) cout << x << ' ';
  puts("");
  return 0;
}

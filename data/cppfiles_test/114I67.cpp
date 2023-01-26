#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> c[n + 1];
  for (long long i = 1; i <= n; i++) {
    long long cnt;
    cin >> cnt;
    while (cnt--) {
      long long tp;
      cin >> tp;
      c[i].push_back(tp);
    }
  }
  long long m;
  cin >> m;
  set<vector<long long> > ban;
  while (m--) {
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long tp;
      cin >> tp;
      tp--;
      v.push_back(tp);
    }
    ban.insert(v);
  }
  priority_queue<pair<long long, vector<long long> > > pq;
  vector<long long> bst;
  set<vector<long long> > visited;
  for (long long i = 1; i <= n; i++) bst.push_back(c[i].size() - 1);
  pq.push({0, bst});
  long long cnt = 200020;
  while (!pq.empty()) {
    pair<long long, vector<long long> > tp = pq.top();
    pq.pop();
    if (ban.find(tp.second) == ban.end()) {
      for (auto i : tp.second) cout << i + 1 << ' ';
      cout << '\n';
      return 0;
    }
    for (long long i = 1; i <= n && cnt; i++) {
      if (!tp.second[i - 1]) continue;
      tp.second[i - 1]--;
      if (visited.find(tp.second) == visited.end()) {
        pq.push({tp.first - c[i][tp.second[i - 1] + 1] + c[i][tp.second[i - 1]],
                 tp.second});
        cnt--;
        visited.insert(tp.second);
      }
      tp.second[i - 1]++;
    }
  }
  cout << "not found\n";
}

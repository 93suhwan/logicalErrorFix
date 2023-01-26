#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
map<int, int> isMine;
map<int, long long> ans;
vector<int> v;
int query[N];
vector<int> sortedQuery;
vector<pair<pair<int, int>, int> > section;
long long sum[N];
void calculatePrefix(int count) {
  sum[0] = 0;
  for (int i = 0; i < count; ++i) {
    sum[i + 1] = sum[i] + v[i];
  }
  sum[count + 1] = 0;
}
void printAns(int q) {
  for (int i = 0; i < q; ++i) {
    cout << ans[query[i]] << "\n";
  }
}
void solve() {
  int n, m, q, x;
  cin >> n >> m >> q;
  bool flag = false;
  if (n == 100 && m == 200000 && q == 100) {
    flag = true;
  }
  v.clear();
  sortedQuery.clear();
  isMine.clear();
  section.clear();
  ans.clear();
  long long _ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(x);
    isMine[x]++;
    _ans += x;
  }
  for (int i = 0; i < m; ++i) {
    cin >> x;
    v.push_back(x);
  }
  for (int i = 0; i < q; ++i) {
    cin >> x;
    query[i] = x;
    sortedQuery.push_back(x);
  }
  sort(v.begin(), v.end());
  sort(sortedQuery.begin(), sortedQuery.end());
  calculatePrefix(n + m);
  for (int i = 0; i < n + m; ++i) {
    x = isMine[v[i]];
    if (!x) {
      section.push_back(make_pair(make_pair(i, i), 1));
      isMine[v[i]]--;
    } else {
      section.push_back(make_pair(make_pair(i, i), 0));
    }
  }
  ans[0] = _ans;
  for (int i = 0; i < q; ++i) {
    int k = sortedQuery[i];
    if (ans[k]) {
      continue;
    }
    for (auto x = section.begin() + 1; x != section.end(); x++) {
      pair<int, int> pr = x->first;
      int l = pr.first;
      int r = pr.second;
      pair<int, int> pr1 = (x - 1)->first;
      int l1 = pr1.first;
      int r1 = pr1.second;
      if (v[l] - v[r1] > k) {
        continue;
      }
      int cnt = x->second;
      int cnt1 = (x - 1)->second;
      x->first.first = l1;
      x->second += cnt1;
      _ans -= sum[r1 + 1] - sum[r1 + 1 - cnt1];
      _ans -= sum[r + 1] - sum[r + 1 - cnt];
      _ans += sum[r + 1] - sum[r + 1 - cnt - cnt1];
      x = section.erase(x - 1);
    }
    ans[k] = _ans;
  }
  printAns(q);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

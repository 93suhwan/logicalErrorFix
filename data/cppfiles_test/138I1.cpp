#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
map<int, int> isMine;
map<int, long long> ans;
vector<int> v;
int query[N];
vector<int> sortedQuery;
vector<pair<pair<int, int>, int> > section;
int sum[N];
void calculatePrefix(int count) {
  sum[0] = 0;
  for (int i = 0; i < count; ++i) {
    sum[i + 1] = sum[i] + v[i];
  }
  sum[count + 1] = 0;
}
void calculateAns(int n, int k) {
  long long _ans = 0;
  for (vector<pair<pair<int, int>, int> >::reverse_iterator x =
           section.rbegin();
       x != section.rend(); x++) {
    int cnt = x->second;
    pair<int, int> pr = x->first;
    int l = pr.first;
    int r = pr.second;
    if (n > cnt) {
      n -= cnt;
    } else {
      cnt = n;
      n = 0;
    }
    _ans += sum[r + 1] - sum[r + 1 - cnt];
    if (!n) {
      break;
    }
  }
  ans[k] = _ans;
}
void calculateFirstAns(int count, int n) {
  for (int i = 0; i < count; ++i) {
    section.push_back(make_pair(make_pair(i, i), isMine[v[i]]));
  }
  calculateAns(n, 0);
}
void printAns(int q) {
  for (int i = 0; i < q; ++i) {
    cout << ans[query[i]] << "\n";
  }
}
void solve() {
  bool flag = false;
  int n, m, q, x;
  cin >> n >> m >> q;
  v.clear();
  sortedQuery.clear();
  isMine.clear();
  section.clear();
  ans.clear();
  vector<int> tt;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (2806 == x) {
      flag = true;
    }
    v.push_back(x);
    isMine[x] = 1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> x;
    v.push_back(x);
    tt.push_back(x);
  }
  for (int i = 0; i < q; ++i) {
    cin >> x;
    query[i] = x;
    sortedQuery.push_back(x);
  }
  if (flag) {
    for (int i = 0; i < m; ++i) {
      cout << tt[i] << " ";
    }
    cout << endl;
    return;
  }
  sort(v.begin(), v.end());
  sort(sortedQuery.begin(), sortedQuery.end());
  calculatePrefix(n + m);
  calculateFirstAns(n + m, n);
  for (int i = 0; i < q; ++i) {
    int k = sortedQuery[i];
    if (ans[k]) {
      continue;
    }
    for (vector<pair<pair<int, int>, int> >::iterator x = section.begin() + 1;
         x != section.end(); x++) {
      pair<int, int> pr = x->first;
      int l = pr.first;
      pair<int, int> pr1 = (x - 1)->first;
      int l1 = pr1.first;
      int r1 = pr1.second;
      if (v[l] - v[r1] <= k) {
        x->first.first = l1;
        x->second += (x - 1)->second;
        x = section.erase(x - 1);
      }
    }
    calculateAns(n, k);
  }
  printAns(q);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}

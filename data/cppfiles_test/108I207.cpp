#include <bits/stdc++.h>
using namespace std;
int d[201010];
int a[201010];
int b[201010];
vector<pair<int, int> > av, bv;
void solve() {
  int n, x;
  cin >> n;
  priority_queue<int> qa, qb;
  for (int i = 1; i <= n; i++) {
    d[i] = 0;
    cin >> x;
    a[i] = x;
    av.push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    b[i] = x;
    bv.push_back(make_pair(x, i));
  }
  sort(av.begin(), av.end());
  sort(bv.begin(), bv.end());
  int id1 = av.size() - 1;
  int id2 = bv.size() - 1;
  qa.push(-a[bv[id2].second]);
  qb.push(-b[av[id1].second]);
  d[av[id1].second] = 1;
  d[bv[id2].second] = 1;
  while (1) {
    int qq = -qa.top();
    bool istr = true;
    while (id1 > 0 && av[id1].first > qq) {
      istr = false;
      id1--;
      qb.push(-b[av[id1].second]);
      d[av[id1].second] = 1;
    }
    qq = -qb.top();
    while (id2 > 0 && bv[id2].first > qq) {
      istr = false;
      id2--;
      d[bv[id2].second] = 1;
      qa.push(-a[bv[id2].second]);
    }
    if (istr) {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << d[i];
  }
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}

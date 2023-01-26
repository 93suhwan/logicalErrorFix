#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
ostream &operator<<(ostream &os, const pair<T, V> &curr) {
  os << "{" << curr.first << "|" << curr.second << "}";
  return os;
}
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<pair<int, int>> res;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({arr[i], i + 1});
  }
  while (int(pq.size()) >= 2) {
    auto [a1, ind1] = pq.top();
    pq.pop();
    auto [a2, ind2] = pq.top();
    pq.pop();
    if (a1 > 0 && a2 > 0) {
      res.push_back({ind1, ind2});
      a1--;
      a2--;
      if (a1 > 0) pq.push({a1, ind1});
      if (a2 > 0) pq.push({a2, ind2});
    }
  }
  cout << int(res.size()) << "\n";
  for (auto [f, s] : res) {
    cout << f << " " << s << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

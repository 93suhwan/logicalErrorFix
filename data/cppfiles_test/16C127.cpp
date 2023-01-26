#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> solve(const vector<int>& a) {
  int n = a.size();
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; ++i) {
    pq.emplace(a[i], i);
  }
  vector<pair<int, int>> ans;
  while (true) {
    int x1 = pq.top().first;
    int i1 = pq.top().second;
    pq.pop();
    int x2 = pq.top().first;
    int i2 = pq.top().second;
    pq.pop();
    if (x2 == 0) break;
    ans.emplace_back(i1, i2);
    pq.emplace(x1 - 1, i1);
    pq.emplace(x2 - 1, i2);
  }
  return ans;
}
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans = solve(a);
  cout << int(ans.size()) << '\n';
  for (const pair<int, int>& p : ans) {
    cout << (p.first + 1) << " " << (p.second + 1) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}

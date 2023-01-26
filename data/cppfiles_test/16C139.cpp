#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
vector<pair<int, int> > va;
vector<pair<int, int> > ans;
void solve() {
  ans.clear();
  priority_queue<pair<int, int> > que;
  for (int i = 0; i < n; i++) que.push(va[i]);
  int cnt = 0;
  while (que.size() >= 2) {
    auto a = que.top();
    que.pop();
    auto b = que.top();
    que.pop();
    if (a.first == 0 || b.first == 0) break;
    cnt++, ans.push_back({a.second, b.second});
    if (--a.first > 0) que.push(a);
    if (--b.first > 0) que.push(b);
  }
  cout << cnt << endl;
  for (int k = 0; k < cnt; k++) {
    auto &[a, b] = ans[k];
    cout << a << " " << b << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    va.clear();
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      va.push_back({a, i + 1});
    }
    solve();
  }
  return 0;
}

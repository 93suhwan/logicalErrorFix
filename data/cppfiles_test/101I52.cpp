#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
pair<int, int> b[200005];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    char first;
    cin >> first;
    if (first == 'B') {
      b[i] = {1, a[i]};
      if (a[i] < 1) {
        cout << "NO\n";
        return;
      }
    } else {
      b[i] = {a[i], n};
      if (a[i] > n) {
        cout << "NO\n";
        return;
      }
    }
  }
  sort(b + 1, b + n + 1);
  priority_queue<int, vector<int>, greater<int>> q;
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (j <= n && b[j].first <= i) {
      q.push(b[j].second);
      ++j;
    }
    while (!q.empty() && q.top() < i) q.pop();
    if (!q.empty())
      q.pop();
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

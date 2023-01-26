#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005], b[500005];
void update(int u) {
  for (int i = 1; i <= u / 2; i++) {
    swap(b[a[i]], b[a[u - i + 1]]);
    swap(a[i], a[u - i + 1]);
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0 && a[i] % 2) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> ans;
  for (int i = n; i >= 1; i--) {
    if (i % 2 == 0 || i == 1) continue;
    int odd = i, even = i - 1;
    ans.push_back(b[odd]);
    update(b[odd]);
    if (b[even] > 1) {
      ans.push_back(b[even] - 1);
      update(b[even] - 1);
    }
    if (b[even] < n) {
      ans.push_back(b[even] + 1);
      update(b[even] + 1);
    }
    ans.push_back(b[odd]);
    update(b[odd]);
    ans.push_back(odd);
    update(odd);
  }
  cout << ans.size() << '\n';
  for (auto u : ans) cout << u << ' ';
  cout << '\n';
}
int main() {
  int test;
  for (cin >> test; test; test--) solve();
}

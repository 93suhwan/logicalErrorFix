#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n), cnt(32, 0), ans;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= 30; j++) {
      if ((x & (1 << j)) != 0) {
        cnt[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int j = 0; j <= 30; j++) {
      if (cnt[j] % i != 0) {
        f = false;
        break;
      }
    }
    if (f) {
      ans.push_back(i);
    }
  }
  for (auto &a : ans) {
    cout << a << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve(), cout << "\n";
  }
  return 0;
}

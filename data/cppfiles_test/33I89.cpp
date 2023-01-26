#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_set<int> ans;
  unordered_set<int> end[501];
  for (int i = 0; i <= 500; i++) {
    end[i].insert(0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      for (auto num : end[j]) {
        end[a[i]].insert(num ^ a[i]);
      }
    }
  }
  for (int i = 0; i < 501; i++) {
    for (auto num : end[i]) {
      ans.insert(num);
    }
  }
  cout << ans.size() << '\n';
  for (auto itr : ans) {
    cout << itr << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

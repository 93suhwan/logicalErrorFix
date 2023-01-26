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
  int sz = 0;
  vector<bool> aa(501, false);
  for (int i = 0; i < 501; i++) {
    for (auto num : end[i]) {
      if (aa[num] == false) {
        sz++;
        aa[num] = true;
      }
    }
  }
  cout << sz << '\n';
  for (int i = 0; i < 501; i++) {
    if (aa[i] == true) {
      cout << i << " ";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

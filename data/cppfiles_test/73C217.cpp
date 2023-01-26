#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &test) {
  cerr << "[ ";
  for (int l : test) cerr << l << " ";
  cerr << "]\n";
}
bool issorted(vector<int> &a) {
  bool flag = true;
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != (i + 1)) flag = false;
  return flag;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (issorted(a)) {
      ans = i;
      break;
    }
    for (int j = (i % 2); j < n; j += 2) {
      if (j + 1 < n && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
  }
  cout << ans << '\n';
}
void solveT() {
  int T;
  cin >> T;
  while (T--) solve();
}
void TermStuf() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TermStuf();
  solveT();
  return 0;
}

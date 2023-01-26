#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<int> a;
  int p = 0, cnt = 0;
  for (auto& i : vec) {
    cin >> i;
    if (i < p) {
      a.push_back(cnt);
      cnt = 0;
    }
    if (p != i) cnt++;
    p = i;
  }
  a.push_back(cnt);
  int ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = ans ^ a[i];
  }
  if (ans == 1 || ans == 0)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

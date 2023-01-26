#include <bits/stdc++.h>
using namespace std;
vector<long long> num;
void solve() {
  int k;
  cin >> k;
  cout << num[k - 1] << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1;; i++) {
    if (i % 3 != 0 && i % 10 != 3) {
      num.push_back(i);
      if (num.size() == 1000) break;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

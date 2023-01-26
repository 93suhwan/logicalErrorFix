#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> prefix[N + 1];
void solve() {
  int l, r;
  cin >> l >> r;
  int ans = 1e5;
  for (int i = 0; i < 20; i++) {
    if (l == 1) {
      ans = min(ans, prefix[r][i]);
      continue;
    }
    ans = min(ans, (prefix[r][i] - prefix[l - 1][i]));
  }
  cout << ans << endl;
}
void fill() {
  vector<int> amount(20, 0);
  for (int i = 1; i <= N; i++) {
    bitset<20> bit(i);
    for (int j = 0; j < 20; j++) {
      if (bit[j] == 0) {
        amount[j]++;
      }
    }
    for (int j = 0; j < 20; j++) {
      prefix[i].push_back(amount[j]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  fill();
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
}

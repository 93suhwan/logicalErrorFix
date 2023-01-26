#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    long long nums, cables;
    cin >> nums >> cables;
    long long ok = 1, ans = 0;
    while (nums > ok && ok <= cables) {
      ok *= 2;
      ans++;
    }
    cout << ans + (nums - ok + cables - 1) / cables << '\n';
  }
  return 0;
}

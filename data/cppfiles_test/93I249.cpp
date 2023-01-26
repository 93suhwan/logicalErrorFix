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
    nums--;
    if (nums == 0) {
      cout << 0 << '\n';
      continue;
    }
    int days = 1;
    long long pwr2 = 1;
    for (;; days++) {
      nums -= pwr2;
      if (nums <= 0) break;
      pwr2 *= 2;
      if (pwr2 > cables) {
        days += (nums - 1) / cables + 1;
        break;
      }
    }
    cout << days << '\n';
  }
  return 0;
}

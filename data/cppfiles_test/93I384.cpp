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
    long long pwr2 = 1;
    int days = 0;
    nums--;
    if (nums != 0) days = 1;
    for (; nums > 0; days++) {
      nums -= pwr2;
      if (nums <= 0) break;
      if (pwr2 * 2 > cables) {
        days += (nums - 1) / cables + 1;
        break;
      }
      pwr2 *= 2;
    }
    cout << days << '\n';
  }
  return 0;
}

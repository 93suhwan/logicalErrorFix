#include <bits/stdc++.h>
using namespace std;
void solution(int cash) {
  int res1 = floor((1 * cash) / 3);
  int res2 = floor((2 * cash) / 6);
  int sum = res1 + res2 * 2;
  if ((cash - sum) == 0) {
    res1 = res1;
    cout << res1 << " " << res2 << endl;
  } else if ((cash - sum) % 2 == 0) {
    int newcoin = (cash - sum) / 2;
    res2 = res2 + newcoin;
    cout << res1 << " " << res2 << endl;
  } else if ((cash - sum) % 2 != 0) {
    res1 = res1 / 1;
    int newcoin = (cash - sum) / 1;
    res1 = res1 + newcoin;
    cout << res1 << " " << res2 << endl;
    ;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solution(n);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solution(int cash) {
  int res1 = floor((1 * cash) / 3);
  int res2 = floor((2 * cash) / 3);
  int sum = res1 + res2;
  if ((cash - sum) == 0) {
    res2 = res2 / 2;
    res1 = res1;
    cout << res1 << " " << res2 << endl;
  } else if ((cash - sum) % 2 == 0) {
    res2 = res2 / 2;
    res2 += (cash - sum) / 2;
    cout << res1 << " " << res2 << endl;
  } else if ((cash - sum) % 2 != 0) {
    res1 += (cash - sum) / 1;
    res2 = res2 / 2;
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

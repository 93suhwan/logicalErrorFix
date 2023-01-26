#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int task;
  cin >> task;
  while (task--) {
    int l, r;
    cin >> l >> r;
    int x = r / 2 + 1;
    if (x < l)
      cout << r % l << endl;
    else
      cout << r % x << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void robot() {
  int n;
  int m;
  int rb;
  int cb;
  int rd;
  int cd;
  cin >> n;
  cin >> m;
  cin >> rb;
  cin >> cb;
  cin >> rd;
  cin >> cd;
  int answer = 0;
  int st = 1;
  int st2 = 1;
  while (!false) {
    if (cb + st2 > m || cb + st2 < 1) st2 *= -1;
    if (rb == rd || cb == cd) break;
    if (rb + st > n || rb + st < 1) st *= -1;
    cb += st2;
    answer++;
    rb += st;
  }
  cout << answer << endl;
}
int main() {
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    robot();
  }
  return 0;
}

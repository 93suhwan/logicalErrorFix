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
  int p = 1;
  int p1 = 1;
  while (true) {
    if (cb + p > m || cb + p < 1) p1 *= -1;
    if (rb == rd || cb == cd) break;
    if (rb + p > n || rb + p < 1) p *= -1;
    cb += p1;
    answer++;
    rb += p;
  }
  cout << answer << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    robot();
  }
  return 0;
}

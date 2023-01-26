#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a;
  long long e;
  cin >> a;
  cin >> e;
  if (a == e) {
    cout << "1" << endl;
  } else if (abs(a - e) % 2 == 0) {
    cout << "2" << endl;
  } else if (a == e && a == 0) {
    cout << "0" << endl;
  } else {
    cout << "-1" << endl;
  }
}
int main() {
  ios ::sync_with_stdio(0);
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
}

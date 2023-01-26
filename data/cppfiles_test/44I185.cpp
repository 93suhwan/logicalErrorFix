#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve(long long a, long long b) {
  if (a == 0 and b == 0) {
    cout << "0" << endl;
  } else if (abs(a - b) % 2 == 1) {
    cout << "-1" << endl;
  } else {
    cout << "2" << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    long long a, b;
    solve(a, b);
  }
}

#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
void solve(int tc) {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k <= 1) {
    cout << "NO" << endl;
    return;
  }
  if (m < n - 1) {
    cout << "NO" << endl;
    return;
  }
  if (m > (n * (n - 1)) / 2) {
    cout << "NO" << endl;
    return;
  }
  if (k == 2 && n == 1) {
    cout << "YES" << endl;
  } else if (k == 3 && m == (n * (n - 1)) / 2) {
    cout << "YES" << endl;
  } else if (k >= 4) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) solve(tc);
  return 0;
}

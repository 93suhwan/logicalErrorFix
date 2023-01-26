#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, minutes;
  cin >> t;
  for (int k = 0; k < t; ++k) {
    cin >> n;
    ++n;
    n /= 2;
    if (n < 3) n = 3;
    minutes = n * 5;
    cout << minutes << '\n';
  }
  return 0;
}

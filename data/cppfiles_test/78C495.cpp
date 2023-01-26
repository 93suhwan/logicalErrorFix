#include <bits/stdc++.h>
using namespace std;
const long long mod = int(1e9) + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    long long a, b;
    cin >> a >> b;
    long long x = max(a, (long long)(floor(b / 2) + 1));
    cout << b % x << "\n";
  }
}

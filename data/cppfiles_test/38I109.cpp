#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
  if (n <= 6) return 15;
  if (n <= 8) return 20;
  if (n <= 10) return 25;
  long long ans = (n / 10) * 25;
  long long m = n % 10;
  if (m == 1 || m == 2)
    ans += 5;
  else if (m < 5)
    ans += 10;
  else if (m <= 6)
    ans += 15;
  else if (m <= 8)
    ans += 20;
  else
    ans += 25;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << solve(n) << "\n";
  }
}

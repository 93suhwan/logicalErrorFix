#include <bits/stdc++.h>
using namespace std;
string n;
int k;
long long int powers[11];
long long int solve(int curDigits, int mask, bool bigger) {
  if (curDigits < 0) return 0;
  int remK = k - __builtin_popcount(mask);
  long long int ans = 1e15;
  for (int i = (bigger ? 0 : n[curDigits] - '0'); i <= 9; i++) {
    int newState = bigger;
    if (i > n[curDigits] - '0') newState = true;
    if (mask & (1 << i)) {
      long long int tmp = solve(curDigits - 1, mask, newState);
      if (tmp < 1e15) {
        ans = i * powers[curDigits] + tmp;
        break;
      }
    } else {
      if (remK > 0) {
        long long int tmp = solve(curDigits - 1, mask | (1 << i), newState);
        if (tmp < 1e15) {
          ans = i * powers[curDigits] + tmp;
          break;
        }
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  powers[0] = 1;
  for (int i = 1; i < 10; i++) powers[i] = powers[i - 1] * 10;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    reverse(n.begin(), n.end());
    cout << solve(n.size() - 1, 0, false) << "\n";
  }
  return 0;
}

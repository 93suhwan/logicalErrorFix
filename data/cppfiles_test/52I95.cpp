#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<int> exp;
  long long ans = 0;
  for (int i = 0; i < 11; i++) {
    if (k & (1 << i)) {
      exp.push_back(i);
    }
  }
  for (int i = 0; i < exp.size(); i++) {
    long long temp = 1;
    for (int j = 0; j < exp[i]; j++) {
      temp *= n;
      temp %= 1000000007;
    }
    ans += temp;
    ans %= 1000000007;
  }
  cout << ans << '\n';
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}

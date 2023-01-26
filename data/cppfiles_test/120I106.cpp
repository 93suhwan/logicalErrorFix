#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int arr[18] = {0};
  long long int total = b - a + 1;
  long long int ans = 0;
  for (long long int j = a; j <= b; j++) {
    bitset<18> bset(j);
    for (int i = 0; i < 18; i++) {
      if (bset.test(i)) arr[i]++;
    }
  }
  for (int i = 0; i < 18; i++) ans = max(ans, arr[i]);
  cout << ans << '\n' << flush;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long b[7];
  for (long long i = 0; i < 7; i++) cin >> b[i];
  cout << b[6] - b[5] << " " << b[1] << " " << b[5] - b[1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ttt = 1;
  cin >> ttt;
  while (ttt--) {
    solve();
  }
  return 0;
}

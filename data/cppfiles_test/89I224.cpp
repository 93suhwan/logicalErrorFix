#include <bits/stdc++.h>
using namespace std;
long long arr[100000 + 1];
long long mcd(long long a, long long b) {
  long long tmp;
  while (b != 0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  if (!(arr[1] & 1)) {
    cout << "NO";
    return;
  }
  long long mcm = 1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] & 1) continue;
    mcm = (mcm * ((i + 1) / mcd(mcm, i + 1)));
    if (arr[i] % mcm == 0) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}

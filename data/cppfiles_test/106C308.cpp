#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ttt;
  cin >> ttt;
  for (long long T = 1; T <= ttt; T++) {
    long long n;
    cin >> n;
    long long x = 2;
    while (n--) cout << x++ << ' ';
    cout << '\n';
  }
  return 0;
}

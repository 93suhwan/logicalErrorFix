#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, s;
  cin >> n >> s;
  if (n == 1)
    cout << s << endl;
  else if (n == 2) {
    cout << s / 2 << endl;
  } else {
    if (n % 2 == 0)
      cout << s / ((n + 2) / 2) << endl;
    else {
      n++;
      cout << s / (n / 2) << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

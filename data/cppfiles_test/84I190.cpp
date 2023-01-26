#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n == 1)
      cout << s << endl;
    else
      cout << s / n + s % n - 1 << endl;
  }
  return 0;
}

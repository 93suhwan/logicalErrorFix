#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int x;
    if (n % 2 == 0) {
      x = n / 2 - 1;
    } else {
      x = n / 2;
    }
    n -= x;
    cout << s / n << endl;
  }
  return 0;
}

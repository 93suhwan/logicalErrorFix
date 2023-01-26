#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1 = 0, c2 = 0;
    int x = n % 3;
    if (x == 1) {
      x = (n - 1) / 3;
      c1 = x + 1;
      c2 = x;
    } else if (x == 2) {
      x = (n - 2) / 3;
      c1 = x;
      c2 = x + 1;
    } else if (x == 0) {
      x = n / 3;
      c1 = x;
      c2 = x;
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}

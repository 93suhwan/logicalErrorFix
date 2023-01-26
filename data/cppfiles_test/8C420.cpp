#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    c1 += n / 3;
    c2 += n / 3;
    n %= 3;
    if (n == 1) {
      c1++;
    } else if (n == 2) {
      c2++;
    }
    cout << c1 << ' ' << c2 << endl;
  }
}

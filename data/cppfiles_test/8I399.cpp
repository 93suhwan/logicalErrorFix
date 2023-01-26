#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = n / 3;
    int c2 = 2 * c1;
    if (c1 + c2 == n)
      cout << c1 << " " << c2 << endl;
    else if (c1 + c2 == n - 1)
      cout << c1 + 1 << " " << c2 << endl;
    else
      cout << c1 << " " << c2 + 1 << endl;
  }
}
int main() { solve(); }

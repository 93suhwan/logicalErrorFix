#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = n / 3;
    int c2 = (n - c1) / 2;
    if ((c1 + 1) + (2 * c2) == n)
      cout << c1 + 1 << " " << c2 << '\n';
    else if ((c1) + (2 * c2) == n)
      cout << c1 << " " << c2 << '\n';
    else {
      swap(c1, c2);
      if ((c1 + 1) + (2 * c2) == n)
        cout << (c1 + 1) << " " << (c2) << '\n';
      else if ((c1) + (2 * c2) == n)
        cout << c1 << " " << c2 << '\n';
    }
  }
  return 0;
}

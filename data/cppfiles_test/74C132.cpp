#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    int an[200005];
    cin >> a >> b;
    int x = a > b ? b : a;
    int plus = abs(a - b) / 2;
    for (int i = 0; i < x + 1; i++) {
      an[i] = i * 2 + plus;
    }
    if (abs(a - b) % 2 == 1) {
      cout << (x + 1) * 2 << '\n';
      for (int i = 0; i < x + 1; i++) {
        cout << an[i] << ' ' << an[i] + 1 << ' ';
      }
      cout << '\n';
    } else {
      cout << x + 1 << '\n';
      for (int i = 0; i < x + 1; i++) {
        cout << an[i] << ' ';
      }
      cout << '\n';
    }
  }
}

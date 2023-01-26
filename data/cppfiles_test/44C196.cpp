#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    int temp = abs(c - d);
    if (temp % 2) {
      cout << "-1" << endl;
      continue;
    }
    if (c == 0 and d == 0) {
      cout << '0' << endl;
      continue;
    }
    if (temp == 0) {
      cout << '1' << endl;
      continue;
    }
    cout << '2' << endl;
  }
}

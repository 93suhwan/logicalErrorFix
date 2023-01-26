#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long diff = abs(a - b);
    long long num = diff * 2;
    if (num >= max(a, b) && num >= c) {
      if (c + diff <= num) {
        cout << c + diff << "\n";
      } else {
        cout << c + diff - num << "\n";
      }
    } else {
      cout << "-1\n";
    }
  }
}

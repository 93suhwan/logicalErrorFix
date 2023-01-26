#include <bits/stdc++.h>
using namespace std;
bool isSum(int sum, int a, int b) { return sum == a + b; }
bool check(int a, int b, int c) {
  if (a == b and c % 2 == 0) return true;
  if (b == c and a % 2 == 0) return true;
  if (a == c and b % 2 == 0) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (isSum(a, b, c) or isSum(b, a, c) or isSum(c, a, b)) {
      cout << "YES" << endl;
      continue;
    }
    if (check(a, b, c))
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

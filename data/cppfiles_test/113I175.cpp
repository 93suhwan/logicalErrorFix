#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    long long num1 = x1 * (pow(10, p1));
    long long num2 = x2 * (pow(10, p2));
    if (num1 > num2)
      cout << ">\n";
    else if (num1 < num2)
      cout << "<\n";
    else
      cout << "=\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && c % 2 == 0)
      cout << "YES";
    else if (a == c && b % 2 == 0)
      cout << "YES";
    else if (b == c && a % 2 == 0)
      cout << "YES";
    else if (a + b == c)
      cout << "YES";
    else if (a + c == b)
      cout << "YES";
    else if (b + c == a)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

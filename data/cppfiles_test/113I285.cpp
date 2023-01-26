#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string x1, x2;
    long long p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    double num1 = stoi(x1), num2 = stoi(x2);
    for (int i = 1; i < x1.size(); i++) num1 /= 10;
    for (int i = 1; i < x2.size(); i++) num2 /= 10;
    if (x1.size() - 1 + p1 > x2.size() - 1 + p2)
      cout << ">" << endl;
    else if (x1.size() - 1 + p1 < x2.size() - 1 + p2)
      cout << "<" << endl;
    else if (num1 > num2)
      cout << ">" << endl;
    else if (num1 < num2)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
  return 0;
}

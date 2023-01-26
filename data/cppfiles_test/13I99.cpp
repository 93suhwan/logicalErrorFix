#include <bits/stdc++.h>
using namespace std;
int count(string a, string b, int m, int n) {
  if ((m == 0 && n == 0) || n == 0) return 1;
  if (m == 0) return 0;
  if (a[m - 1] == b[n - 1])
    return count(a, b, m - 1, n - 1) + count(a, b, m - 1, n);
  else
    return count(a, b, m - 1, n);
}
int main() {
  string a;
  cin >> a;
  string b1 = "AB";
  string b2 = "BC";
  int n1 = count(a, b1, a.size(), b1.size());
  int n2 = count(a, b2, a.size(), b2.size());
  int x = n1 + n2;
  if (n1 == a.size()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}

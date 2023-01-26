#include <bits/stdc++.h>
using namespace std;
string solution() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  if (sum % 2) {
    return "NO";
  }
  sum /= 2;
  if (a + b == sum && sum == c) {
    return "YES";
  }
  if (b + c == sum && sum == a) return "YES";
  if (a + c == sum && sum == b) return "YES";
  if (a == b || b == c || c == a) return "YES";
  return "NO";
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solution() << endl;
}

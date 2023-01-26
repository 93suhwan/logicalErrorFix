#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  long long int t, i;
  cin >> t;
  for (i = 1; i <= t; i++) {
    string s;
    cin >> s;
    long long int sum = 0;
    long long int c1 = 0, c2 = 0, c3 = 0;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        sum = sum;
        c1++;
      } else if (s[i] == '2') {
        sum = sum;
        c2++;
      } else {
        sum += 1;
        c3++;
      }
    }
    if (c1 == 0 && c2 != 0 && c3 != 0)
      cout << min(1, sum) << "\n";
    else if (c2 == 0 && c1 != 0 && c3 != 0)
      cout << min(2, sum) << "\n";
    else if (c3 == 0 && c2 != 0 && c1 != 0)
      cout << min(0, sum) << "\n";
    else if (c1 == 0 && c2 == 0)
      cout << min(1, sum) << "\n";
    else if (c2 == 0 && c3 == 0)
      cout << min(0, sum) << "\n";
    else
      cout << min(0, sum) << "\n";
  }
  return 0;
}

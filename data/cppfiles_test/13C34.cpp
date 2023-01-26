#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long a, b, c;
    a = 0;
    b = 0;
    c = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else
        c++;
    }
    long long sum = 0;
    if (a <= b) {
      sum += a;
      b -= a;
    } else if (c <= b) {
      sum += c;
      b -= c;
    }
    sum += b;
    if (s.length() % 2 != 0)
      cout << "no" << endl;
    else {
      if (sum == (s.length() / 2))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    string s;
    cin >> s;
    long long a = count(s.begin(), s.end(), 'B');
    long long b = s.size() - a;
    if (a == b)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}

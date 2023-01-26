#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
void Sun_god() {
  string s1;
  long long x2;
  cin >> s1 >> x2;
  string s2 = to_string((long long)pow(10, x2));
  string f1 = s1 + s2;
  string s3;
  long long x4;
  cin >> s3 >> x4;
  string s4 = to_string((long long)pow(10, x4));
  string f2 = s3 + s4;
  if (f1.length() > f2.length()) {
    cout << ">"
         << "\n";
  } else if (f2.length() > f1.length()) {
    cout << "<"
         << "\n";
  } else {
    long long num1 = stoi(s1);
    long long num2 = stoi(s3);
    if (x2 > x4) {
      num1 = num1 * pow(10, x2 - x4);
    } else {
      num2 = num2 * pow(10, x4 - x2);
    }
    if (num1 > num2) {
      cout << ">"
           << "\n";
    } else if (num2 > num1) {
      cout << "<"
           << "\n";
    } else {
      cout << "="
           << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Sun_god();
  }
  return 0;
}

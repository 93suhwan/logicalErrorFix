#include <bits/stdc++.h>
using namespace std;
void busted() {
  long long x1, p1;
  cin >> x1 >> p1;
  long long x2, p2;
  cin >> x2 >> p2;
  if (p1 == p2) {
    if (x1 > x2) {
      cout << ">\n";
    } else if (x1 < x2) {
      cout << "<\n";
    } else {
      cout << "=\n";
    }
    return;
  }
  string str1 = to_string(x1);
  string str2 = to_string(x2);
  if ((long long)str1.size() + p1 > (long long)str2.size() + p2) {
    cout << ">\n";
    return;
  }
  if ((long long)str1.size() + p1 < (long long)str2.size() + p2) {
    cout << "<\n";
    return;
  }
  if ((long long)str1.size() > (long long)str2.size()) {
    for (long long i = (long long)str2.size() - 1; i < (long long)str1.size();
         i++) {
      str2 += '0';
    }
  }
  if ((long long)str1.size() < (long long)str2.size()) {
    for (long long i = (long long)str1.size() - 1; i < (long long)str2.size();
         i++) {
      str1 += '0';
    }
  }
  for (long long i = 0; i < str2.size(); i++) {
    if (str1[i] > str2[i]) {
      cout << ">\n";
      return;
    }
    if (str1[i] < str2[i]) {
      cout << "<\n";
      return;
    }
  }
  cout << "=\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) busted();
  return 0;
}

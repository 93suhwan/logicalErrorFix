#include <bits/stdc++.h>
using namespace std;
long long solve(long long n, string str1, string str2) {
  long long t1 = 0, t2 = 0;
  for (long long i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      if (str1[i] == '1')
        t1++;
      else
        t2++;
    }
  }
  if (t1 != t2)
    return -1;
  else
    return 2 * t1;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string str1, str2;
    cin >> n;
    cin >> str1 >> str2;
    long long a1 = solve(n, str1, str2);
    long long ind = -1;
    for (long long i = 0; i < n; i++) {
      if (str1[i] == '1') {
        ind = i;
        break;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (str1[i] == '1' && i != ind)
        str1[i] = '0';
      else if (str1[i] == '0')
        str1[i] = '1';
    }
    long long a2 = solve(n, str1, str2);
    if (a1 == -1 && a2 == -1) {
      cout << "-1" << endl;
    } else {
      if (a1 == -1)
        cout << (1 + a2) << endl;
      else if (a2 == -1)
        cout << a1 << endl;
      else
        cout << min(a1, 1 + a2) << endl;
    }
  }
  return 0;
}

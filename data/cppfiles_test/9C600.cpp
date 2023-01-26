#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    string s;
    cin >> s;
    long long int j, a[26] = {0};
    for (j = 0; j < s.size(); j++) {
      a[s[j] - 97]++;
    }
    long long int c1 = 0, co = 0;
    for (j = 0; j < 26; j++) {
      if (a[j] > 1) co++;
      if (a[j] == 1) c1++;
    }
    cout << co + (c1 / 2) << endl;
  }
  return 0;
}

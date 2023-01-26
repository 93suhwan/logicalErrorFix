#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long int a[26] = {}, i, p = 0, s = 0;
    for (i = 0; i < str.length(); i++) a[str[i] - 'a']++;
    for (i = 0; i < 26; i++)
      if (a[i] > 1)
        p++;
      else if (a[i])
        s++;
    cout << s / 2 + p << endl;
  }
  return 0;
}

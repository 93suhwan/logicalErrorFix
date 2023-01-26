#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string p, q;
    long long int count = 0;
    for (long long int i = 0; s[i] != '\0'; i++) count++;
    if (count == 1)
      cout << "no" << endl;
    else {
      p = s[0];
      for (long long int i = 1; i < (count / 2); i++) {
        p += s[i];
      }
      q = s[count / 2];
      for (long long int i = (count / 2) + 1; i < count; i++) {
        q += s[i];
      }
      if (p == q)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}

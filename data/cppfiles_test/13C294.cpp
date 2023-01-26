#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long k = 0, k1 = 0, k2 = 0;
    for (long long i = 0; i < s.size(); ++i) {
      if (s[i] == 'A') k++;
      if (s[i] == 'B') k1++;
      if (s[i] == 'C') k2++;
    }
    if (k + k2 == k1)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int j = 0;
    long long int n = s.size();
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'N') j++;
    }
    if (j == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long ans = 0;
    string str;
    cin >> str;
    int p = str.length();
    for (long long i = 0; i < p; i++) {
      if (str[i] == 'N') ans++;
    }
    if (ans == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    long long n = S.length();
    if (n == 2) {
      if (S[0] == S[1])
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else
      cout << "YES"
           << "\n";
  }
  return 0;
}

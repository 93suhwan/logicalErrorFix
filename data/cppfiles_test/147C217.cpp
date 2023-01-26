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
    long long count = 0;
    for (long long i = 0; i < n; i++) {
      if (S[i] == 'N') count++;
    }
    if ((count > 1) || (count == 0))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}

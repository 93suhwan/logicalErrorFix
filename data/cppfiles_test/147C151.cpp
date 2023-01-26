#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long c = 0;
    for (auto x : s) {
      if (x == 'N') c++;
    }
    if (c == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}

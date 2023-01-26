#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long count = (s[0] == '0');
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '0' && s[i - 1] != '0') count++;
    }
    cout << min(count, 2ll) << endl;
  }
}

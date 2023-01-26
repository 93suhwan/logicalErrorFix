#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, sum, n;
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        sum++;
      }
    }
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] == '0') {
        sum++;
      }
    }
    if (sum >= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

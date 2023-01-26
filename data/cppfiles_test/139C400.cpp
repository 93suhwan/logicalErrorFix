#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int size = s.length();
    long long int count(0);
    if (size % 2 != 0) {
      cout << "NO" << endl;
    } else {
      string s2;
      for (int i = (size / 2); i < size; ++i) {
        s2.push_back(s[i]);
      }
      for (int i = 0; i <= (size / 2); ++i) {
        if (s[i] == s2[i]) ++count;
      }
      if (count == (size / 2))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}

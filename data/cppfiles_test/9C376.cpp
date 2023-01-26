#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;
const int INF = 1e9 + 2;
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (T& x : a) in >> x;
  return in;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int a[26] = {0};
    for (int i = 0; i < n; i++) {
      a[s[i] - 'a']++;
    }
    int red = 0, green = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] == 1) {
        if (green > red) {
          red += 1;
        } else
          green += 1;
      }
      if (a[i] >= 2) {
        red += 1;
        green += 1;
      }
    }
    cout << min(red, green) << endl;
  }
}

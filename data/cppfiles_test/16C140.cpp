#include <bits/stdc++.h>
const unsigned int MOD = 1000000007;
const long double r = 1e+9;
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> v;
    string s;
    cin >> s;
    string s1 = s;
    sort(s1.begin(), s1.end());
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s1[i]) {
        x++;
      }
    }
    cout << x << endl;
  }
}

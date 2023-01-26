#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, j, count;
  cin >> t;
  string s;
  for (i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
    string cpy;
    cpy = s;
    count = 0;
    sort(cpy.begin(), cpy.end());
    for (j = 0; j < n; j++) {
      if (s[j] != cpy[j]) {
        count++;
      }
    }
    cout << count << endl;
  }
}

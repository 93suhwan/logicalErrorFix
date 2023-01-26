#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
string second;
void num_to_str(int num) {
  if (num) {
    num_to_str((num - 1) / 26);
    second += ('a' + (num - 1) % 26);
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, k = 0, d = 0, f = 0, a, b, c = 0, j = 0, ans = 0;
    string s;
    cin >> s;
    long long l = s.size();
    sort(s.begin(), s.end());
    for (i = 0; i < l - 1; i++) {
      if (s[i] == s[i + 1])
        f++;
      else {
        if (f > 2) d += f - 2;
        f = 0;
      }
    }
    if (f > 2) d += f - 2;
    cout << (l - d) / 2 << endl;
  }
}

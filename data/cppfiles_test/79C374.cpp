#include <bits/stdc++.h>
const long long int sz = 2 * 1e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    long long int c = 0;
    char ch;
    map<char, long long int> m;
    long long int a[21] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                           53, 59, 61, 67, 71, 73, 89, 83, 89, 97};
    for (auto it : s) {
      if ((it) == '1' || it == '4' || it == '6' || it == '8' || it == '9') {
        ch = it;
        c++;
      }
      m[it]++;
    }
    if (c) {
      cout << 1 << "\n";
      cout << ch << "\n";
    } else if (m['2'] > 1) {
      cout << 2 << "\n";
      cout << 22 << "\n";
    } else if (m['3'] > 1) {
      cout << 2 << "\n";
      cout << 33 << "\n";
    } else if (m['5'] > 1) {
      cout << 2 << "\n";
      cout << 55 << "\n";
    } else if (m['7'] > 1) {
      cout << 2 << "\n";
      cout << 77 << "\n";
    } else {
      long long int ans = -1;
      for (long long int i = 0; i < k; i++) {
        for (long long int j = i + 1; j < k; j++) {
          long long int num = (s[i] - '0') * 10 + s[j] - '0';
          if (!binary_search(a, a + 21, num)) {
            ans = num;
            break;
          }
        }
        if (ans != -1) break;
      }
      cout << 2 << "\n";
      cout << ans << "\n";
    }
  }
}

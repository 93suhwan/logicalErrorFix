#include <bits/stdc++.h>
using namespace std;
int calc_XOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    bool found = false;
    for (int i{1}; i < s.size() - 1; i++) {
      if (s[i - 1] != s[i]) {
        cout << i << " " << i + 1 << endl;
        found = true;
        break;
      }
      if (s[i] != s[i + 1]) {
        cout << i + 1 << " " << i + 2 << endl;
        found = true;
        break;
      }
    }
    if (!found) cout << "-1 -1" << endl;
  }
  return 0;
}

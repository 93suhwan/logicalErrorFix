#include <bits/stdc++.h>
using namespace std;
int count(string &s) {
  int n = s.length();
  int counter = n + 1;
  for (char c = 'a'; c <= 'z'; c++) {
    int count = 0;
    int j = 0, k = n - 1;
    while (j <= k) {
      if (s[j] != s[k]) {
        if (s[j] != c && s[k] != c) {
          count = n + 1;
          break;
        } else if (s[j] == c && s[k] != c) {
          j++;
          count++;
        } else if (s[k] == c && s[j] != c) {
          k--;
          count++;
        }
      } else {
        j++;
        k--;
      }
    }
    counter = min(count, counter);
  }
  return counter;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int k = count(s);
    if (k == n + 1)
      cout << "-1"
           << "\n";
    else
      cout << k << "\n";
  }
}

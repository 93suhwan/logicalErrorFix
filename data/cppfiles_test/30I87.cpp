#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  setup();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int ans = -1;
    for (int k = 0; k < 26; k++) {
      char c = k + 'a';
      long long int i = 0, j = n - 1, tans = 0;
      while (i < j) {
        if (s[i] != s[j]) {
          if (s[i] == c) {
            i++;
            tans++;
            continue;
          } else if (s[j] == c) {
            j--;
            tans++;
            continue;
          } else {
            break;
          }
        }
        i++;
        j--;
      }
      if (i >= j) {
        ans = max(ans, tans);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

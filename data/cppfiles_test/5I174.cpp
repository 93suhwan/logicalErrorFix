#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    long long n;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    for (long long j = 0; j < n; j = j + 2) {
      if (s[1][j] == '1' && (j + 1) < n && s[0][j + 1] == '1') {
        s[0][j + 1] = '2';
        s[1][j] = '0';
      }
    }
    for (long long j = 1; j < n; j += 2) {
      if (s[1][j] == '1' && (j - 1) >= 0 && s[0][j - 1] == '1') {
        s[0][j - 1] = '2';
        s[1][j] = '0';
      }
    }
    for (long long j = 0; j < n; j++) {
      if (s[1][j] == '1' && s[0][j] == '0') {
        s[0][j] = '2';
      }
    }
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      if (s[0][j] == '2') sum++;
    }
    cout << sum << '\n';
  }
  return 0;
}

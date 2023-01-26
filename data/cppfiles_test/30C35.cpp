#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string S) {
  string P = S;
  reverse(P.begin(), P.end());
  if (S == P) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (isPalindrome(s)) {
      cout << 0 << "\n";
      continue;
    }
    long long arr[123] = {0};
    for (long long i = 0; i < n; i++) {
      arr[s[i]]++;
    }
    long long mn = INT_MAX;
    for (long long i = 97; i < 123; i++) {
      long long count = 0;
      long long l = 0, r = n - 1;
      if (arr[i] > 0) {
        while (l < r) {
          if (s[l] == s[r]) {
            l++;
            r--;
          } else if (s[l] == i) {
            l++;
            count++;
          } else if (s[r] == i) {
            r--;
            count++;
          } else {
            count = INT_MAX;
            break;
          }
        }
        mn = min(mn, count);
      }
    }
    if (mn != INT_MAX) {
      cout << mn << "\n";
    } else
      cout << -1 << "\n";
  }
}

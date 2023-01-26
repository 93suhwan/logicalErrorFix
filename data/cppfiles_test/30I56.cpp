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
    long long a[123] = {0};
    for (long long i = 0; i < n; i++) {
      arr[s[i]]++;
    }
    for (long long i = 97; i < 123; i++) {
      if (arr[i] > 0) {
        string st = "";
        for (long long j = 0; j < n; j++) {
          if (s[j] != i) {
            st = st + s[j];
          }
        }
        if (isPalindrome(st)) {
          a[i]++;
        }
      }
    }
    long long mn = INT_MAX;
    for (long long i = 97; i < 123; i++) {
      if (a[i] > 0) {
        long long count = 0;
        for (long long j = 0; j < n; j++) {
          if (s[j] == i) {
            if (s[n - j - 1] != i) count++;
          }
        }
        mn = min(mn, count);
      }
    }
    if (mn != INT_MAX) {
      cout << mn << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}

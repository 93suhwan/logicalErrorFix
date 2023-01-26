#include <bits/stdc++.h>
using namespace std;
void solve(long long int caseno) {
  long long int n, start = 0;
  cin >> n;
  string s;
  cin >> s;
  while (start < n && s[start] == '?') start++;
  for (long long int i = start; i < n;) {
    if (s[i] == '?') {
      char prev = s[i - 1];
      long long int j = i;
      while (j < n && s[j] == '?') {
        if (prev == 'R')
          s[j] = 'B';
        else
          s[j] = 'R';
        prev = s[j];
        j++;
      }
      i = j;
    } else
      i++;
  }
  for (long long int i = n - 1; i >= 0;) {
    if (s[i] == '?') {
      char prev = s[i + 1];
      long long int j = i;
      while (j >= 0 && s[j] == '?') {
        if (prev == 'R')
          s[j] = 'B';
        else
          s[j] = 'R';
        prev = s[j];
        j--;
      }
      i = j;
    } else
      i--;
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}

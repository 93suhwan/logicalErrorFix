#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j, t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    n = s.size();
    long long ts = t.size();
    long long k;
    long long cnt = 0;
    long long f = 0;
    for (i = 0; i < ts; i++) {
      for (j = 0; j < n; j++) {
        if (t[i] == s[j]) {
          while (t[i] == s[j] && j < n && i < ts) {
            j++;
            i++;
            cnt++;
          }
          break;
        }
      }
      k = j - 2;
      if (t[i] == s[k]) {
        while (t[i] == s[k] && k >= 0 && cnt < ts && i < ts) {
          k--;
          i++;
          cnt++;
        }
        break;
      }
    }
    if (cnt == ts)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

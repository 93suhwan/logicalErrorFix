#include <bits/stdc++.h>
using namespace std;
int a[11], b[5];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long x = n;
    memset(a, 0, sizeof(a));
    int ans = 0, chang = 0;
    while (x) {
      chang++;
      if (x % 10 && a[x % 10] == 0) {
        ans++;
        a[x % 10] = 1;
      }
      x /= 10;
    }
    if (ans == k)
      cout << n << "\n";
    else {
      string s = to_string(n);
      memset(a, -1, sizeof(a));
      memset(b, 0, sizeof(b));
      long long cnt = 0;
      for (int i = 0; i < s.size(); i++) {
        if (a[s[i] - '0'] == -1) {
          a[s[i] - '0'] = i;
          cnt++;
          b[cnt] = i;
          if (cnt > k && k == 2) {
            if (s[b[1]] > s[b[2]] && s[b[2]] > s[b[3]]) {
              for (int k = i; k < s.size(); k++) {
                s[k] = s[k - 1];
              }
            }
            if (s[b[1]] > s[b[3]] && s[b[3]] > s[b[2]]) {
              char p = s[b[2]];
              for (int k = b[2]; k < s.size(); k++) {
                s[k] = p + 1;
              }
            }
            if (s[b[2]] > s[b[1]] && s[b[1]] > s[b[3]]) {
              for (int k = i; k < s.size(); k++) {
                s[k] = s[k - 1];
              }
            }
            if (s[b[3]] > s[b[1]] && s[b[1]] > s[b[2]]) {
              char p = s[b[2]];
              for (int k = b[2]; k < s.size(); k++) {
                s[k] = p + 1;
              }
            }
            if (s[b[3]] > s[b[2]] && s[b[2]] > s[b[1]]) {
              char p = s[b[2]];
              for (int k = b[2]; k < s.size(); k++) {
                s[k] = p + 1;
              }
            }
            if (s[b[2]] > s[b[3]] && s[b[3]] > s[b[1]]) {
              for (int k = i; k < s.size(); k++) {
                s[k] = s[k - 1];
              }
            }
            cout << s << "\n";
            break;
          }
          if (cnt > k && k == 1) {
            if (s[i] < s[i - 1]) {
              for (int j = i; j < s.size(); j++) {
                s[j] = s[i - 1];
              }
              cout << s << "\n";
              break;
            } else {
              char l = s[i - 1];
              for (int j = a[s[i - 1] - '0']; j < s.size(); j++) {
                s[j] = l + 1;
              }
              cout << s << "\n";
              break;
            }
          }
        }
      }
    }
  }
}

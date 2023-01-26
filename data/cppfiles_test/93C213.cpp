#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ab = 0;
  int ba = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b')
      ab++;
    else if (s[i] == 'b' && s[i + 1] == 'a')
      ba++;
  }
  int del = 0;
  if (ab > ba) {
    del = ab - ba;
    for (int i = s.length() - 1; i >= 0 && del != 0; i--) {
      if (s[i] == 'b' && s[i - 1] == 'a') {
        s[i - 1] = 'b';
        del--;
      }
    }
  } else {
    del = ba - ab;
    for (int i = s.length() - 1; i >= 0 && del != 0; i--) {
      if (s[i] == 'a' && s[i - 1] == 'b') {
        s[i - 1] = 'a';
        del--;
      }
    }
  }
  cout << s << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long j = 1;
    long long cnt = 0;
    while (j < k) {
      j = j * 2;
      cnt++;
    }
    cnt += ceil((n - j) / (double)k);
    cout << cnt << endl;
  }
}

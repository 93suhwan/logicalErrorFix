#include <bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
int T, n;
bool not_prime(int x) {
  if (x == 1) return true;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return true;
  return false;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> s;
    memset(cnt, 0, sizeof(cnt));
    for (auto c : s) ++cnt[c - '0'];
    if (cnt[1]) {
      cout << 1 << endl << 1 << endl;
      continue;
    }
    if (cnt[4]) {
      cout << 1 << endl << 4 << endl;
      continue;
    }
    if (cnt[6]) {
      cout << 1 << endl << 6 << endl;
      continue;
    }
    if (cnt[8]) {
      cout << 1 << endl << 8 << endl;
      continue;
    }
    if (cnt[9]) {
      cout << 1 << endl << 9 << endl;
      continue;
    }
    if (cnt[2] >= 2) {
      cout << 2 << endl << 22 << endl;
      continue;
    }
    if (cnt[3] >= 2) {
      cout << 2 << endl << 33 << endl;
      continue;
    }
    if (cnt[5] >= 2) {
      cout << 2 << endl << 55 << endl;
      continue;
    }
    if (cnt[7] >= 2) {
      cout << 2 << endl << 77 << endl;
      continue;
    }
    int mx = 1 << 30;
    for (int i = 1; i < (1 << n); ++i) {
      int num = 0;
      for (int p = 0; p < n; ++p) {
        if (i & (1 << p)) num = num * 10 + s[p] - '0';
      }
      if (not_prime(num)) mx = min(mx, num);
    }
    if (mx < 10)
      cout << 1 << endl;
    else if (mx < 100)
      cout << 2 << endl;
    else if (mx < 1000)
      cout << 3 << endl;
    else
      cout << 4 << endl;
    cout << mx << endl;
  }
  return 0;
}

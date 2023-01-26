#include <bits/stdc++.h>
using namespace std;
long long _r() {
  long long x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
string a;
int cnt[1000] = {0};
void Init() {
  cin >> a;
  for (int i = 0; i < 26; i++) {
    cnt[i] = 0;
  }
}
void solve() {
  for (int i = 0; i < a.length(); i++) {
    cnt[a[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] <= 2) {
      ans += cnt[i];
    } else {
      ans += 2;
    }
  }
  cout << (ans >> 1);
}
int main() {
  int t = _r();
  while (t--) {
    Init();
    solve();
    if (t) printf("\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
unsigned long long t, n, a;
void judge() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> a;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    unsigned long long now = 1, tim = 0, flag = 0;
    while (now <= a) {
      now *= 2;
      tim++;
      if (now >= n) {
        cout << tim << "\n";
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    tim += (n - now) / a;
    if ((n - now) % a) {
      tim++;
    }
    cout << tim << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void dibya() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = INT_MAX;
  for (int i = 'a'; i <= 'z'; i++) {
    long long l, r;
    l = 0;
    r = n - 1;
    long long res = 0;
    while (l <= r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else if (s[l] == i) {
        l++;
        res++;
      } else if (s[r] == i) {
        r--;
        res++;
      } else {
        res = INT_MAX;
        break;
      }
    }
    ans = min(res, ans);
  }
  if (ans == INT_MAX) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    dibya();
  }
  return 0;
}

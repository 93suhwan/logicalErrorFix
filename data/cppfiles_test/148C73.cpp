#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  for (long long t = 0; t < tc; t++) {
    long long w, h;
    cin >> w >> h;
    long long max_hor1 = LONG_MIN;
    long long min_hor1 = LONG_MAX;
    long long hor1;
    cin >> hor1;
    long long num;
    for (long long i = 0; i < hor1; i++) {
      cin >> num;
      max_hor1 = max(max_hor1, num);
      min_hor1 = min(min_hor1, num);
    }
    long long diff1 = max_hor1 - min_hor1;
    long long ans = diff1 * h;
    long long hor2;
    cin >> hor2;
    long long max_hor2 = LONG_MIN;
    long long min_hor2 = LONG_MAX;
    for (long long i = 0; i < hor2; i++) {
      cin >> num;
      max_hor2 = max(max_hor2, num);
      min_hor2 = min(min_hor2, num);
    }
    long long diff2 = max_hor2 - min_hor2;
    long long ans2 = diff2 * h;
    ans = max(ans, ans2);
    long long fin = ans;
    long long ver1;
    cin >> ver1;
    long long max_ver1 = LONG_MIN;
    long long min_ver1 = LONG_MAX;
    for (long long i = 0; i < ver1; i++) {
      cin >> num;
      max_ver1 = max(max_ver1, num);
      min_ver1 = min(min_ver1, num);
    }
    long long diff_ver1 = max_ver1 - min_ver1;
    ans = diff_ver1 * w;
    long long ver2;
    cin >> ver2;
    long long max_ver2 = LONG_MIN;
    long long min_ver2 = LONG_MAX;
    for (long long i = 0; i < ver2; i++) {
      cin >> num;
      max_ver2 = max(max_ver2, num);
      min_ver2 = min(min_ver2, num);
    }
    long long diff_ver2 = max_ver2 - min_ver2;
    ans2 = diff_ver2 * w;
    ans = max(ans, ans2);
    ans = max(fin, ans);
    cout << ans << "\n";
  }
  return 0;
}

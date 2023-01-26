#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    int w, h;
    cin >> w >> h;
    int max_hor1 = INT_MIN;
    int min_hor1 = INT_MAX;
    int hor1;
    cin >> hor1;
    int num;
    for (int i = 0; i < hor1; i++) {
      cin >> num;
      max_hor1 = max(max_hor1, num);
      min_hor1 = min(min_hor1, num);
    }
    int diff1 = max_hor1 - min_hor1;
    int ans = diff1 * h;
    int hor2;
    cin >> hor2;
    int max_hor2 = INT_MIN;
    int min_hor2 = INT_MAX;
    for (int i = 0; i < hor2; i++) {
      cin >> num;
      max_hor2 = max(max_hor2, num);
      min_hor2 = min(min_hor2, num);
    }
    int diff2 = max_hor2 - min_hor2;
    int ans2 = diff2 * h;
    ans = max(ans, ans2);
    int fin = ans;
    int ver1;
    cin >> ver1;
    int max_ver1 = INT_MIN;
    int min_ver1 = INT_MAX;
    for (int i = 0; i < ver1; i++) {
      cin >> num;
      max_ver1 = max(max_ver1, num);
      min_ver1 = min(min_ver1, num);
    }
    int diff_ver1 = max_ver1 - min_ver1;
    ans = diff_ver1 * w;
    int ver2;
    cin >> ver2;
    int max_ver2 = INT_MIN;
    int min_ver2 = INT_MAX;
    for (int i = 0; i < ver2; i++) {
      cin >> num;
      max_ver2 = max(max_ver2, num);
      min_ver2 = min(min_ver2, num);
    }
    int diff_ver2 = max_ver2 - min_ver2;
    ans2 = diff_ver2 * w;
    ans = max(ans, ans2);
    ans = max(fin, ans);
    cout << ans << "\n";
  }
  return 0;
}

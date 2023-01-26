#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp, mp2;
    int color = 0, count = 0;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    for (int i = 0; i < n; i++) {
      mp2[a[i]] = 0;
      if (mp[a[i]] < k) {
        mp2[a[i]] = 1;
        count++;
      }
    }
    count -= count % k;
    int counter = 0;
    for (int i = 0; i < n; i++) {
      if (mp2[a[i]] == 1 && counter < count) {
        counter++;
        color++;
        color = (color > k) ? 1 : color;
        cout << color;
      } else if (mp2[a[i]] == 1 && counter >= count) {
        cout << "0";
      } else if (mp2[a[i]] == 0) {
        if (mp[a[i]] > k) {
          cout << "0";
        } else {
          cout << mp[a[i]];
        }
        mp[a[i]]--;
      }
      if (i + 1 < n) cout << " ";
    }
    cout << "\n";
  }
  return 0;
}

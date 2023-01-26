#include <bits/stdc++.h>
using namespace std;
int n, num, k;
int a[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    unordered_map<int, int> mp;
    int color = 1;
    for (int i = 0; i < n; i++) {
      cin >> num;
      mp[num]++;
      if (mp[num] > k)
        a[i] = 0;
      else {
        a[i] = color;
        if (color == k)
          color = 1;
        else
          color++;
      }
    }
    if (color == 1) {
      for (int i = 0; i < n; i++) cout << a[i] << " ";
    } else {
      color--;
      for (int i = n - 1; i >= 0; i--)
        if (a[i] == color) {
          a[i] = 0;
          color--;
        }
      for (int i = 0; i < n; i++) cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}

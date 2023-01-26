#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int arr[26], n = s.size(), ans = 0;
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; ++i) {
      ++arr[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      ans += min(2, arr[i]);
    }
    cout << ans / 2 << "\n";
  }
  return 0;
}

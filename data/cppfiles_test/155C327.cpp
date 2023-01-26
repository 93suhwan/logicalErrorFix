#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].first, vec[i].second = i;
    }
    string s;
    cin >> s;
    sort(vec.begin(), vec.end());
    int ans = n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[vec[i].second] == '1') {
        vec[i].first = ans;
        ans--;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[vec[i].second] == '0') {
        vec[i].first = ans;
        ans--;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      swap(vec[i].first, vec[i].second);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
      cout << vec[i].second << " ";
    }
    cout << "\n";
  }
  return 0;
}

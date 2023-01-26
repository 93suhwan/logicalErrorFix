#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    set<int> ans;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    string s;
    cin >> s;
    vector<int> b, r;
    for (int i = 0; i < n; i++) {
      char s1 = s[i];
      if (s1 == 'R') {
        r.push_back(arr[i]);
      } else {
        b.push_back(arr[i]);
      }
    }
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    bool flag = true;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] < i + 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (int i = b.size(); i < n; i++) {
        if (r[i - b.size()] > i + 1) {
          flag = false;
        }
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

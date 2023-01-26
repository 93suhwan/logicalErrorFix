#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int I = 0; I < n; I++) cin >> arr[I];
    cin >> s;
    priority_queue<int, vector<int>, greater<int>> blues;
    priority_queue<int, vector<int>, greater<int>> reds;
    for (int I = 0; I < n; I++) {
      if (s[I] == 'B') {
        blues.push(arr[I]);
      } else {
        reds.push(arr[I]);
      }
    }
    bool flag = true;
    for (int I = 1; I < n + 1; I++) {
      if (blues.size() and blues.top() >= I) {
        blues.pop();
      } else {
        if (reds.size() and reds.top() <= I) {
          reds.pop();
        } else {
          flag = false;
        }
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

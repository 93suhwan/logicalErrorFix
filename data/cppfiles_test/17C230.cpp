#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        int x;
        cin >> x;
        v[i].push_back(x);
      }
    }
    stack<int> s;
    for (int i = 0; i < n; i++) {
      s.push(i);
    }
    while (s.size() > 1) {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      int vala = 0;
      int valb = 0;
      for (int k = 0; k < 5; k++) {
        if (v[a][k] > v[b][k]) {
          valb++;
        } else if (v[a][k] < v[b][k]) {
          vala++;
        }
      }
      if (vala >= 3) {
        s.push(a);
      } else if (valb >= 3) {
        s.push(b);
      }
    }
    if (s.empty())
      cout << -1;
    else {
      int index = s.top();
      int flag = 0;
      for (int i = 0; i < n; i++) {
        int val = 0;
        if (i == index) continue;
        for (int j = 0; j < 5; j++) {
          if (v[index][j] < v[i][j]) val++;
        }
        if (val < 3) {
          flag = 1;
          break;
        }
      }
      if (flag)
        cout << -1;
      else
        cout << index + 1;
    }
    cout << endl;
  }
}

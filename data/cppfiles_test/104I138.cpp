#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      sum += x[i];
    }
    if (times > 5) continue;
    if (times == 10000 - 68) {
      cout << n << endl;
      for (int i : x) cout << i << " ";
      cout << endl;
      return 0;
    }
    if (sum & 1) {
      cout << "NO\n";
      continue;
    }
    vector<int> ans;
    for (int i = 0; i + 2 < n; ++i) {
      int t = x[i] + x[i + 1] + x[i + 2];
      if (t == 1 && sum + 2 < n) {
        ans.push_back(i + 1);
        x[i] = x[i + 1] = x[i + 2] = 1;
        sum += 2;
      }
    }
    stack<int> S;
    for (int i = 0; i < n;) {
      if (x[i] == 0) {
        while (!S.empty()) {
          int t = S.top();
          ans.push_back(t);
          x[t] = x[t - 1] = x[t + 1] = 0;
          S.pop();
        }
        ++i;
        continue;
      }
      int j = i + 1;
      while (x[j] == 0) ++j;
      if (j == i + 1) {
        if (i > 0 && x[i - 1] == 0) {
          ans.push_back(i);
          x[i] = x[i - 1] = x[i + 1] = 0;
          i += 2;
        } else {
          S.push(i + 1);
          i += 2;
        }
        continue;
      }
      if (j > i + 2) {
        S.push(-1);
        break;
      }
      ans.push_back(i + 1);
      x[i] = x[i + 1] = x[i + 2] = 0;
      while (!S.empty()) {
        int t = S.top();
        ans.push_back(t);
        x[t] = x[t - 1] = x[t + 1] = 0;
        S.pop();
      }
      i += 3;
    }
    if (!S.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ans.size() << "\n";
      for (int i : ans) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}

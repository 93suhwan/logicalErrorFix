#include <bits/stdc++.h>
using namespace std;
struct debugger {
  static void call(string::iterator it, string::iterator ed) {}
  template <typename T, typename... aT>
  static void call(string::iterator it, string::iterator ed, T a, aT... rest) {
    string b;
    for (; *it != ','; ++it)
      if (*it != ' ') b += *it;
    cout << b << "=" << a << " ";
    call(++it, ed, rest...);
  }
};
bool compare(long long a, long long b) { return a > b; }
void solve() {
  int n;
  string::iterator(n);
  string a[n];
  vector<long long> a1, a2, a3, a4, a5;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int c[5] = {0};
    for (int j = 0; j < a[i].size(); j++) {
      if (a[i][j] == 'a') {
        c[0]++;
      } else if (a[i][j] == 'b') {
        c[1]++;
      } else if (a[i][j] == 'c') {
        c[2]++;
      } else if (a[i][j] == 'd') {
        c[3]++;
      } else {
        c[4]++;
      }
    }
    a1.push_back(2 * c[0] - a[i].size());
    a2.push_back(2 * c[1] - a[i].size());
    a3.push_back(2 * c[2] - a[i].size());
    a4.push_back(2 * c[3] - a[i].size());
    a5.push_back(2 * c[4] - a[i].size());
  }
  sort(a1.begin(), a1.end(), compare);
  sort(a2.begin(), a2.end(), compare);
  sort(a3.begin(), a3.end(), compare);
  sort(a4.begin(), a4.end(), compare);
  sort(a5.begin(), a5.end(), compare);
  long long ans = 0, tempAns = 0, total = 0;
  for (int i = 0; i < a1.size(); i++) {
    total += a1[i];
    if (total >= 1) {
      tempAns++;
    } else if (a1[i] == 0 && total) {
      tempAns++;
    } else if (total < 0) {
      break;
    }
  }
  ans = max(tempAns, ans);
  total = tempAns = 0;
  for (int i = 0; i < a2.size(); i++) {
    total += a2[i];
    if (total >= 1) {
      tempAns++;
    } else if (a2[i] == 0 && total > 0) {
      tempAns++;
    } else if (total <= 0) {
      break;
    }
  }
  ans = max(tempAns, ans);
  total = tempAns = 0;
  for (int i = 0; i < a3.size(); i++) {
    total += a3[i];
    if (total >= 1) {
      tempAns++;
    } else if (a3[i] == 0 && total > 0) {
      tempAns++;
    } else if (total <= 0) {
      break;
    }
  }
  ans = max(tempAns, ans);
  total = tempAns = 0;
  for (int i = 0; i < a4.size(); i++) {
    total += a4[i];
    if (total >= 1) {
      tempAns++;
    } else if (a4[i] == 0 && total > 0) {
      tempAns++;
    } else if (total <= 0) {
      break;
    }
  }
  ans = max(tempAns, ans);
  total = tempAns = 0;
  for (int i = 0; i < a5.size(); i++) {
    total += a5[i];
    if (total >= 1) {
      tempAns++;
    } else if (a5[i] == 0 && total > 0) {
      tempAns++;
    } else if (total <= 0) {
      break;
    }
  }
  ans = max(tempAns, ans);
  total = tempAns = 0;
  cout << ans << "\n";
}
int main() {
  int t;
  string::iterator(t);
  while (t--) {
    solve();
  }
  return 0;
}

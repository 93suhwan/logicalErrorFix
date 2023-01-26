#include <bits/stdc++.h>
using namespace std;
int a[30];
int b[30];
set<int> s;
vector<int> v;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0) a[i] = -a[i];
    }
    sort(a, a + n);
    bool flag = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0 || (i != 0 && a[i] == a[i - 1])) {
        flag = 1;
        break;
      }
      s.clear();
      for (int j = 0; j < n; j++) {
        if (j != i) {
          v.clear();
          for (auto x = s.begin(); x != s.end(); x++) {
            int t = *x;
            v.push_back(abs(t + a[j]));
            v.push_back(abs(t - a[j]));
          }
          v.push_back(a[j]);
          for (auto x = v.begin(); x != v.end(); x++) {
            s.insert(*x);
          }
        }
      }
      if (s.find(a[i]) != s.end()) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "No" << endl;
  }
}

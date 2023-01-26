#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, k;
    cin >> n >> s >> k;
    if (n < 3 && s + k == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else if (max(s, k) - min(s, k) >= 2) {
      cout << -1 << endl;
    } else if (s + k > n - 2) {
      cout << -1 << endl;
    } else {
      vector<int> ss, kk;
      int pos = n, pos2 = 1;
      for (int i = n; ss.size() < s; i--) {
        pos = i - 1;
        ss.push_back(i);
      }
      pos2 = pos - 1;
      int pos3 = pos2 - 1;
      for (int i = 1; kk.size() < k; i++) {
        pos3 = i + 1;
        kk.push_back(i);
      }
      if (s >= k) {
        for (int i = pos3; i < pos2; i++) {
          cout << i << " ";
        }
        cout << pos2 << " ";
        while (ss.size() != 0) {
          cout << ss.back() << " ";
          ss.pop_back();
          if (kk.size() != 0) {
            cout << kk.back() << " ";
            kk.pop_back();
          }
        }
        cout << pos << " ";
      } else {
        cout << pos2 << " ";
        for (int i = pos2 - 1; i >= pos3; i--) {
          cout << i << " ";
        }
        while (kk.size() != 0) {
          cout << kk.back() << " ";
          kk.pop_back();
          if (ss.size() != 0) {
            cout << ss.back() << " ";
            ss.pop_back();
          }
        }
        cout << pos << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

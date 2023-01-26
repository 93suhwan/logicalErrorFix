#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    long long int copy = (n - 2);
    long long int Max = ceil(((n - 2) * 1.0) / 2);
    if (a == 0 && b == 0) {
      copy = n;
      for (int i = 0; i < n; i++) {
        cout << copy << " ";
        copy--;
      }
      cout << "\n";
      continue;
    }
    if (a > Max || b > Max) {
      cout << -1 << endl;
      continue;
    }
    if ((a == 0 && b != 1) || (b == 0 && a != 1)) {
      cout << -1 << endl;
      continue;
    }
    if (abs(a - b) > 1) {
      cout << -1 << endl;
      continue;
    }
    copy = n;
    long long int copy1 = 1, k = 0, l = 0;
    vector<long long int> ans;
    if (a > b) {
      for (int i = 0; i < n; i++) {
        if (k == a) {
          break;
        }
        if (i % 2 == 0) {
          ans.push_back(copy1);
          copy1++;
        } else {
          if (i >= 1 && i < n - 1) {
            k++;
          }
          ans.push_back(copy);
          copy--;
        }
      }
      if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      } else {
        for (int i = ans.size(); i < n; i++) {
          ans.push_back(copy);
          copy--;
        }
        for (int i = 0; i < n; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      }
    } else if (b > a) {
      for (int i = 0; i < n; i++) {
        if (k == b) {
          break;
        }
        if (i % 2 == 0) {
          ans.push_back(copy);
          copy--;
        } else {
          if (i >= 1 && i < n - 1) {
            k++;
          }
          ans.push_back(copy1);
          copy1++;
        }
      }
      if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      } else {
        for (int i = ans.size(); i < n; i++) {
          ans.push_back(copy1);
          copy1++;
        }
        for (int i = 0; i < n; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (k == a && l == b) {
          break;
        }
        if (i % 2 == 0) {
          if (i >= 2 && i <= n - 2) {
            l++;
          }
          ans.push_back(copy1);
          copy1++;
        } else {
          if (i >= 1 && i < n - 1) {
            k++;
          }
          ans.push_back(copy);
          copy--;
        }
      }
      if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      } else {
        for (int i = ans.size(); i < n; i++) {
          ans.push_back(copy);
          copy--;
        }
      }
    }
  }
}

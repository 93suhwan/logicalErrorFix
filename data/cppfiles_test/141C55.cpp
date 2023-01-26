#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    int flag = 0;
    vector<int> ans;
    while (m != 0) {
      int x = n % 10;
      int y = m % 10;
      if (x <= y) {
        ans.push_back(y - x);
      } else {
        m /= 10;
        y = y + 10 * (m % 10);
        if (x < y && y >= 10 && y <= 19) {
          ans.push_back(y - x);
        } else {
          flag = 1;
          break;
        }
      }
      n /= 10;
      m /= 10;
    }
    if (flag == 1) {
      cout << -1 << "\n";
      continue;
    }
    if (n) {
      cout << -1 << "\n";
    } else {
      while (ans.back() == 0) ans.pop_back();
      for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
      }
      cout << "\n";
    }
  }
  return 0;
}

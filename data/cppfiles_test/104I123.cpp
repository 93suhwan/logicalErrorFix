#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    Vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Vi ans;
    int sum = count((a).begin(), (a).end(), 1);
    bool flag = false;
    int ones = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        if (ones % 2 == 1 && sum % 2 == 0 && i > 0 && i < n - 1 &&
            a[i - 1] == 1 && a[i + 1] == 1) {
          ans.push_back(i);
          a[i - 1] = a[i + 1] = 0;
          sum -= 2;
          --ones;
        }
        if (ones % 2 == 0 && sum % 2 == 0) {
          for (int j = i; j < n - 2; ++j) {
            if (a[j] + a[j + 1] + a[j + 2] == 2)
              ans.push_back(j), a[j] = a[j + 1] = a[j + 2] = 0;
            else if (a[j] == 1 && a[j + 1] == 0 && a[j + 2] == 0)
              ans.push_back(j), ans.push_back(j - 1), a[j] = 0, a[j + 2] = 1;
          }
          for (int j = i + 1 - 1; j >= 2; --j) {
            if (a[j] + a[j - 1] + a[j - 2] == 2)
              ans.push_back(j - 2), a[j] = a[j - 1] = a[j - 2] = 0;
            else if (a[j] == 1 && a[j - 1] == 0 && a[j - 2] == 0)
              ans.push_back(j - 2), ans.push_back(j - 1), a[j] = 0,
                                                          a[j - 2] = 1;
          }
          flag = true;
          break;
        }
      } else
        ++ones;
    }
    if (flag == false)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl << (int)ans.size() << endl;
      for (auto i : ans) cout << i + 1 << " ";
      cout << endl;
    }
  }
  return 0;
}

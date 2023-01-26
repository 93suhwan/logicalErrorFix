#include <bits/stdc++.h>
int n;
using namespace std;
int solve(vector<int>& a, int flag) {
  int i;
  int cnt = 0;
  if (flag == 1) {
    i = 1;
  } else
    i = 0;
  for (int j = 0; j < a.size(); j++, i += 2) {
    cnt += abs(a[j] - i);
  }
  return cnt;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a;
    int buf;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      cin >> buf;
      if (buf & 1) {
        a.push_back(i);
        odd++;
      } else
        even++;
    }
    if (abs(odd - even) > 1) {
      cout << -1 << endl;
    } else {
      if (odd > even)
        cout << solve(a, 0) << endl;
      else if (even > odd)
        cout << solve(a, 1) << endl;
      else
        cout << min(solve(a, 0), solve(a, 1)) << endl;
    }
  }
  return 0;
}

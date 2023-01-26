#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> ones;
    vector<int> zeros;
    ;
    string s;
    cin >> s;
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ones.push_back(a[i + 1]);
      } else
        zeros.push_back(a[i + 1]);
    }
    int k = ones.size();
    int max = n - k;
    sort(ones.begin(), ones.end());
    sort(zeros.begin(), zeros.end());
    map<int, int> m;
    map<int, int> p;
    int j = n;
    for (int i = k - 1; i >= 0; i--) {
      m[ones[i]] = j;
      j--;
    }
    for (int i = 0; i < max; i++) {
      p[zeros[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '0') {
        ans[i] = p[a[i]];
      } else {
        ans[i] = m[a[i]];
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}

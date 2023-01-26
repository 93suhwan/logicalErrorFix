#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    long long x;
    string s;
    cin >> n >> k >> x >> s;
    if (x == 1) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
          cout << s[i];
        }
      }
      cout << "\n";
      continue;
    }
    x--;
    vector<int> cp;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        cp.push_back(i);
      }
    }
    vector<long long> ix;
    for (int i = 0; i < cp.size(); ++i) {
      int sta;
      if (i == 0) {
        sta = -1;
      } else {
        sta = cp[i - 1];
      }
      ix.push_back((cp[i] - sta - 1) * 1LL * k + 1);
    }
    int ed = n - 1 - cp[cp.size() - 1];
    ix.push_back(ed * 1LL * k + 1);
    int op = ix.size();
    vector<long long> ty(op);
    reverse(ix.begin(), ix.end());
    for (int i = 0; i < op; ++i) {
      ty[i] = x % ix[i];
      x /= ix[i];
    }
    string ans;
    for (int i = 0; i + 1 < ty.size(); ++i) {
      for (int j = 0; j < ty[i]; ++j) {
        ans.push_back('b');
      }
      ans.push_back('a');
    }
    for (int i = 0; i < ty[op - 1]; ++i) {
      ans.push_back('b');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
  return 0;
}

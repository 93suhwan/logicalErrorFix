#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long n;
    cin >> n;
    string s;
    long long ca, cb, cc, cd, ce;
    vector<long long> va, vb, vc, vd, ve;
    for (long long i = 0; i < n; i++) {
      cin >> s;
      ca = cb = cc = cd = ce = 0;
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] == 'a') ca++;
        if (s[i] == 'b') cb++;
        if (s[i] == 'c') cc++;
        if (s[i] == 'd') cd++;
        if (s[i] == 'e') ce++;
      }
      va.push_back(2 * ca - s.size());
      vb.push_back(2 * cb - s.size());
      vc.push_back(2 * cc - s.size());
      vd.push_back(2 * cd - s.size());
      ve.push_back(2 * ce - s.size());
    }
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    sort(vc.rbegin(), vc.rend());
    sort(vd.rbegin(), vd.rend());
    sort(ve.rbegin(), ve.rend());
    long long mx = 0;
    long long ans = INT_MIN;
    long long word = 0;
    for (auto i : va) {
      if (word + i > 0) {
        word += i;
        mx++;
      } else
        break;
    }
    ans = max(mx, ans);
    word = 0;
    mx = 0;
    for (auto i : vb) {
      if (word + i > 0) {
        word += i;
        mx++;
      } else
        break;
    }
    ans = max(mx, ans);
    word = 0;
    mx = 0;
    for (auto i : vc) {
      if (word + i > 0) {
        word += i;
        mx++;
      } else
        break;
    }
    ans = max(mx, ans);
    word = 0;
    mx = 0;
    for (auto i : vd) {
      if (word + i > 0) {
        word += i;
        mx++;
      } else
        break;
    }
    ans = max(mx, ans);
    word = 0;
    mx = 0;
    for (auto i : ve) {
      if (word + i > 0) {
        word += i;
        mx++;
      } else
        break;
    }
    ans = max(mx, ans);
    cout << ans << endl;
  }
  return 0;
}

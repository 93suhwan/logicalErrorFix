#include <bits/stdc++.h>
using namespace std;
bool check(string s, int l, int r) {
  int value = 0;
  for (int i = 0; i <= (r - l); i++) {
    if (i % 2 == 0) {
      if (s[i + l] == '+') {
        value++;
      } else {
        value--;
      }
    } else {
      if (s[i + l] == '-') {
        value++;
      } else {
        value--;
      }
    }
  }
  return value == 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int, int>> vp(n + 1);
    for (int i = 1; i <= n; i++) {
      vp[i] = vp[i - 1];
      if (s[i - 1] == '+') {
        vp[i].first++;
      } else {
        vp[i].second++;
      }
    }
    while (q--) {
      long long int l, r;
      cin >> l >> r;
      int count1 = vp[r].first - vp[l - 1].first;
      int count2 = vp[r].second - vp[l - 1].second;
      if (count1 == count2) {
        bool chck = check(s, l - 1, r - 1);
        if (chck) {
          cout << "0" << endl;
        } else {
          cout << 2 << endl;
        }
      } else {
        int val = abs(count2 - count1) % 2;
        if (val == 0) {
          cout << 2 << endl;
        } else {
          cout << 1 << endl;
        }
      }
    }
  }
  return 0;
}

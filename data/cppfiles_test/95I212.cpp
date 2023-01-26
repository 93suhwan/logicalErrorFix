#include <bits/stdc++.h>
using namespace std;
int codefo;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> codefo;
  while (codefo--) {
    int s, n;
    cin >> s >> n;
    long long t = 10;
    vector<int> temp;
    int te = s;
    while (te > 0) {
      temp.push_back(te % t);
      te -= te % t;
      t *= 10;
    }
    int cnt = 0;
    int ten = 1;
    int sz = temp.size();
    vector<int> ko(sz);
    for (int i = 0; i < sz; i++) {
      ko[i] = temp[i] / ten;
      cnt += ko[i];
      ten *= 10;
    }
    if (cnt >= n) {
      ten = 1;
      int now = 0;
      int sum = 0;
      for (int i = 0; i < sz; i++) {
        for (int j = 0; j < ko[i]; j++) {
          if (now < n - 1) {
            cout << ten << ' ';
            now++;
          } else {
            sum += ten;
          }
        }
        ten *= 10;
      }
      cout << sum << endl;
      continue;
    }
    ten = 1;
    while (cnt < n) {
      while (ko[1] == 0) {
        if (cnt >= n) break;
        for (int j = 2; j < sz; j++) {
          if (ko[j] > 0) {
            ko[j] -= 1;
            ko[j - 1] += 10;
            cnt += 9;
            if (cnt >= n) break;
            for (int k = j - 1; k > 1; k--) {
              ko[k] -= 1;
              ko[k - 1] += 10;
              cnt += 9;
              if (cnt >= n) break;
            }
          }
          if (cnt >= n) break;
        }
      }
      if (cnt >= n) break;
      ko[1] -= 1;
      ko[0] += 10;
      cnt += 9;
    }
    int now = 0, sum = 0;
    vector<int> ans(n);
    int id = 0;
    ten = 1;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < ko[i]; j++) {
        ans[id] += ten;
        id = (id + 1) % n;
      }
      ten *= 10;
    }
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        cout << ans[i] << ' ';
      else
        cout << ans[i] << endl;
    }
  }
}

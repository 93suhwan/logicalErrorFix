#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr) cin >> e;
    int ans = *max_element(arr.begin(), arr.end());
    int ans2 = INT_MAX;
    int cond = 1;
    for (int i : arr) {
      if (i & 1) {
        cond = 0;
        break;
      }
    }
    if (cond) ans2 = ans / 2;
    int ans3 = INT_MAX;
    cond = 1;
    for (int i : arr) {
      if (i % 3 != 0) {
        cond = 0;
        break;
      }
    }
    if (cond) ans3 = ans / 3;
    int c1 = 0, c2 = 0, c3 = 0;
    int ans4 = INT_MIN;
    for (int i : arr) {
      c2 = max(c2, i / 2);
      c1 = max(c1, i - 2 * (i / 2));
    }
    ans4 = c1 + c2;
    c1 = 0, c2 = 0, c3 = 0;
    int ans5 = INT_MIN;
    for (int i : arr) {
      c3 = max(c3, i / 3);
      c1 = max(c1, i - 3 * (i / 3));
    }
    ans5 = c1 + c3;
    c1 = 0, c2 = 0, c3 = 0;
    int ans6 = INT_MIN;
    for (int i : arr) {
      if (i == 1) {
        ans6 = INT_MAX;
        break;
      }
      if (i % 3 == 0) {
        c3 = max(c3, i / 3);
      } else if ((i - 2) % 3 == 0) {
        c3 = max(c3, (i - 2) / 3);
        c1 = max(c1, (i - 3 * ((i - 2) / 3)) / 2);
      } else {
        c3 = max(c3, (i - 4) / 3);
        c1 = max(c1, (i - 3 * ((i - 4) / 3)) / 2);
      }
      ans6 = max(ans6, c1 + c3);
    }
    c1 = 0, c2 = 0, c3 = 0;
    int ans7 = INT_MIN;
    for (int i : arr) {
      c3 = max(c3, i / 3);
      int r = i - 3 * (i / 3);
      if (r == 1 and !c1) {
        c1 = 1;
      } else if (!c2) {
        c2 = 1;
      }
      int i_know_my_love_u_r_reading_this = c3 - min(c1, c2);
      if ((3 * i_know_my_love_u_r_reading_this + 2 * c2 + c1) >= i) {
        ans7 = max(ans7, c1 + c2 + i_know_my_love_u_r_reading_this);
      } else {
        ans7 = max(ans7, c1 + c2 + c3);
      }
    }
    vector<int> v = {ans, ans2, ans3, ans4, ans5, ans6, ans7};
    cout << *min_element(v.begin(), v.end()) << endl;
  }
}

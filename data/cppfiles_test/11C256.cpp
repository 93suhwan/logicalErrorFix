#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp1(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return 2 * a[0] - s1 > 2 * b[0] - s2;
}
bool comp2(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return 2 * a[1] - s1 > 2 * b[1] - s2;
}
bool comp3(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return 2 * a[2] - s1 > 2 * b[2] - s2;
}
bool comp4(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return 2 * a[3] - s1 > 2 * b[3] - s2;
}
bool comp5(vector<int> a, vector<int> b) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    s1 += a[i];
    s2 += b[i];
  }
  return 2 * a[4] - s1 > 2 * b[4] - s2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n];
    vector<vector<int>> cnt(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (char c : s[i]) {
        cnt[i][c - 'a']++;
      }
    }
    sort(cnt.begin(), cnt.end(), comp1);
    int c1 = 0, c2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      c1 += cnt[i][0];
      c2 += cnt[i][1] + cnt[i][2] + cnt[i][3] + cnt[i][4];
      if (c1 > c2) {
        ans = max(ans, i + 1);
      }
    }
    sort(cnt.begin(), cnt.end(), comp2);
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      c1 += cnt[i][1];
      c2 += cnt[i][0] + cnt[i][2] + cnt[i][3] + cnt[i][4];
      if (c1 > c2) {
        ans = max(ans, i + 1);
      }
    }
    sort(cnt.begin(), cnt.end(), comp3);
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      c1 += cnt[i][2];
      c2 += cnt[i][1] + cnt[i][0] + cnt[i][3] + cnt[i][4];
      if (c1 > c2) {
        ans = max(ans, i + 1);
      }
    }
    sort(cnt.begin(), cnt.end(), comp4);
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      c1 += cnt[i][3];
      c2 += cnt[i][1] + cnt[i][2] + cnt[i][0] + cnt[i][4];
      if (c1 > c2) {
        ans = max(ans, i + 1);
      }
    }
    sort(cnt.begin(), cnt.end(), comp5);
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      c1 += cnt[i][4];
      c2 += cnt[i][1] + cnt[i][2] + cnt[i][3] + cnt[i][0];
      if (c1 > c2) {
        ans = max(ans, i + 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool cmp1(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    int q = a[4] + a[1] + a[2] + a[3];
    int p = b[4] + b[1] + b[2] + b[3];
    return q < p;
  }
  return a[0] > b[0];
}
bool cmp2(vector<int> a, vector<int> b) {
  if (a[1] == b[1]) {
    int q = a[0] + a[4] + a[2] + a[3];
    int p = b[0] + b[4] + b[2] + b[3];
    return q < p;
  }
  return a[1] > b[1];
}
bool cmp3(vector<int> a, vector<int> b) {
  if (a[2] == b[2]) {
    int q = a[0] + a[1] + a[4] + a[3];
    int p = b[0] + b[1] + b[4] + b[3];
    return q < p;
  }
  return a[2] > b[2];
}
bool cmp4(vector<int> a, vector<int> b) {
  if (a[3] == b[3]) {
    int q = a[0] + a[1] + a[2] + a[4];
    int p = b[0] + b[1] + b[2] + b[4];
    return q < p;
  }
  return a[3] > b[3];
}
bool cmp5(vector<int> a, vector<int> b) {
  if (a[4] == b[4]) {
    int q = a[0] + a[1] + a[2] + a[3];
    int p = b[0] + b[1] + b[2] + b[3];
    return q < p;
  }
  return a[4] > b[4];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> fr(n, vector<int>(5, 0));
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < s[i].size(); j++) {
        if (s[i][j] == 'a') fr[i][0]++;
        if (s[i][j] == 'b') fr[i][1]++;
        if (s[i][j] == 'c') fr[i][2]++;
        if (s[i][j] == 'd') fr[i][3]++;
        if (s[i][j] == 'e') fr[i][4]++;
      }
    }
    int ans = 0, cw = 0;
    sort(fr.begin(), fr.end(), cmp1);
    int cs = 0, co = 0;
    for (int i = 0; i < n; i++) {
      cs = cs + fr[i][0];
      co = co + fr[i][1] + fr[i][2] + fr[i][3] + fr[i][4];
      if (cs > co)
        cw++;
      else if (cs <= co) {
        cs = cs - fr[i][0];
        co = co - fr[i][1] - fr[i][2] - fr[i][3] - fr[i][4];
      }
    }
    ans = max(ans, cw);
    cw = 0;
    cs = 0, co = 0;
    sort(fr.begin(), fr.end(), cmp2);
    for (int i = 0; i < n; i++) {
      cs = cs + fr[i][1];
      co = co + fr[i][0] + fr[i][2] + fr[i][3] + fr[i][4];
      if (cs > co)
        cw++;
      else if (cs <= co) {
        cs = cs - fr[i][1];
        co = co - fr[i][0] - fr[i][2] - fr[i][3] - fr[i][4];
      }
    }
    ans = max(ans, cw);
    cw = 0;
    cs = 0, co = 0;
    sort(fr.begin(), fr.end(), cmp3);
    for (int i = 0; i < n; i++) {
      cs = cs + fr[i][2];
      co = co + fr[i][1] + fr[i][0] + fr[i][3] + fr[i][4];
      if (cs > co)
        cw++;
      else if (cs <= co) {
        cs = cs - fr[i][2];
        co = co - fr[i][1] - fr[i][0] - fr[i][3] - fr[i][4];
      }
    }
    ans = max(ans, cw);
    cw = 0;
    cs = 0, co = 0;
    sort(fr.begin(), fr.end(), cmp4);
    for (int i = 0; i < n; i++) {
      cs = cs + fr[i][3];
      co = co + fr[i][1] + fr[i][2] + fr[i][0] + fr[i][4];
      if (cs > co)
        cw++;
      else if (cs <= co) {
        cs = cs - fr[i][3];
        co = co - fr[i][1] - fr[i][2] - fr[i][0] - fr[i][4];
      }
    }
    ans = max(ans, cw);
    cw = 0;
    cs = 0, co = 0;
    sort(fr.begin(), fr.end(), cmp5);
    for (int i = 0; i < n; i++) {
      cs = cs + fr[i][4];
      co = co + fr[i][1] + fr[i][2] + fr[i][3] + fr[i][0];
      if (cs > co)
        cw++;
      else if (cs <= co) {
        cs = cs - fr[i][4];
        co = co - fr[i][1] - fr[i][2] - fr[i][3] - fr[i][0];
      }
    }
    ans = max(ans, cw);
    cout << ans << "\n";
  }
  return 0;
}

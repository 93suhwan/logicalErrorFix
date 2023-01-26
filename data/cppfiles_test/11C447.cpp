#include <bits/stdc++.h>
using namespace std;
typedef struct ps {
  int a[5] = {0, 0, 0, 0, 0};
} ps;
bool comp1(ps a, ps b) { return a.a[0] > b.a[0]; }
bool comp2(ps a, ps b) { return a.a[1] > b.a[1]; }
bool comp3(ps a, ps b) { return a.a[2] > b.a[2]; }
bool comp4(ps a, ps b) { return a.a[3] > b.a[3]; }
bool comp5(ps a, ps b) { return a.a[4] > b.a[4]; }
void solve() {
  int c;
  cin >> c;
  vector<ps> a;
  for (int i = 0; i < c; i++) {
    string s;
    cin >> s;
    ps t;
    int b[5] = {0};
    for (int i = 0; i < s.length(); i++) {
      b[s[i] - 'a']++;
    }
    t.a[0] = b[0] - (b[1] + b[2] + b[3] + b[4]);
    t.a[1] = b[1] - (b[0] + b[2] + b[3] + b[4]);
    t.a[2] = b[2] - (b[1] + b[0] + b[3] + b[4]);
    t.a[3] = b[3] - (b[1] + b[2] + b[0] + b[4]);
    t.a[4] = b[4] - (b[1] + b[2] + b[3] + b[0]);
    a.push_back(t);
  }
  int ans = 0;
  sort(a.begin(), a.end(), comp1);
  int d = 0, j = 0;
  bool f = true;
  while (j < a.size() && d > 0 || f) {
    f = false;
    d += a[j].a[0];
    if (d <= 0) break;
    j++;
  }
  ans = max(ans, j);
  sort(a.begin(), a.end(), comp2);
  f = true;
  d = 0, j = 0;
  while (j < a.size() && d > 0 || f) {
    d += a[j].a[1];
    f = false;
    if (d <= 0) break;
    j++;
  }
  ans = max(ans, j);
  sort(a.begin(), a.end(), comp3);
  f = true;
  d = 0, j = 0;
  while (j < a.size() && d > 0 || f) {
    d += a[j].a[2];
    f = false;
    if (d <= 0) break;
    j++;
  }
  ans = max(ans, j);
  sort(a.begin(), a.end(), comp4);
  f = true;
  d = 0, j = 0;
  while (j < a.size() && d > 0 || f) {
    d += a[j].a[3];
    f = false;
    if (d <= 0) break;
    j++;
  }
  ans = max(ans, j);
  sort(a.begin(), a.end(), comp5);
  f = true;
  d = 0, j = 0;
  while (j < a.size() && d > 0 || f) {
    d += a[j].a[4];
    f = false;
    if (d <= 0) break;
    j++;
  }
  ans = max(ans, j);
  cout << ans << endl;
}
int main() {
  int t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

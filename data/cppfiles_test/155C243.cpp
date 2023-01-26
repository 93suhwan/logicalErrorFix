#include <bits/stdc++.h>
using namespace std;
int s[200005];
struct pp {
  int lev;
  int loc;
} s1[200005], s2[200005];
bool cmp(pp &a, pp &b) { return a.lev < b.lev; }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int s1h = 0, s2h = 0;
    string test;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> s[j];
    }
    cin >> test;
    for (int p = 0; p < test.length(); p++) {
      if (test[p] == '0')
        s1[s1h].lev = s[p], s1[s1h++].loc = p;
      else
        s2[s2h].lev = s[p], s2[s2h++].loc = p;
    }
    sort(s1, s1 + s1h, cmp);
    sort(s2, s2 + s2h, cmp);
    for (int j = 0; j < s1h; j++) {
      s[s1[j].loc] = j + 1;
    }
    for (int j = 0; j < s2h; j++) {
      s[s2[j].loc] = j + s1h + 1;
    }
    for (int j = 0; j < n; j++) cout << s[j] << " ";
    cout << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
  string s;
  map<char, int> cnt;
  bool operator<(const node& n1) const { return s < n1.s; }
} ns[N];
bool st[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      ns[i].cnt.clear();
      cin >> ns[i].s;
      sort(ns[i].s.begin(), ns[i].s.end());
      for (int j = 0; j < (int)ns[i].s.length(); j++) ns[i].cnt[ns[i].s[j]]++;
    }
    sort(ns, ns + n);
    int res = 0;
    for (char tmp = 'a'; tmp <= 'e'; tmp++) {
      int curc = 0, curno = 0;
      int ans = 0;
      memset(st, false, sizeof st);
      for (int j = 0; j < n; j++) {
        int left = ns[j].s.length() - ns[j].cnt[tmp];
        if ((curc + ns[j].cnt[tmp] > curno + left)) {
          ans++;
          st[j] = true;
          curc += ns[j].cnt[tmp];
          curno += left;
        }
      }
      if (curc > curno) {
        for (int j = 0; j < n; j++) {
          int left = ns[j].s.length() - ns[j].cnt[tmp];
          if (!st[j] && ns[j].cnt[tmp] == left) {
            ans++;
            st[j] = true;
          }
        }
        res = max(res, ans);
      }
    }
    cout << res << endl;
  }
  return 0;
}

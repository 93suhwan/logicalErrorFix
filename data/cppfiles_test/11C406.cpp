#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
  string s;
  int cnt[10];
} ns[N];
bool cmpa(const node &n1, const node &n2) { return n1.cnt[0] > n2.cnt[0]; }
bool cmpb(const node &n1, const node &n2) { return n1.cnt[1] > n2.cnt[1]; }
bool cmpc(const node &n1, const node &n2) { return n1.cnt[2] > n2.cnt[2]; }
bool cmpd(const node &n1, const node &n2) { return n1.cnt[3] > n2.cnt[3]; }
bool cmpe(const node &n1, const node &n2) { return n1.cnt[4] > n2.cnt[4]; }
bool st[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) ns[i].cnt[j] = 0;
    for (int i = 0; i < n; i++) {
      cin >> ns[i].s;
      for (int j = 0; j < (int)ns[i].s.length(); j++)
        ns[i].cnt[ns[i].s[j] - 'a']++;
      for (int j = 0; j < 5; j++) {
        int left = ns[i].s.length() - ns[i].cnt[j];
        ns[i].cnt[j] = ns[i].cnt[j] - left;
      }
    }
    int res = 0;
    int cnt = 0, ans = 0;
    sort(ns, ns + n, cmpa);
    for (int i = 0; i < n; i++) {
      ans += ns[i].cnt[0];
      if (ans <= 0) break;
      cnt++;
    }
    res = max(res, cnt);
    cnt = ans = 0;
    sort(ns, ns + n, cmpb);
    for (int i = 0; i < n; i++) {
      ans += ns[i].cnt[1];
      if (ans <= 0) break;
      cnt++;
    }
    res = max(res, cnt);
    cnt = ans = 0;
    sort(ns, ns + n, cmpc);
    for (int i = 0; i < n; i++) {
      ans += ns[i].cnt[2];
      if (ans <= 0) break;
      cnt++;
    }
    res = max(res, cnt);
    cnt = ans = 0;
    sort(ns, ns + n, cmpd);
    for (int i = 0; i < n; i++) {
      ans += ns[i].cnt[3];
      if (ans <= 0) break;
      cnt++;
    }
    res = max(res, cnt);
    ans = cnt = 0;
    sort(ns, ns + n, cmpe);
    for (int i = 0; i < n; i++) {
      ans += ns[i].cnt[4];
      if (ans <= 0) break;
      cnt++;
    }
    res = max(res, cnt);
    cout << res << endl;
  }
  return 0;
}

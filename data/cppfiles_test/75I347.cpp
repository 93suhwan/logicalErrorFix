#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  int len;
  int maxx;
} mp[100005];
bool cmp(node a, node b) {
  if (a.maxx != b.maxx)
    return a.maxx < b.maxx;
  else
    return a.id > b.id;
}
int n;
bool work(long long mid) {
  long long res = mid;
  for (int i = 1; i <= n; i++) {
    if (mp[i].id == 1) {
      if (res >= mp[i].maxx)
        res += mp[i].len;
      else
        return 0;
    } else {
      if (res + mp[i].id - 1 >= mp[i].maxx)
        res += mp[i].len;
      else
        return 0;
    }
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      int maxx = 0;
      int id = 0;
      for (int j = 1; j <= k; j++) {
        int a;
        cin >> a;
        if (j == 1) {
          maxx = a + 1;
          id = j;
        } else {
          if (a - j + 2 > maxx) {
            maxx = a;
            id = j;
          }
        }
      }
      mp[i] = {id, k, maxx};
    }
    sort(mp + 1, mp + 1 + n, cmp);
    long long l, r;
    l = 1;
    r = mp[n].maxx;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (work(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << endl;
  }
  return 0;
}

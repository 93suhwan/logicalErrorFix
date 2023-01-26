#include <bits/stdc++.h>
using namespace std;
struct mydata {
  int a, b, c, d, e, id;
};
bool comp(mydata one, mydata two) {
  int cnt1 = 0;
  if (one.a < two.a) cnt1++;
  if (one.b < two.b) cnt1++;
  if (one.c < two.c) cnt1++;
  if (one.d < two.d) cnt1++;
  if (one.e < two.e) cnt1++;
  if (cnt1 > 2) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<mydata> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d >> v[i].e;
      v[i].id = i + 1;
    }
    sort(v.begin(), v.end(), comp);
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    bool hai = true;
    for (int i = 1; i < n; i++) {
      if (comp(v[0], v[i]) == false) {
        hai = false;
        break;
      }
    }
    if (hai) {
      cout << v[0].id << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}

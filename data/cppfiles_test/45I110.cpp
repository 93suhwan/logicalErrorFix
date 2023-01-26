#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test_case() {
  int n;
  cin >> n;
  vector<int> o, e;
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 1)
      o.push_back(i);
    else
      e.push_back(i);
  }
  int _o = (int)o.size();
  int _e = (int)e.size();
  if (abs(_o - _e) > 1) {
    printf("-1\n");
    return;
  }
  ll m = 1e9;
  if (_o >= _e) {
    ll s = 0;
    int _i = 0;
    for (int i = (0); (1) > 0 ? i < (_o) : i > (_o); i += (1)) {
      s += abs(_i - o[i]);
      _i += 2;
    }
    m = min(m, s);
  }
  if (_e >= _o) {
    ll s = 0;
    int _i = 0;
    for (int i = (0); (1) > 0 ? i < (_e) : i > (_e); i += (1)) {
      s += abs(_i - e[i]);
      _i += 2;
    }
    m = min(m, s);
  }
  printf("%lld\n", m);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) test_case();
}

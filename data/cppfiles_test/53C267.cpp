#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
map<long long, long long> mp;
void refresh() {
  mp.clear();
  vec.clear();
}
long long ara[300005];
int main() {
  long long tc = 1;
  scanf("%lld", &tc);
  while (tc--) {
    refresh();
    long long n, k, i, j, ans = 0;
    scanf("%lld %lld", &n, &k);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &ara[i]);
      vec.push_back(ara[i]);
    }
    sort(vec.begin(), vec.end());
    for (i = 0; i < n; i++) {
      mp[vec[i]] = i;
    }
    for (i = 2; i <= n; i++) {
      if (mp[ara[i]] == mp[ara[i - 1]] + 1) {
      } else
        ans++;
    }
    ans++;
    if (ans <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

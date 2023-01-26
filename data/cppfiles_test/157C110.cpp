#include <bits/stdc++.h>
using namespace std;
long long int inf = 998244353;
long long int facto[1000010];
long long int power(long long int a, long long int pow) {
  long long int ans = 1;
  if (a < 0) a += inf;
  while (pow) {
    if (pow % 2 == 1) {
      ans = ((ans % inf) * (a % inf)) % inf;
    }
    a = ((a % inf) * (a % inf)) % inf;
    if (a < 0) a += inf;
    pow /= 2;
  }
  return ans;
}
void fact(int n) {
  long long int fac = 1;
  for (int i = 1; i <= n; i++) {
    fac = ((fac % inf) * (i % inf)) % inf;
    facto[i] = fac;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  facto[0] = 1;
  fact(6000);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') pos.push_back(i);
  }
  if (pos.size() < k) {
    cout << 1 << "\n";
    return 0;
  }
  if (k == 0) {
    cout << 1 << "\n";
    return 0;
  }
  int i = 0, j = k - 1, sz = pos.size();
  long long int ans = 0;
  while (j < sz) {
    if (j != sz - 1) {
      int szz;
      if (i)
        szz = pos[j + 1] - 1 - pos[i - 1];
      else
        szz = pos[j + 1] - 1 - min(pos[i], 0) + 1;
      long long int tot = facto[szz];
      tot = ((tot % inf) * (power(facto[k], inf - 2) % inf)) % inf;
      tot = ((tot % inf) * (power(facto[szz - k], inf - 2) % inf)) % inf;
      szz = pos[j + 1] - 1 - pos[i];
      long long int tot1 = facto[szz];
      tot1 = ((tot1 % inf) * (power(facto[k - 1], inf - 2) % inf)) % inf;
      tot1 = ((tot1 % inf) * (power(facto[szz - k + 1], inf - 2) % inf)) % inf;
      ans = (ans + tot - tot1) % inf;
    } else {
      int szz;
      if (i)
        szz = max(pos[j], n - 1) - pos[i - 1];
      else
        szz = max(pos[j], n - 1) - min(pos[i], 0) + 1;
      long long int tot = facto[szz];
      tot = ((tot % inf) * (power(facto[k], inf - 2) % inf)) % inf;
      tot = ((tot % inf) * (power(facto[szz - k], inf - 2) % inf)) % inf;
      ans = (ans + tot) % inf;
    }
    j += 1;
    i += 1;
  }
  cout << (ans + inf) % inf << "\n";
  return 0;
}

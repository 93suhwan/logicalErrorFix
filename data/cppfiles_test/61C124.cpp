#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
map<int, int> mp1, mp2;
pair<int, int> num[maxn];
long long int C(int n, int m) {
  long long int sum = 1;
  if (n <= m) return 1;
  for (long long int i = n, j = 1; j <= m; i--, j++) {
    sum = sum * i;
    sum = sum / j;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> num[i].first >> num[i].second;
      mp1[num[i].first]++;
      mp2[num[i].second]++;
    }
    long long int ans = C(n, 3);
    for (int i = 1; i <= n; i++)
      ans -= (mp1[num[i].first] - 1ll) * (mp2[num[i].second] - 1ll);
    cout << ans << "\n";
    ;
    mp1.clear();
    mp2.clear();
  }
  return 0;
}

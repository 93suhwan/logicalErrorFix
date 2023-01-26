#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long n;
  cin >> n;
  unsigned long long a[n];
  map<int, int> mp;
  unsigned long long sum = 0;
  unsigned long long mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    sum += a[i];
    mx = max(mx, a[i]);
  }
  unsigned long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    unsigned long long answer = 0;
    unsigned long long ck = sum, ck2 = sum;
    unsigned long long x, y;
    cin >> x >> y;
    if (mp.lower_bound(x) != mp.end()) {
      ck -= (mp.lower_bound(x)->first);
      if (y > ck) answer += y - ck;
      unsigned long long ans2 = 0;
      if (mp.lower_bound(x) != mp.begin()) {
        ans2 += x - (prev(mp.lower_bound(x))->first);
        ck2 -= (prev(mp.lower_bound(x))->first);
        if (y > ck2) ans2 += y - ck2;
        answer = min(answer, ans2);
      }
    } else {
      ck -= mx;
      answer += x - mx;
      if (y > ck) answer += y - ck;
    }
    cout << answer << "\n";
  }
  return 0;
}

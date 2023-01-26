#include <bits/stdc++.h>
using namespace std;
vector<long long> solveoddarray(vector<long long>& a, long long start,
                                long long end) {
  vector<long long> ans;
  for (long long i = start; i <= end - 2; i += 2) {
    ans.push_back(i + 1);
  }
  for (long long i = end - 4; i >= 0; i -= 2) {
    ans.push_back(i + 1);
  }
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    scanf("%lld", &n);
    vector<long long> a(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    bool possible = true;
    vector<long long> ans;
    if (sum % 2 == 0) {
      if (n % 2 == 1) {
        ans = solveoddarray(a, 0, n - 1);
      } else {
        if (a[0] == 0 || a[n - 1] == 0) {
          if (a[0] == 0) {
            ans = solveoddarray(a, 1, n - 1);
          } else {
            ans = solveoddarray(a, 0, n - 2);
          }
        } else {
          possible = false;
        }
      }
    } else {
      possible = false;
    }
    if (!possible) {
      printf("NO\n");
    } else {
      printf("YES\n");
      printf("%lld\n", (long long)ans.size());
      if ((long long)ans.size() > 0) {
        for (long long i = 0; i < (long long)ans.size(); i++) {
          printf("%lld ", ans[i]);
        }
        printf("\n");
      }
    }
  }
}

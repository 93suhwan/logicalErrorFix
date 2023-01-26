#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long n = 7;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long long> ans(3);
  ans[0] = v[0];
  long long target = v[6] - v[0];
  long long i = 1;
  long long j = 5;
  while (i < j) {
    if (v[i] + v[j] < target) {
      i++;
    } else if (v[i] + v[j] > target) {
      j--;
    } else if (v[i] + v[j] == target) {
      ans[1] = v[i];
      ans[2] = v[j];
      break;
    }
  }
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << "\n";
}
void fxn() {}
void funtion() {}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    fun();
  }
  return 0;
}

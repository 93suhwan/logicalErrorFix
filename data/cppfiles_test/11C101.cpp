#include <bits/stdc++.h>
using namespace std;
template <class T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
long long n;
long long const N = 2 * 1e5 + 2;
vector<long long> temp;
vector<vector<long long>> count1(N, vector<long long>(7, 0));
long long checkforbest() {
  long long count = 0;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    sum += temp[i - 1];
    if (sum > 0)
      ++count;
    else
      break;
  }
  return count;
}
void solve() {
  cin >> n;
  count1.clear();
  count1.resize(n + 1, vector<long long>(7, 0));
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long len = s.size();
    for (long long j = 0; j < len; j++) {
      count1[i + 1][(s[j] - 'a') + 1] += 1;
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    sum = 0;
    for (long long j = 1; j <= 5; j++) {
      sum += count1[i][j];
    }
    count1[i][6] = sum;
  }
  long long ans = 0;
  for (long long i = 1; i <= 5; i++) {
    temp.clear();
    for (long long j = 1; j <= n; j++) {
      temp.push_back(2 * count1[j][i] - count1[j][6]);
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    ans = max(ans, checkforbest());
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void start() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void debug(vector<char> vec) {
  long long n = vec.size();
  for (long long i = 0; i < (long long)n; i++) cout << vec[i];
  cout << endl;
  return;
}
long long power(long long a, long long b, long long P = 1000000007) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  long long count1 = 0, count2 = 0;
  vector<long long> ones;
  for (long long i = 0; i < (long long)n; i++) {
    if (str[i] == '2') {
      ones.push_back(i);
      count2++;
    } else
      count1++;
  }
  if (count2 <= 2) {
    cout << "NO" << endl;
    return;
  }
  vector<vector<char>> vec(n, vector<char>(n, '='));
  for (long long i = 0; i < (long long)n; i++) vec[i][i] = 'X';
  for (long long i = 0; i < (long long)ones.size(); i++) {
    vec[ones[i]][ones[(i + 1) % ones.size()]] = '+';
    vec[ones[(i + 1) % ones.size()]][ones[i]] = '-';
  }
  cout << "YES" << endl;
  for (long long i = 0; i < (long long)n; i++) debug(vec[i]);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

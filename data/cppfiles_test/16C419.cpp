#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  s2 = s1;
  sort(s1.begin(), s1.end());
  long long cnt = 0;
  for (long long i = 0; i < s1.size(); i++)
    if (s1[i] != s2[i]) cnt++;
  cout << cnt << endl;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) test_case();
}

#include <bits/stdc++.h>
using namespace std;
struct trp {
  int x, y, z;
};
void fun() {}
void q2() {
  string s;
  cin >> s;
  long long int ans = 0;
  long long int c = 0;
  unordered_map<char, long long int> m;
  for (auto it : s) m[it]++;
  for (auto it : m) {
    if (it.second >= 2)
      ans++;
    else
      c++;
  }
  cout << ans + (c / 2) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    q2();
  }
}

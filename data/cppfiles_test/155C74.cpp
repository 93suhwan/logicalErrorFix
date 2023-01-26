#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;
long long tt, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for (int sb = 1; sb <= tt; sb++) {
    bitset<200009> vis;
    cin >> n;
    long long su = 0, cnt = 0;
    vector<int> v(n), j(n), aa, pos(n + 1), bb;
    for (auto &it : v) cin >> it;
    string s;
    cin >> s;
    for (int i = 0; i <= n - 1; i++) j[i] = s[i] - '0', su += j[i];
    long long mi = n - su;
    for (auto it : v) {
      if (it <= mi && j[cnt]) {
        aa.push_back(it);
      } else if (it > mi && j[cnt])
        pos[it] = it;
      else if (it <= mi && !j[cnt])
        pos[it] = it;
      else
        bb.push_back(it);
      cnt += 1;
    }
    cnt = n;
    for (auto it : aa) {
      while (pos[cnt] == cnt) {
        cnt -= 1;
      }
      pos[it] = cnt;
      cnt -= 1;
    }
    for (auto it : bb) {
      while (pos[cnt] == cnt) {
        cnt -= 1;
      }
      pos[it] = cnt;
      cnt -= 1;
    }
    for (int i = 0; i <= n - 1; i++)
      cout << pos[v[i]] << (i == n - 1 ? "\n" : " ");
  }
  return 0;
}

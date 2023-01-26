#include <bits/stdc++.h>
using namespace std;
int T, n;
vector<long long> sticks;
bool ans;
void init() {
  long long tmp1, tmp2, tmp3;
  cin >> tmp1 >> tmp2 >> tmp3;
  ans = false;
  sticks.clear();
  sticks.push_back(tmp1);
  sticks.push_back(tmp2);
  sticks.push_back(tmp3);
  sort(sticks.begin(), sticks.end());
}
void sol() {
  if (sticks[2] == sticks[0] + sticks[1]) ans = true;
  if (sticks[0] == sticks[1] && sticks[2] % 2 == 0) ans = true;
  if (sticks[0] % 2 == 0 && sticks[1] == sticks[2]) ans = true;
  cout << (ans ? "YES" : "NO") << endl;
}
int main() {
  cin >> T;
  while (T--) {
    init();
    sol();
  }
  return 0;
}

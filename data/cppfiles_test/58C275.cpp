#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
bool Check() {
  int N;
  cin >> N;
  string s1, s2;
  cin >> s1 >> s2;
  if (s2[N - 1] == '1') return false;
  for (int i = 0; i < N; i++)
    if (s1[i] == '1' && s2[i] == '1') return false;
  return true;
}
void Solve() { cout << (Check() ? "YES" : "NO") << '\n'; }
int main() {
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}

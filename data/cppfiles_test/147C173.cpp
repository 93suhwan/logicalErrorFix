#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
void openFiles() {}
void solveA() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
      if (c == 'N') cnt++;
    }
    if (cnt != 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  openFiles();
  solveA();
}

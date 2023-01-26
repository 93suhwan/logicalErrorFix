#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
bool check(int x) {
  if (x % 3 == 0) return false;
  while (x--) {
    if (x % 10 == 3) return false;
  }
  return true;
}
int main() {
  fast();
  int t;
  cin >> t;
  vector<int> v;
  int i = 1;
  while (i <= 1000) {
    if (check(i) == true) {
      v.push_back(i);
      i++;
    } else
      i++;
  }
  for (auto i : v) cout << i;
  return 0;
}

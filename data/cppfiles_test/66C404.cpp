#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
bool check(int x) {
  if (x % 3 == 0) {
    return false;
  }
  if (x % 10 == 3) {
    return false;
  }
  return true;
}
int main() {
  fast();
  int t;
  cin >> t;
  vector<int> v{};
  for (int i = 1; i <= 1800; i++) {
    if (check(i) == true) v.push_back(i);
  }
  while (t--) {
    int x;
    cin >> x;
    cout << v[x - 1] << "\n";
  }
  return 0;
}

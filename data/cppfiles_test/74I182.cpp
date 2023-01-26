#include <bits/stdc++.h>
using namespace std;
void solve() {
  int al, bob;
  cin >> al >> bob;
  int n = al + bob;
  int apna;
  if (n % 2 == 0)
    apna = n / 2;
  else
    apna = n / 2 + 1;
  int dusre = n - apna;
  vector<int> v;
  for (int i = 0; i <= apna && i <= al; i++) {
    if (dusre >= al - i) v.push_back(apna - i + al - i);
  }
  swap(apna, dusre);
  for (int i = 0; i <= apna && i <= al; i++) {
    if (dusre >= al - i) v.push_back(apna - i + al - i);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < v.size() - 1; i++) {
    if (v[i] == v[i + 1] || v[i] == v[i - 1]) {
      v.erase(v.begin() + i);
      i--;
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

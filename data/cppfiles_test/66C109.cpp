#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void SMG() {
  for (int i = 0; i <= 100000; i++)
    if (i % 3 != 0 and i % 10 != 3) v.push_back(i);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << v[k - 1] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  SMG();
  return 0;
}

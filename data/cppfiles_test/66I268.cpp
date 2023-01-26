#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void init() {
  for (int i = 1; i <= 1666; ++i) {
    if (i % 3 && i % 10 != 3) v.push_back(i);
  }
  cout << v.size() << endl;
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  int k;
  while (t--) {
    cin >> k;
    cout << v[k - 1] << "\n";
  }
  return 0;
}

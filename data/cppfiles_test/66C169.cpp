#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void preprocess() {
  for (int i = 1; i <= 1e6; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    v.push_back(i);
  }
}
int main() {
  preprocess();
  long long int t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    cout << v[k - 1];
    cout << "\n";
  }
}

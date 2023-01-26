#include <bits/stdc++.h>
using namespace std;
vector<int> X;
bool func(int x) {
  if (x % 3 == 0 || x % 10 == 3) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; X.size() <= 1000; i++)
    if (func(i)) X.push_back(i);
  while (t--) {
    int n;
    cin >> n;
    cout << X[n - 1] << "\n";
  }
  return 0;
}

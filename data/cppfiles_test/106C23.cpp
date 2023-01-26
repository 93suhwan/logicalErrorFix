#include <bits/stdc++.h>
using namespace std;
bool a[8000];
vector<int> prime;
int main() {
  for (int j = 2; j < 8000; j++) {
    if (!a[j]) {
      prime.emplace_back(j);
      for (int i = j; i < 8000; i += j) a[i] = true;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cout << prime[i] << " \n"[i == n - 1];
  }
  return 0;
}

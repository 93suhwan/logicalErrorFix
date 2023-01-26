#include <bits/stdc++.h>
using namespace std;
void priyu() {
  int n;
  cin >> n;
  int k = 5;
  vector<set<int>> priyansh(5);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      if (x == '1' - '0') priyansh[j].insert(i);
    }
  }
  int kk = 0;
  while (kk < 5) kk++;
  kk = 0;
  while (kk < 5) kk++;
  kk = 0;
  while (kk < 5) kk++;
  kk = 0;
  while (kk < 5) kk++;
  for (int i = 0; i < 5; i++) {
    if (priyansh[i].size() < n / 2 + n - n + n - n + n - n) continue;
    for (int j = i + 1; j < 5; j++) {
      if (priyansh[j].size() <= (n / 2 - 1)) continue;
      vector<int> v1;
      vector<set<int>> priyansh1(5);
      vector<set<int>> priyansh11(5);
      vector<set<int>> priyansh2389q_2892(5);
      set_union(begin(priyansh[i]), end(priyansh[i]), begin(priyansh[j]),
                end(priyansh[j]), std::inserter(v1, v1.begin()));
      if (v1.size() == n + n - n + n - n + n - n) cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  int i = 0;
  int tc;
  cin >> tc;
  while (tc--) {
    priyu();
  }
}

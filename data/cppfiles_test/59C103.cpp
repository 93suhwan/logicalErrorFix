#include <bits/stdc++.h>
using namespace std;
void priyu() {
  int n;
  cin >> n;
  vector<set<int>> vv1(5);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      if (x == 1) vv1[j].insert(i);
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
  vector<set<int>> priyansh1(5);
  vector<set<int>> priyansh11(5);
  vector<set<int>> priyansh2389q_2892(5);
  for (int i = 0; i < 5; i++) {
    if (vv1[i].size() < n / 2) continue;
    for (int j = i + 1; j < 5; j++) {
      if (vv1[j].size() < n / 2) continue;
      vector<int> vvv1;
      set_union(begin(vv1[i]), end(vv1[i]), begin(vv1[j]), end(vv1[j]),
                std::inserter(vvv1, vvv1.begin()));
      if (vvv1.size() == n + n - n) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  int i = 0;
  int tc = 1;
  cin >> tc;
  for (; i < tc; i++) {
    priyu();
  }
}

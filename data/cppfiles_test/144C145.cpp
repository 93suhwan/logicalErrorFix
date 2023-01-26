#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
void processor() {
  int n, m, k;
  cin >> n >> m >> k;
  set<pair<int, int>> elements;
  for (int i = 1; i <= n; i++) {
    elements.insert({0, i});
  }
  int required = n % m * (n / m + 1);
  for (int i = 0; i < k; i++) {
    int req = required, oth = n - req;
    set<pair<int, int>> other;
    for (auto p : elements) {
      if (req && p.first % 2 == 0) {
        other.insert({p.first + 1, p.second});
        req--;
      } else if (oth && p.first % 2 == 1) {
        other.insert({p.first + 1, p.second});
        oth--;
      } else
        other.insert({p.first, p.second});
    }
    elements = other;
    vector<int> bigs, smalls;
    for (auto p : elements) {
      if (p.first % 2) {
        bigs.push_back(p.second);
      } else
        smalls.push_back(p.second);
    }
    if (bigs.size()) {
      cout << n / m + 1 << " ";
    }
    for (int i = 0; i < bigs.size(); i++) {
      cout << bigs[i] << " ";
      if ((i + 1) % (n / m + 1) == 0 && i + 1 != bigs.size())
        cout << endl << n / m + 1 << " ";
      else if ((i + 1) % (n / m + 1) == 0)
        cout << endl;
    }
    if (smalls.size()) {
      cout << n / m << " ";
    }
    for (int i = 0; i < smalls.size(); i++) {
      cout << smalls[i] << " ";
      if ((i + 1) % (n / m) == 0 && i + 1 != smalls.size())
        cout << endl << n / m << " ";
      else if ((i + 1) % (n / m) == 0)
        cout << endl;
    }
  }
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int count, counter = 0;
  cin >> count;
  while (counter++ < count) {
    processor();
  }
  return 0;
}

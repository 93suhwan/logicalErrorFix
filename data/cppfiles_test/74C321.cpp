#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int total = a + b;
  int aServes = total / 2;
  if (total % 2 == 0) {
    int aServes = total / 2;
    set<int> Ks;
    int aWinsServes = a;
    int k = aServes - aWinsServes;
    Ks.insert(k);
    while (aWinsServes--) {
      k += 2;
      Ks.insert(k);
    }
    cout << Ks.size() << endl;
    for (auto i : Ks) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    int aServes = total / 2;
    set<int> Ks;
    int aWinsServes = a;
    int k = aServes - aWinsServes;
    Ks.insert(k);
    while (aWinsServes--) {
      k += 2;
      Ks.insert(k);
    }
    aServes = total / 2 + 1;
    aWinsServes = a;
    k = aServes - aWinsServes;
    Ks.insert(k);
    while (aWinsServes--) {
      k += 2;
      Ks.insert(k);
    }
    cout << Ks.size() << endl;
    for (auto i : Ks) {
      cout << i << " ";
    }
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

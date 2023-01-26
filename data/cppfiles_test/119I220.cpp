#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test;
  cin >> test;
  while (test--) {
    long long int name;
    cin >> name;
    long long int chodna[name];
    for (int i = 0; i < name; i++) {
      cin >> chodna[i];
    }
    sort(chodna, chodna + name);
    long long int mx = 0, m = chodna[name - 1], p;
    for (int i = 0; i < name / 2; i++) {
      p = chodna[i] + chodna[name - i - 1];
      m = min(p / 2, m);
      mx = max(p / 2 + p % 2, mx);
    }
    if (name % 2) {
      p = chodna[name / 2] + chodna[name / 2 + 1];
      m = min(p / 2, m);
      mx = max(p / 2 + p % 2, mx);
    }
    cout << mx - m << endl;
  }
  return 0;
}

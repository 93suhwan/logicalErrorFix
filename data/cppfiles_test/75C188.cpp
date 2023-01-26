#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int m = 0; m < t; m++) {
    int n;
    cin >> n;
    pair<int, int> tab[n + 1];
    int k, a;
    for (int i = 0; i < n; i++) {
      cin >> k;
      int mini = 0, armor = 0;
      for (int j = 0; j < k; j++) {
        cin >> a;
        if (armor <= a) {
          mini = a - j + 1;
          armor = a + 1;
        }
        armor++;
      }
      tab[i].first = mini;
      tab[i].second = k;
    }
    sort(tab, tab + n);
    int mini = 0, armor = 0, suma = 0;
    for (int i = 0; i < n; i++) {
      if (armor <= tab[i].first) {
        mini = tab[i].first - suma;
        armor = tab[i].first;
      }
      armor += tab[i].second;
      suma += tab[i].second;
    }
    cout << mini << '\n';
  }
}

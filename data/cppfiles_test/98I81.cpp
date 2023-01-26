#include <bits/stdc++.h>
using namespace std;
void functie(int n) {
  string tastatura, cuvant;
  while (n) {
    vector<int> v;
    int cost = 0;
    cin >> tastatura >> cuvant;
    for (int i = 0; i < cuvant.size(); i++) {
      for (int j = 0; j < tastatura.size(); j++)
        if (cuvant[i] == tastatura[j]) v.push_back(j);
    }
    for (int i = 1; i < v.size(); i++) cost += abs(v[i] - v[i - 1]);
    cout << cost;
    n--;
  }
}
int main() {
  int n;
  cin >> n;
  functie(n);
  return 0;
}

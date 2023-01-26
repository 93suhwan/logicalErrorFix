#include <bits/stdc++.h>
using namespace std;
const int stala = 5e5 + 10;
long long res = 0;
int ojciec[stala];
int prz[stala];
int prz2[stala];
long long wynik[stala];
int ile_dobrych[stala];
long long pref[stala];
vector<pair<long long, int> > wektor;
map<long long, vector<int> > mapka_zapytania;
set<long long> secik;
map<long long, vector<int> > mapka;
long long tab[stala];
int Find(int x) {
  if (ojciec[x] != x) {
    ojciec[x] = Find(ojciec[x]);
  }
  return ojciec[x];
}
void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a != b) {
    long long stary_wynik = wynik[a] + wynik[b];
    ojciec[b] = a;
    prz2[a] = prz2[b];
    ile_dobrych[a] += ile_dobrych[b];
    wynik[a] = pref[prz2[a]] - pref[prz2[a] - ile_dobrych[a]];
    res += (wynik[a] - stary_wynik);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ile, ile2, zap;
  cin >> ile >> ile2 >> zap;
  for (int i = 1; i <= ile; i++) {
    long long a;
    cin >> a;
    res += a;
    wektor.push_back(make_pair(a, 0));
  }
  for (int i = 1; i <= ile2; i++) {
    long long a;
    cin >> a;
    wektor.push_back(make_pair(a, 1));
  }
  sort(wektor.begin(), wektor.end());
  for (int i = 1; i <= zap; i++) {
    long long a;
    cin >> a;
    secik.insert(a);
    mapka_zapytania[a].push_back(i);
  }
  for (int i = 0; i < (int)wektor.size(); i++) {
    pref[i + 1] = wektor[i].first + pref[i];
    if (i != (int)wektor.size() - 1) {
      secik.insert(wektor[i + 1].first - wektor[i].first);
      mapka[wektor[i + 1].first - wektor[i].first].push_back(i + 1);
    }
    ojciec[i + 1] = i + 1;
    prz[i + 1] = i + 1;
    prz2[i + 1] = i + 1;
    if (wektor[i].second == 0) {
      ile_dobrych[i + 1] = 1;
      wynik[i + 1] = wektor[i].first;
    }
  }
  while (!secik.empty()) {
    long long index = *(secik.begin());
    secik.erase(secik.begin());
    for (int i = 0; i < (int)mapka[index].size(); i++) {
      int zmienna = mapka[index][i];
      Union(zmienna, zmienna + 1);
    }
    for (int i = 0; i < (int)mapka_zapytania[index].size(); i++) {
      int zmienna = mapka_zapytania[index][i];
      tab[zmienna] = res;
    }
  }
  for (int i = 1; i <= zap; i++) {
    cout << tab[i] << "\n";
  }
  return 0;
}

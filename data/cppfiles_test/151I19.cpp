#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 99;
int fu[2 * N];
map<int, int> mapa;
map<int, int> rmapa;
void dodaj(int i) {
  int x;
  cin >> x;
  if (mapa[x] == 0 || fu[mapa[x]] != x) {
    mapa[x] = N + i;
    fu[N + i] = x;
  }
  fu[i] = mapa[x];
}
void zamien() {
  int x, y;
  cin >> x >> y;
  if (x == y) return;
  if (fu[mapa[x]] == x) {
    if (fu[mapa[y]] == y)
      fu[mapa[x]] = mapa[y];
    else
      fu[mapa[x]] = y;
  }
}
int findd(int i) {
  if (fu[i] < N) return fu[i];
  fu[i] = findd(fu[i]);
  return fu[i];
}
int main() {
  int K = 0;
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      dodaj(K);
      K++;
    }
    if (a == 2) zamien();
  }
  for (int i = 0; i < K; i++) {
    cout << findd(i) << " ";
  }
  cout << "\n";
}

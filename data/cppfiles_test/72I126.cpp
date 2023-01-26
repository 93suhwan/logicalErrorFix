#include <bits/stdc++.h>
using namespace std;
const int MLD = 1000 * 1000 * 1000;
ostream& operator<<(ostream& os, pair<int, int> pkt) {
  os << pkt.first << ' ' << pkt.second;
  return os;
}
pair<int, int> rot90(pair<int, int> pkt) { return {pkt.second, -pkt.first}; }
pair<int, int> flip(pair<int, int> pkt, int ile) {
  if (ile < 0) return flip(pkt, 4 - ile);
  for (int i = 0; i < ile; i++) {
    pkt = rot90(pkt);
    pkt.first += MLD;
    pkt.second += MLD;
  }
  return pkt;
}
int ask(pair<int, int> poz, int ile) {
  poz = flip(poz, -ile);
  cout << "? " << poz << endl;
  int ret;
  cin >> ret;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> odl_od_scjany;
  for (int i = 0; i < 4; i++) {
    int a = ask({1, 1}, i);
    int b = ask({1, MLD}, i);
    pair<int, int> dol = {a, 1};
    pair<int, int> gora = {b, MLD};
    int diff = abs(a - b);
    if (a > b)
      dol.first -= diff, dol.second += diff;
    else
      gora.first -= diff, gora.first -= diff;
    diff = gora.second - dol.second;
    dol.first -= diff / 2, dol.second += diff / 2;
    if (dol.first < 1) dol.first = 1;
    odl_od_scjany.push_back(ask(dol, i) + dol.first);
  }
  cout << "! " << odl_od_scjany[0] << ' ' << odl_od_scjany[1] << ' '
       << MLD + 1 - odl_od_scjany[2] << ' ' << MLD + 1 - odl_od_scjany[3]
       << '\n';
}

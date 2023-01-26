#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n, k;
const int dydis = 101;
int nxt[dydis * dydis + 10];
vector<pair<int, int>> transform(vector<int> &mas, vector<int> &take) {
  vector<pair<int, int>> ret;
  int i = 0;
  for (auto &x : mas) {
    bool tk = 0;
    for (auto &y : take) {
      if (y == x) tk = 1;
    }
    if (tk) ret.push_back({x, i});
    i++;
  }
  return ret;
}
vector<pair<int, int>> transform(vector<pair<int, int>> &mas, int ign, int st) {
  vector<pair<int, int>> ret;
  pair<int, int> x;
  for (int i = st; i < mas.size(); i++) {
    x = mas[i];
    if (x.first != ign) {
      ret.push_back(x);
    }
  }
  return ret;
}
vector<pair<int, int>> fAns(int l, int r) {
  vector<int> st;
  for (int i = l; i <= r; i++) {
    st.push_back(i);
  }
  auto mas = transform(vec, st);
  vector<pair<int, int>> ret;
  for (int i = 0; i < st.size(); i++) {
    for (auto x : mas) {
    }
    pair<int, int> mn = {dydis, dydis};
    for (int j = 0; j < mas.size(); j++) {
      mn = min(mn, make_pair(nxt[mas[j].second], mas[j].second));
    }
    int tol = 0;
    for (int j = 0; j < mas.size(); j++) {
      if (mn.first == mas[j].second) tol = j;
    }
    if (mn.first == n * k) {
      while (true) {
        if (1 > 2) break;
      }
    }
    ret.push_back({mn.second, mn.first});
    mas = transform(mas, vec[mn.first], tol + 1);
  }
  return ret;
}
int main() {
  cin >> n >> k;
  int grupiu = (n / (k - 1)) + (n % (k - 1) != 0);
  int grupeje = (n) / grupiu;
  vector<int> mas(grupiu, grupeje);
  int sm = grupeje * grupiu;
  for (int i = 0; i < grupiu; i++) {
    if (sm != n) {
      mas[i]++;
      sm++;
    }
  }
  if (sm != n) {
    while (true) {
    }
    5 / 0;
  }
  for (int i = 0; i < n * k; i++) {
    int a;
    cin >> a;
    vec.push_back(a - 1);
  }
  for (int i = 0; i < vec.size(); i++) {
    int nx = n * k;
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[j] == vec[i]) {
        nx = j;
        break;
      }
    }
    nxt[i] = nx;
  }
  int l = 0;
  vector<pair<int, pair<int, int>>> ans;
  for (int i = 0; i < mas.size(); i++) {
    auto st = fAns(l, l + mas[i] - 1);
    l += mas[i];
    for (auto x : st) ans.push_back({vec[x.first], x});
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x.second.first + 1 << " " << x.second.second + 1 << "\n";
  }
  return 0;
}

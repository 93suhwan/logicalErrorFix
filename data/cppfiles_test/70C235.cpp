#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
map<char, int> n_occ;
map<char, int> last_occ;
bool cmp(pair<char, int> &a, pair<char, int> &b) { return a.second < b.second; }
vector<pair<char, int>> sort(map<char, int> &M) {
  vector<pair<char, int>> A;
  for (auto &it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
  return A;
}
int main() {
  int t;
  ull r, c, k;
  string text;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> text;
    n_occ.clear();
    last_occ.clear();
    for (int i = 0; i < text.length(); i++) {
      if (n_occ.find(text[i]) == n_occ.end()) {
        n_occ[text[i]] = 0;
      }
      n_occ[text[i]]++;
      last_occ[text[i]] = i;
    }
    vector<pair<char, int>> s_n_occ = sort(n_occ);
    vector<pair<char, int>> s_last_occ = sort(last_occ);
    int distinct = n_occ.size();
    int j = 1;
    int s = 0;
    bool posible = true;
    for (auto &it : s_last_occ) {
      it.second = j++;
      s += n_occ[it.first] / it.second;
      if (n_occ[it.first] % it.second != 0) posible = false;
    }
    if (!posible) {
      cout << -1 << endl;
      continue;
    }
    string reuslt = "";
    for (int j = 0; j < s; j++) {
      reuslt += text[j];
    }
    string test = reuslt;
    int idx = 0;
    auto it = s_last_occ.begin();
    posible = true;
    while (test != "") {
      if (text.substr(idx, test.size()) != test) {
        posible = false;
        break;
      }
      idx += test.size();
      test.erase(std::remove(test.begin(), test.end(), it->first), test.end());
      it++;
    }
    if (!posible) {
      cout << -1 << endl;
      continue;
    }
    cout << reuslt;
    cout << " ";
    for (auto el : s_last_occ) {
      cout << el.first;
    }
    cout << endl;
  }
}

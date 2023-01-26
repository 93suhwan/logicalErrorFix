#include <bits/stdc++.h>
using namespace std;
class player {
 public:
  int index;
  int s1;
  int s2;
};
bool cmp1(player a, player b) {
  if (a.s1 != b.s1)
    return a.s1 < b.s1;
  else
    return a.index < b.index;
}
bool cmp2(player a, player b) {
  if (a.s2 != b.s2)
    return a.s2 < b.s2;
  else
    return a.index < b.index;
}
int main() {
  set<player, decltype(cmp1)*> set1(cmp1);
  set<player, decltype(cmp2)*> set2(cmp2);
  int t, word, n, j;
  string input;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    while (getchar() != '\n')
      ;
    player* arr = new player[n];
    getline(cin, input);
    stringstream ss1(input);
    j = 0;
    while (ss1 >> word) arr[j].index = j, arr[j++].s1 = word;
    getline(cin, input);
    stringstream ss2(input);
    j = 0;
    while (ss2 >> word) arr[j++].s2 = word;
    for (int i = 0; i < n; i++) set1.insert(arr[i]), set2.insert(arr[i]);
    if ((*set1.rbegin()).index == (*set2.rbegin()).index) {
      for (int i = 0; i < n; i++) cout << ((*set1.rbegin()).index == i) ? 1 : 0;
      cout << '\n';
    } else {
      int* ans = new int[n];
      for (int i = 0; i < n; i++) ans[i] = 0;
      int minX = (*set2.rbegin()).s1;
      int minY = (*set1.rbegin()).s2;
      ans[(*set1.rbegin()).index] = 1;
      ans[(*set2.rbegin()).index] = 1;
      player erase1, erase2, current;
      erase1 = *set1.rbegin();
      erase2 = *set2.rbegin();
      set1.erase(erase1);
      set2.erase(erase1);
      set1.erase(erase2);
      set2.erase(erase2);
      int band = 1;
      while (band) {
        if (set1.empty() || set2.empty())
          band = 0;
        else {
          current = *set1.rbegin();
          if (current.s1 > minX) {
            ans[current.index] = 1;
            set1.erase(current);
            set2.erase(current);
            if (current.s2 < minY) minY = current.s2;
          } else {
            current = *set2.rbegin();
            if (current.s2 > minY) {
              ans[current.index] = 1;
              set1.erase(current);
              set2.erase(current);
              if (current.s1 < minX) minX = current.s1;
            } else
              band = 0;
          }
        }
      }
      for (int i = 0; i < n; i++) cout << ans[i];
      cout << '\n';
      delete[] ans;
    }
    delete[] arr;
    set1.clear();
    set2.clear();
  }
  return 0;
}

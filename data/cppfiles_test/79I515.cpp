#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
void run() {
  mp["1"] = 1;
  mp["4"] = 1;
  mp["6"] = 1;
  mp["8"] = 1;
  mp["9"] = 1;
  mp["22"] = 1;
  mp["25"] = 1;
  mp["27"] = 1;
  mp["32"] = 1;
  mp["33"] = 1;
  mp["35"] = 1;
  mp["52"] = 1;
  mp["55"] = 1;
  mp["72"] = 1;
  mp["75"] = 1;
  mp["77"] = 1;
  return;
}
void find(int l, string A) {
  if (l == 1) {
    cout << l << "\n";
    cout << A << "\n";
    return;
  }
  for (int i = 0; i < l; i++) {
    string tmp;
    tmp += A[i];
    if (mp.find(tmp) != mp.end()) {
      cout << 1 << "\n";
      cout << A[i] << "\n";
      return;
    }
  }
  for (int i = 0; i < l; i++) {
    for (int j = i + 1; j < l; j++) {
      string tmp2;
      tmp2 += A[i];
      tmp2 += +A[j];
      if (mp.find(tmp2) != mp.end()) {
        cout << 2 << "\n";
        cout << tmp2 << "\n";
        return;
      }
    }
  }
}
int main() {
  mp.clear();
  run();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l;
    string n;
    cin >> l;
    cin >> n;
    find(l, n);
  }
  return 0;
}

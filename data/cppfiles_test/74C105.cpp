#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    vector<int> vec;
    if (n % 2 == 0) {
      int agames = n / 2;
      int bgames = n / 2;
      if (a > agames) {
        int ac = agames;
        int bc = a - agames;
        int k = bc;
        vec.push_back(k);
        for (int i = 1; i <= (bgames - bc); i++) {
          k += 2;
          vec.push_back(k);
        }
      } else {
        int ac = a;
        int bc = 0;
        int k = agames - ac;
        vec.push_back(k);
        for (int i = 1; i <= ac; i++) {
          k += 2;
          vec.push_back(k);
        }
      }
    } else {
      int agames = (n / 2) + 1;
      int bgames = n / 2;
      if (a > agames) {
        int ac = agames;
        int bc = a - agames;
        int k = bc;
        vec.push_back(k);
        for (int i = 1; i <= (bgames - bc); i++) {
          k += 2;
          vec.push_back(k);
        }
      } else {
        int ac = a;
        int bc = 0;
        int k = agames - ac;
        vec.push_back(k);
        for (int i = 0; i < min(bgames, ac); i++) {
          k += 2;
          vec.push_back(k);
        }
      }
      agames = (n / 2);
      bgames = (n / 2) + 1;
      if (a > agames) {
        int ac = agames;
        int bc = a - agames;
        int k = bc;
        vec.push_back(k);
        for (int i = 1; i <= (bgames - bc); i++) {
          k += 2;
          vec.push_back(k);
        }
      } else {
        int ac = a;
        int bc = 0;
        int k = agames - ac;
        vec.push_back(k);
        for (int i = 0; i < min(bgames, ac); i++) {
          k += 2;
          vec.push_back(k);
        }
      }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
  }
  return 0;
}

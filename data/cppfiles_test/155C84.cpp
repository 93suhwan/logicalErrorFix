#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tests;
  cin >> tests;
  while (tests--) {
    long long n;
    cin >> n;
    long long p[n], invq[n + 1];
    for (int i = 0; i < n; i++) cin >> p[i];
    string s;
    cin >> s;
    long long liked[n], disliked[n], iliked = 0, idisliked = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        disliked[idisliked] = p[i];
        idisliked++;
      } else {
        liked[iliked] = p[i];
        iliked++;
      }
    }
    std::sort(liked, liked + iliked);
    std::sort(disliked, disliked + idisliked);
    for (int i = 0; i < idisliked; i++) {
      invq[disliked[i]] = i + 1;
    }
    for (int i = 0; i < iliked; i++) {
      invq[liked[i]] = i + idisliked + 1;
    }
    for (int i = 0; i < n; i++) {
      cout << invq[p[i]] << " ";
    }
    cout << endl;
  }
}

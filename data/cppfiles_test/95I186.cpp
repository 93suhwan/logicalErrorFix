#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--) {
    int sum, elements;
    cin >> sum >> elements;
    int aux_sum = sum, digit_sum = 0;
    while (aux_sum) {
      digit_sum += aux_sum % 10;
      aux_sum /= 10;
    }
    int power = 1;
    if (elements <= digit_sum) {
      vector<int> dividing;
      dividing.push_back(sum);
      while (dividing.size() < elements) {
        while (dividing[0] / power % 10 == 0) {
          power *= 10;
        }
        while (dividing.size() < elements and dividing[0] / power % 10 > 0) {
          dividing.push_back(power);
          dividing[0] -= power;
        }
      }
      for (int nr : dividing) {
        cout << nr << ' ';
      }
      cout << '\n';
    } else {
      set<int> dividing;
      int act_elements = 1;
      while (sum / power > 1) {
        while (sum / power % 10 == 0) {
          power *= 10;
        }
        while (sum / power % 10 > 0 and sum / power > 1) {
          if (power != 1) {
            dividing.insert(power);
          }
          act_elements++;
          sum -= power;
        }
      }
      dividing.insert(sum);
      while (act_elements < elements) {
        int nr = *dividing.begin();
        power = 1;
        while (nr > power * 10) {
          power *= 10;
        }
        dividing.erase(dividing.begin());
        if (power != 1) {
          dividing.insert(power);
        }
        if (nr - power > 0) {
          dividing.insert(nr - power);
          act_elements++;
        }
      }
      for (int nr : dividing) {
        cout << nr << ' ';
      }
      for (int i = 1; i <= elements - dividing.size(); ++i) {
        cout << 1 << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}

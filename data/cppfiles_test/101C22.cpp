#include <bits/stdc++.h>
using namespace std;
int main() {
  int times;
  cin >> times;
  for (int i = 0; i < times; i++) {
    int length;
    cin >> length;
    int given[length];
    for (int j = 0; j < length; j++) {
      cin >> given[j];
    }
    string color;
    cin >> color;
    vector<int> down;
    vector<int> up;
    for (int j = 0; j < length; j++) {
      if (color.at(j) == 'B')
        down.push_back(given[j]);
      else
        up.push_back(given[j]);
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());
    int downpos = 0;
    int uppos = 0;
    bool works = true;
    for (int j = 1; j <= length; j++) {
      if (down.size() > 0 && (downpos < down.size() && down[downpos] >= j)) {
        downpos++;
      } else {
        if (up.size() > 0 && (uppos < up.size() && up[uppos] <= j)) {
          uppos++;
        } else {
          works = false;
          break;
        }
      }
    }
    if (works)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

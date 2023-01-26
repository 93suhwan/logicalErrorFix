#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  scanf("%d", &a);
  while (a--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (y >= (x + 1) / 2 || z >= (x + 1) / 2) {
      printf("-1\n");
      continue;
    }
    vector<int> v;
    if (y > z) {
      v.push_back(1);
      v.push_back(2);
      while (y > 0 || z > 0) {
        if (v[v.size() - 1] == 2) {
          if (y > 0) {
            v.push_back(1);
            y--;
          } else {
            v.push_back(2);
            v.push_back(1);
          }
        } else {
          if (z > 0) {
            v.push_back(2);
            z--;
          } else {
            v.push_back(1);
            v.push_back(2);
          }
        }
      }
    } else {
      v.push_back(2);
      v.push_back(1);
      while (y > 0 || z > 0) {
        if (v[v.size() - 1] == 2) {
          if (y > 0) {
            v.push_back(1);
            y--;
          } else {
            v.push_back(2);
            v.push_back(1);
          }
        } else {
          if (z > 0) {
            v.push_back(2);
            z--;
          } else {
            v.push_back(1);
            v.push_back(2);
          }
        }
      }
    }
    if (v.size() <= x) {
      int last = v[v.size() - 1];
      int num = x - v.size();
      for (int i = 0; i < num; i += 1) {
        v.push_back(last);
      }
      for (int i = 0; i < v.size(); i += 1) {
        printf("%d%c", v[i], " \n"[i == v.size() - 1]);
      }
    } else {
      printf("-1\n");
    }
  }
}

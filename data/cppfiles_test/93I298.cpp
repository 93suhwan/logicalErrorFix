#include <bits/stdc++.h>
int main() {
  long long int tcase, nc, np, o, connectable, done;
  std::vector<long long int> O;
  std::cin >> tcase;
  for (int i = 0; i < tcase; i++) {
    connectable = 1;
    done = 1;
    o = 0;
    std::cin >> nc >> np;
    while (nc > done) {
      o++;
      done += connectable;
      if (done <= np)
        connectable = done;
      else if (done > np) {
        connectable = np;
        if ((nc - done) % connectable != 0)
          o += ((nc - done) / connectable) + 1;
        else
          o += ((nc - done) / connectable);
        break;
      }
    }
    O.push_back(o);
  }
  for (int i = 0; i < tcase; i++) {
    std::cout << O[i] << std::endl;
  }
}

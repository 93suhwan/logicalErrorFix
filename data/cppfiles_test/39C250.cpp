#include <iostream>
#include <algorithm>
#include <string>

const int maxwh = 1e8;

using namespace std;

double W, H;
double x1, y1, x2, y2;
double w, h;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        double ans;
        if (x2 - x1 + w > W && y2 - y1 + h > H)
            ans = -1;
        else {
            double ww = max(x1, W - x2);
            double hh = max(y1, H - y2);
            // cout << endl << ww << "hh =" << hh << endl;
            if (ww >= w || hh >= h)
                ans = 0;
            else {
                if (x2 - x1 + w > W)
                    ans = h - hh;
                else if (y2 - y1 + h > H)
                    ans = w - ww;
                else
                    ans = min(w - ww, h - hh);
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}
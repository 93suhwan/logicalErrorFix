#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct piii{
    int F, S, pos;
};
vector<int> a;
vector<piii> rep;
int trace[500005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x;
            a.push_back(x);
            trace[x] = x;
        }
        else {
            cin >> x >> y;
            if (a.size() > 0) {
                rep.push_back({x, y, a.size() - 1});
            }
        }
    }
    int n = rep.size() - 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        int dem = 0;
        while (rep[n].pos == i && n >= 0) {
            trace[rep[n].F] = rep[n].S;
            n--;
            dem++;
        }
        for (int j = 1; j <= dem; j++)
            a[i] = trace[a[i]];
        if(dem==0)
            a[i] = trace[a[i]];
    }
    for (int i : a)
        cout << i << " ";
}

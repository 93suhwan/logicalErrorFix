#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 2e5 + 105;

double rw, rh, x1, y1, x2, y2, tw, th;

int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        cin>>rw>>rh>>x1>>y1>>x2>>y2>>tw>>th;

        double ttw = (x2-x1), tth = (y2-y1);

        if(th+tth > rh && tw+ttw > rw){
            cout<<-1<<endl;
            continue;
        }

        double ans = 2e18;
        if(th+tth <= rh){
            double niche = y1;
            double upore = rh-y2;

            double maxim = max(niche, upore);
            double cur = max((double)0, th-maxim);
            ans = min(ans, cur);
        }
        if(tw+ttw <= rw){
            double niche = x1;
            double upore = rw-x2;

            double maxim = max(niche, upore);
            double cur = max((double)0, tw-maxim);
            ans = min(ans, cur);
        }
        cout<<ans<<endl;
    }
}

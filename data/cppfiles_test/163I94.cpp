#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define fst first
#define snd second
#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ci2(x,y) cin>>x>>y;
#define ci3(x,y,z) cin>>x>>y>>z;
#define ci4(x,y,z,w) cin>>x>>y>>z>>w;
#define co2(x,y) cout<<x<<" "<<y<<endl;
#define co3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define co4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
#define pii pair<int,int>
#define piii pair<int, pii>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define viii vector<piii>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define Vector Point
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define openio freopen("in","r",stdin);freopen("out","w",stdout)
#define closeio fclose(stdin);fclose(stdout)

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

using namespace std;

const int MX = 4e5+45;
const ll P = 1000000007LL;
ll E[MX];

ll fexp(ll b, ll e){
    ll r = 1;
    while(e){
        if(e%2) r = (r*b)%P;
        e/=2;
        b = (b*b)%P;
    }
    return r;
}

ll inv(ll x){
    return fexp(x,P-2);
}

void precalc(ll x, ll k){
    E[0] = 1;
    fore(i,1,k+1){
        E[i] = (E[i-1]*x)%P;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,rb,cb,rd,cd,p;
        cin>>n>>m>>rb>>cb>>rd>>cd>>p;
        rb--;
        cb--;
        rd--;
        cd--;
        ll t0 = 0;
        ll mcm = (m-1)*(n-1)/__gcd(n-1,m-1);
        ll n0 = (m-1)/__gcd(n-1,m-1);
        ll m0 = (n-1)/__gcd(n-1,m-1);
        if(n0%2 or m0%2){
            n0*=2;
            m0*=2;
            mcm*=2;
        }
        ll na = 0;
        ll ma = 0;
        set<ll> S;
        vll TN;
        TN.clear();
        fore(i,0,n0){
            ll nac;
            if(i%2) nac = (n-1)*(i+1)-rd;
            else nac = (n-1)*i+rd;
            if(nac>=rb) TN.pb(nac-rb);
            else TN.pb(rb-nac+mcm);
            if(TN[i]<mcm) S.insert(TN[i]);
        }
        vll TM;
        TM.clear();
        fore(i,0,m0){
            ll mac;
            if(i%2) mac = (m-1)*(i+1)-cd;
            else mac = (m-1)*i+cd;
            if(mac>=cb) TM.pb(mac-cb);
            else TM.pb(cb-mac+mcm);
            if(TM[i]<mcm) S.insert(TM[i]);
        }
        vll T;
        for(set<ll>::iterator it = S.begin(); it!=S.end(); it++){
            T.pb(*it);
        }
        int k = sz(T);
        ll pp = (p*inv(100LL))%P;
        precalc((P+1-pp)%P,k);
        ll ans = (pp*inv((P+1-E[k])%P))%P;
        ll lans = 0;
        fore(i,0,k){
            lans += (T[i]*E[i])%P;
            lans %= P;
        }
        lans += ((((mcm%P)*E[k])%P)*inv(pp))%P;
        lans %= P;
        ans *= lans;
        ans %= P;
        cout<<ans<<endl;
    }
    return 0;
}
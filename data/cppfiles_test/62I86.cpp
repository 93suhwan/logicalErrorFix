#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define inv(n) power((n), mod - 2)
#define ff(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define fff(i,a,b) for (int (i) = (a); (i) <= b; (i)++)
#define bff(i,a,b) for (int (i) = (b)-1; (i) >= (a); (i)--)
#define bfff(i,a,b) for (int (i) = (b); (i) >= (a); (i)--)
#define sum_overflow(a,b) __builtin_add_overflow_p ((a), (b), (__typeof__ ((a) + (b))) 0)
#define mul_overflow(a,b) __builtin_mul_overflow_p ((a), (b), (__typeof__ ((a) + (b))) 0)

using namespace std;
long double typedef ld;
unsigned int typedef ui;
long long int typedef li;
pair<int,int> typedef pii;
pair<li,li> typedef pli;
pair<ld,ld> typedef pld;
vector<vector<int>> typedef graph;
unsigned long long int typedef ull;
//const int mod = 998244353;
//const int mod = 1000000007;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;







//Note to self: Check for overflow

int n,m;
li ukljucen,st;
bool tab[1005][1005];

int izracun(int y, int x)
{
    int ret=0;

    if (y>x) y-=x,x=0;
    else x-=y,y=-0;

    int dole=x-1,desno=x-1;
    while (y<n && x<m)
    {
        if (tab[y][x]) dole=x,desno=x;
        ret+=2*x-dole-desno;

        if (tab[y+1][x]) dole=x;
        if (tab[y][x+1]) desno=x;
        ret+=2*x-dole-desno;

        y++,x++;
    }

    return ret;
}

int main()
{
    FAST;

    int q;
    cin>>n>>m>>q;
    ukljucen=n*m;
    fff(i,n,n+2) fff(j,0,m+2) tab[i][j]=1;
    fff(i,0,n+2) fff(j,m,m+2) tab[i][j]=1;

    ff(i,0,n) st+=izracun(i,0);
    ff(i,1,m) st+=izracun(0,i);

    cout<<st<<endl;

    while (q--)
    {
        int y,x; cin>>y>>x; y--,x--;
        st-=izracun(y,x),st-=izracun(y,x+1),st-=izracun(y+1,x);
        ukljucen+=tab[y][x],tab[y][x]^=1,ukljucen-=tab[y][x];
        st+=izracun(y,x),st+=izracun(y,x+1),st+=izracun(y+1,x);
        cout<<st-ukljucen<<"\n";
    }
}

//Note to self: Check for overflow

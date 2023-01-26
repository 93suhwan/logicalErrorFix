#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <cstdlib>
#include <string.h>

using namespace std;

#define For(i,i1,i2) for(int i=(int)i1 ; i<=(int)i2 ; i++)
#define Rof(i,i1,i2) for(int i=(int)i1 ; i>=(int)i2 ; i--)
#define int long long
#define NMAX 500005
#define MODU 1000000007
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back


int n;
int check[32],tot[32],occ[32];
char cs[NMAX],s2[NMAX],cand[NMAX];

int solve()
{
    fill(tot,tot+30,0);
    int dis = 0;
    For(i,0,n-1)
    {
        int c = cs[i] - 'a';
        tot[c]++;
    }
    For(i,0,30)
        if (tot[i]) dis++;

    fill(check,check+30,0);
    fill(occ,occ+30,0);
    int step = 0;
    string order = "";
    Rof(i,n-1,0)
    {
        int c = cs[i] - 'a';

        if (occ[c] ==0)
        {
            if (dis==0) return -1;
            occ[c] = tot[c]/dis;
            dis--;
            order = cs[i] + order;
            step += occ[c];
        }

        if (step == 0)
        {
            For(j,0,order.size()-1)
            {
                int c = order[j] - 'a';
                step += occ[c];
            }
        }
        step--;

    }

    int dz = 0;
    For(i,0,n-1)
    {
        int c = cs[i] - 'a';
        if (occ[c]==0) break;
        occ[c]--;
        cand[dz] = cs[i];
        dz++;
    }


    fill(check,check+30,0);
    strcpy(s2,cand);
    int s2z = strlen(s2);
    For(i,0,order.size()-1)
    {
        int c = order[i] - 'a';
        check[c] = 1;
        For(i,0,dz-1)
        {
            c = cand[i] - 'a';
            if (check[c]==0)
            {

                s2[s2z] = cand[i];
                s2z++;
            }
        }
    }
    //
    //cout<<s2<<'\n';
    if (s2z!=n)
        return -1;
    For(i,0,n-1)
    {
        if (s2[i]!=cs[i]) return -1;
    }

    //cout<<cand<<' '<<order<<'\n';
    printf("%s %s\n",cand,order.c_str());
    return 0;
}

main()
{
    //freopen("a.inp","r",stdin);
//    ios::sync_with_stdio(0);
//    cin.tie();
    int t;
    //cin>>t;
    scanf("%I64d",&t);
    while(t--)
    {
        //cin>>s;
        scanf("%s",cs);
        n = strlen(cs);
        int res = solve();
        if (res==-1)
            //cout<<-1<<'\n';
            printf("-1\n");
    }
}

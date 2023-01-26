#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair <int,int>
#define F first
#define S second
#define ever (;;)

const int N = 200100;

bool q;
int n,k,x[N],y[N],notOnline;
vector <ii> v;

ii findSlope(int p1,int p2)
{
    int bast = y[p2]-y[p1];
    int makam = x[p2]-x[p1];

    int g = __gcd(bast,makam);

    bast /= g;
    makam /= g;

    return { bast , makam };
}

bool onLine(int p1,int p2,int p3)
{
    ii m1 = findSlope(p1,p2);
    ii m2 = findSlope(p1,p3);

    return m1 == m2;
}

void ok(int p1,int p2)
{
    if( q )
        return;

    for(int i=3;i<=n;i++)
    {
        if( !onLine(p1,p2,i) )
        {
            if( notOnline )
                return;

            notOnline = i;
        }
    }

    q = 1;
}

double dist(int x1,int y1,int x2,int y2) { return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); }

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);

    ok(1,2);
    ok(1,3);
    ok(2,3);

    for(int i=1;i<=n;i++)
        if( i != notOnline )
            v.push_back( { x[i] , y[i] } );

    sort(v.begin(),v.end());
    n = (int)(v.size());
    int xout = x[notOnline];
    int yout = y[notOnline];
    int xstart = x[k];
    int ystart = y[k];

    if( k == notOnline )
    {
        printf("%.9f\n",dist(v[0].F,v[0].S,v[n-1].F,v[n-1].S) + min( dist(v[0].F,v[0].S,xout,yout) , dist(v[n-1].F,v[n-1].S,xout,yout) ) );
        return 0;
    }

    double all1 = dist(xstart,ystart,v[0].F,v[0].S) + dist(v[0].F,v[0].S,v[n-1].F,v[n-1].S);
    double all2 = dist(xstart,ystart,v[n-1].F,v[n-1].S) + dist(v[n-1].F,v[n-1].S,v[0].F,v[0].S);

    double ans = min( all1 + dist(v[n-1].F,v[n-1].S,xout,yout) , all2 +  + dist(v[0].F,v[0].S,xout,yout) );

    double all = min( all1 , all2 );

    for(int i=1;i<n;i++)
    {
        int x1 = v[i].F;
        int y1 = v[i].S;
        int x2 = v[i-1].F;
        int y2 = v[i-1].S;

        ans = min( ans , all - dist(x1,y1,x2,y2) + dist(x1,y1,xout,yout) + dist(x2,y2,xout,yout) );
    }

    int pos = -1;
    for(int i=0;i<n;i++)
        if( xstart == v[i].F && ystart == v[i].S )
            pos = i;

    if( pos+1 < n )
        ans = min( ans , all1 - dist(v[0].F,v[0].S,v[pos+1].F,v[pos+1].S) + dist(v[0].F,v[0].S,xout,yout) + dist(v[pos+1].F,v[pos+1].S,xout,yout) );
    if( pos-1 >= 0 )
        ans = min( ans , all2 - dist(v[n-1].F,v[n-1].S,v[pos-1].F,v[pos-1].S) + dist(v[n-1].F,v[n-1].S,xout,yout) + dist(v[pos-1].F,v[pos-1].S,xout,yout) );

    printf("%.9f\n",ans);
}

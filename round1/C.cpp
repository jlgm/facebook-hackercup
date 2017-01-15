#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define X first
#define Y second
#define INF 1e11

typedef long long ll;
typedef pair<ll, ll> pii;

ll n, m, k, adj[105][105], dist[105][105], memo[105][5005];
pii f[5005];

ll solve(ll prev, ll v) {
    //db(prev) db(v);
    if (v >= k) return 0;
    if (v == k-1) return dist[prev][f[v].X] + dist[f[v].X][f[v].Y];
    if (memo[prev][v] != -1) return memo[prev][v];
    else {
        ll ans1 = dist[prev][f[v].X] + dist[f[v].X][f[v].Y] + solve(f[v].Y, v+1);
        ll ans2 = dist[prev][f[v].X] + dist[f[v].X][f[v+1].X]
                    + dist[f[v+1].X][f[v].Y] + dist[f[v].Y][f[v+1].Y] + solve(f[v+1].Y,v+2);

        for(int i = 3; i < k-v; i++) {
            ll ans = dist[prev][f[v].X] + dist[f[v].X][f[v+1].X];
            for (int j = 0; j < i-2; j++) {
                ans += dist[f[v+j+1].X][f[v+j].Y] + dist[f[v+j].Y][f[v+j+2].X];
            }
            ans += dist[f[v+i-1].X][f[v+i-2].Y] + dist[f[v+i-2].Y][f[v+i-1].Y];
            ans += solve(f[v+i-1].Y, v+i);
            ans2 = min(ans2, ans);
        }
        return memo[prev][v] = min(ans1,ans2);
    }
}

int main() {

    int t; scanf("%d", &t); fr(caso, 1, t+1) {

        fr(i,0,105) fr(j,0,105) adj[i][j]=dist[i][j]=INF;
        ms(memo,-1);

        scanf("%lld%lld%lld", &n, &m, &k);
        fr(i,0,m) {
            ll x, y, c;
            scanf("%lld%lld%lld", &x, &y, &c);
            adj[x][y] = min(adj[x][y], c);
            adj[y][x] = adj[x][y];
            dist[x][y]=dist[y][x]=adj[x][y];
        }
        fr(i,0,k) {
            ll x, y;
            scanf("%lld%lld", &x, &y);
            f[i] = pii(x,y);
        }

        //floyd-warshall:
        fr(i,1,n+1) dist[i][i] = 0;
        fr(h,1,n+1) fr(i,1,n+1) fr(j,1,n+1) {
            dist[i][j] = min(dist[i][j], dist[i][h]+dist[h][j]);
        }

        ll ans = solve(1,0);

        printf("Case #%d: %lld\n", caso, ((ans<INF)?(ans):(-1LL)));
        ms(f,0);
    }

    return 0;
}

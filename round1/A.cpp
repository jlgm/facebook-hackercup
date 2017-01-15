#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define INF 1e10

typedef long long ll;

ll n, m, sum[305][305], memo[305][305];
vector<ll> c[305];

bool cmp(vector<ll> a, vector<ll> b) { return a[0] < b[0]; }

ll take(ll i, ll amt) {
    return sum[i][amt-1] + (amt)*(amt);
}

ll solve(ll k, ll taken) {

    if ((n-taken == 0) || (k==n)) return 0LL;
    if (memo[k][taken] != -1) return memo[k][taken];

    ll tot = INF;

    for(ll i = 1; i <= m; i++) {
        ll foo = take(k,i) + solve(k+1,taken+i);
        tot = min(foo, tot);
    }

    return memo[k][taken] = tot;
}

int main() {

    int t; scanf("%d", &t); fr(caso, 1, t+1) {
        ms(memo,-1);
        scanf("%lld%lld", &n, &m);
        fr(i,0,n) {
            fr(j,0,m) {
                ll foo;
                scanf("%lld", &foo);
                c[i].pb(foo);
            }
            sort(c[i].begin(), c[i].end());
        }

        fr(i,0,n) fr(j,0,m) sum[i][j] += (c[i][j] + (j ? sum[i][j-1] : 0));

        printf("Case #%d: %lld\n", caso, solve(0LL,0LL));

        fr(i,0,n) c[i].clear();
        ms(sum,0);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define lli long long int
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scl(x) scanf("%lld",&x)
#define scs(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 1000000000
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;

vector<pair<int, int>> graph[1000];
vi dist(1000, INF);
void Dijkastra(int d, int node) {
    priority_queue<pii, vpii, greater<pii>> pq;
    dist[node] = 0;
    pq.push({d, node});
    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currDis = pq.top().first;
        pq.pop();
        for (pair<int, int> edge : graph[currNode]) {
            if (currDis + edge.second < dist[edge.first]) {
                dist[edge.first] = currDis + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b, w;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> w;
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }
    Dijkastra(0, 1);
    for (int i = 1; i <= n; i++) {
        int dis = dist[i];
        deb2( i, dis);
    }
    return 0;
}

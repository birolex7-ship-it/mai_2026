#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
const ll M = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll inf = 1e18; // Маркер для обозначения ещё не посещенных вершин
 
    ll n, m, k;
    cin >> n >> m >> k;
 
    // Список смежности для хранения связей между вершинами графа
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    ll s = k - 1;
    queue<ll> q;
    vector<ll> d(n, inf); // Массив кратчайших расстояний до каждой вершины
    d[s] = 0;
    q.push(s);
    
    // Волновой обход графа для поиска путей
    while (q.size()) {
        ll u = q.front();
        q.pop();
        for (ll v : g[u]) {
            // Если у вершины всё ещё стоит inf значит мы нашли ее кратчайший путь
            if (d[v] == inf) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
 
    for (ll i = 0; i < n; i++) {
        if (d[i] == inf) {
            cout << "-1";
        } else {
            cout << d[i];
        }
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    
    return 0;
}
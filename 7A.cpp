#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
const ll M = 1e9 + 7;
const ll inf = 1e18; // Бесконечность для обозначения недостижимых вершин
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, s;
    cin >> n >> m >> s;
    s--; 
 
    // Список всех ребер графа для удобного последовательного перебора
    vector<vector<ll>> e;
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        e.push_back({u, v, w});
    }
  
    vector<ll> d(n, inf); // Массив текущих кратчайших расстояний
    d[s] = 0;
    for (ll i = 0; i < n-1; i++) {
        bool flag = false; // Отслеживание изменений за текущий проход
 
        for (ll j = 0; j < m; j++) {
            ll u = e[j][0];
            ll v = e[j][1];
            ll w = e[j][2];
 
            if (d[u] == inf) {
                continue;
            }
 
            // Пытаемся улучшить расстояние до вершины v
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                flag = true;
            }
        }
 
        // Выходим если за весь проход ни одно расстояние не уменьшилось
        if (!flag)  {
            break;
        }
    }
 
    // Дополнительный проход для поиска циклов отрицательного веса
    for (ll j = 0; j < m; j++) {
        ll u = e[j][0];
        ll v = e[j][1];
        ll w = e[j][2];
 
        if (d[u] != inf && d[v] > d[u] + w) {
            cout << "Negative cycle";
            return 0;
        }
    }
 
    for (ll i = 0; i < n; i++) {
        if (d[i] == inf) {
            cout << "inf" << ' ';
        } else {
            cout << d[i] << ' ';
        }
    }
 
    return 0;
}
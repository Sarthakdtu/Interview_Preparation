#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    int in[n];
    memset(in, 0, sizeof(in));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
    }
    int dis[n];
    memset(dis, 1, sizeof(dis));
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        for (auto i : g[a])
        {
            dis[i] = max(dis[a] + 1, dis[i]);
            in[i]--;
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dis[i]);
    cout << ans;
}

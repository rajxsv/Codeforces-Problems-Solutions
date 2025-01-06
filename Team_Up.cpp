#include <bits/stdc++.h>

using namespace std;

struct Dsu
{
    vector<int> par, siz, sum;
    int tot;

    // Function 'init(n)' will initialize our 'Dsu' provided appropriate size 'n'.
    void init(int n)
    {

        tot = n;

        // Size of all array's will be '2*n + 1', because we need to store additional dummy nodes.
        par.resize(2 * n + 1);
        siz.resize(2 * n + 1);
        sum.resize(2 * n + 1);
        for (int i = 1; i <= n; i++)
        {
            // Initialize 'par', 'siz', and 'sum' for all elements as we did in Approach 1.
            par[i] = i + n;
            siz[n + i] = 1;
            sum[i + n] = i;
            par[i + n] = i + n;
        }
    }

    // Function 'find(x)' will give us the parent of team 'x' belongs to. Basically team id of 'x'.
    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            // Also, path compression is performed here, refer to cp-algorithm DSU section for more information.
            return par[x] = find(par[x]);
        }
    }

    // Function 'unite(a,b)' will combine teams of member 'a' and 'b' into one team.
    void unite(int a, int b)
    {
        // Get, the team id of team where 'a' and 'b' belongs.
        a = find(a);
        b = find(b);
        if (a == b)
        {
            // If teams are same nothing to be done.
            return;
        }
        if (siz[a] > siz[b])
        {
            // If 'siz[a] > siz[b]' swap both, as we want to perform smaller to larger merging.
            swap(a, b);
        }
        // Now, make all the elements of team 'a', member of team 'b'.

        par[a] = b;
        siz[b] += siz[a];
        sum[b] += sum[a];
        siz[a] = 0;
        sum[a] = 0;
        return;
    }

    // Function, 'move(a,b)', will move member 'a' from its team to team of 'b'.
    void move(int a, int b)
    {
        // Get, the team id of both 'a' and 'b'.
        int parA = find(a), parB = find(b);
        if (parA == parB)
        {
            // If same nothing to be done.
            return;
        }

        // Decrement 'siz[parA]' by 1 and 'sum[parA]' by 'a', as it is removed.
        siz[parA]--;
        sum[parA] -= a;

        // Change the 'par[a]' to 'parB', so it becomes member of team 'b'.
        par[a] = parB;

        // Increase 'siz[parB]' and 'sum[parB]' in similar fashion to which decrement is done.
        siz[parB]++;
        sum[parB] += a;
    }

    // Function 'getSum(x)' will give us the sum of members of team where 'x' belongs.
    int getSum(int x)
    {
        // Get, team id where 'x' belongs.
        x = find(x);
        return sum[x];
    }

    // Function 'getSize(x)' will give us the size of members of team where 'x' belongs.
    int getSize(int x)
    {
        // Get, team id where 'x' belongs.
        x = find(x);
        return siz[x];
    }
};
vector<vector<int>> teamUp(int n, int q, vector<vector<int>> &queries)
{
    // Declare the Dsu 'd' to perform the queries efficiently.
    Dsu d;

    // Use, 'init(n)' function to initilize the arrays of Dsu 'd' by providing size 'n'.
    d.init(n);

    // Declare, 'ans' to store the result of all queries.
    vector<vector<int>> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 1)
        {
            // If query is type one, combine teams of 'queries[i][1]' and 'queries[i][2]' using 'unite(a,b)' function of Dsu 'd'.
            d.unite(queries[i][1], queries[i][2]);
        }
        else if (queries[i][0] == 3)
        {
            // If query is type three, move 'queries[i][1]' from its team to team of 'queries[i][2]' using 'move(a,b)' function of Dsu 'd'.

            d.move(queries[i][1], queries[i][2]);
        }
        else
        {
            // Get the size and sum of team where 'queries[i][1]' belongs to, using function 'getSize(x)' and 'getSum(x)', of Dsu 'd'.
            vector<int> currAns = {d.getSize(queries[i][1]), d.getSum(queries[i][1])};
            ans.push_back(currAns);
        }
    }

    // Finally, return 'ans'.
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> queries(q);
        for (int i = 0; i < q; i++)
        {
            int choice;
            cin >> choice;
            if (choice == 2)
            {
                int a;
                cin >> a;
                queries[i] = {choice, a};
            }
            else
            {
                int a, b;
                cin >> a >> b;
                queries[i] = {choice, a, b};
            }
        }
        vector<vector<int>> res = teamUp(n, q, queries);
        for (auto &i : res)
        {
            cout << i[0] << " " << i[1] << "\n";
        }
    }
}
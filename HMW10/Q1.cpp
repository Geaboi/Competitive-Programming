#include <iostream>
#include <vector>

using namespace std;

// Maximum nodes: queries * bit depth (200,000 * 30)
const int MAX_NODES = 6000005;
int trie[MAX_NODES][2];
int cnt[MAX_NODES];
int nodes_count = 1;

// Function to insert or remove an element
// val: 1 to add, -1 to remove
void update(int x, int val)
{
    int curr = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        if (!trie[curr][bit])
        {
            trie[curr][bit] = nodes_count++;
        }
        curr = trie[curr][bit];
        cnt[curr] += val;
    }
}

// Function to find max (x ^ y)
int query(int x)
{
    int curr = 0;
    int res = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        int target = 1 - bit; // We want the opposite bit to maximize XOR

        // Check if the opposite bit exists and is currently "active"
        if (trie[curr][target] && cnt[trie[curr][target]] > 0)
        {
            res |= (1 << i);
            curr = trie[curr][target];
        }
        else
        {
            curr = trie[curr][bit];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    // The multiset initially contains 0
    update(0, 1);

    while (q--)
    {
        char type;
        int x;
        cin >> type >> x;

        if (type == '+')
        {
            update(x, 1);
        }
        else if (type == '-')
        {
            update(x, -1);
        }
        else
        {
            cout << query(x) << "\n";
        }
    }

    return 0;
}
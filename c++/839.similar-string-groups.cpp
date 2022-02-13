#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
   public:
    vector<int> parent, size;

    int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void merge(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    bool isSimilar(string a, string b) {
        int n = a.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) cnt += 1;
            if (cnt > 2) return false;
        }
        return cnt <= 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // Initializing DSU
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }

        // Checking every string with all the other strings and if similar, doing union of their indices.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    int a = findParent(i);
                    int b = findParent(j);
                    if (a != b) merge(a, b);
                }
            }
        }
        int ans = 0;
        // If parent[i] == i, then i is not a child of someone else.
        // Counting such possibilities gives us the number of disjoint sets present in the DSU.
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) ans += 1;
        }
        return ans;
    }
};
// @lc code=end

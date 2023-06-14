each "item" (wynncraft accessory) has an associated mana value, and spell value. A solution is a collection
of exactly N of these items (each one may be used any number of times) such that the mana values of
all the items sum to at least M. An optimal solution is one where the sum of the spell values
of all the items are maximized. Find the optimal solution

ASSUMPTION: all mana values are positive


intuition and memo definition:

This is somewhat similar to the knapsack problem, but we constrain the collection to have exactly N items, and the mana
values of all items must add up to at least M instead of at most M. Define dp[i][j] to be the optimal solution with i elements in the colleciton
where their mana values sum to at least j.

i ranges from 0 to N inclusive, and j ranges from 0 to M inclusive.


dynamic programming base case:

We have dp[0][j] = 0 for j <= 0, and -1 otherwise.



dynamic programming recurrence relation:

dp[i][j] = max_{e in R} {dp[i-1][j-e.mana] + e.spell} where R is the set of items we were given at the beginning

however, it's possible for certain i, j combos to have no solution, and this will be indicated when dp[i][j] = -1.
Therefore, we need to use the recurrence relation very carefully. If dp[i-1][j-e.mana] returns -1, then we simply
move on to the next item. If dp[i-1][j-e.mana] returns -1 for all items, then dp[i][j] = -1.

Finally, if j is negative, dp[i][j] = dp[i][0] for any i since all mana values are positive.

time: 2d memo and each entry takes time linearly proportional to number of items given in items vector at the beginning,
so O(NML) where L is the length of the items vector

space: the 2d memo is the asymptotically largest variable ever created, and the function isn't recursive,
so O(NM)
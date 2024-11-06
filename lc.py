from collections import defaultdict
class Solution:
    def maximumValueSum(self, nums, k: int, edges) -> int:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        n = len(nums)

        nodes = sorted(range(n), key = lambda u: (nums[u] ^ k) - nums[u], reverse=True)
        

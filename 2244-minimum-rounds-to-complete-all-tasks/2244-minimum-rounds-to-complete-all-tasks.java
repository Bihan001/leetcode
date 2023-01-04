class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int difficulty : tasks) {
            map.put(difficulty, map.getOrDefault(difficulty, 0) + 1);
        }
        int ans = 0;
        for(int count : map.values()) {
            if(count < 2) return -1;
            if(count % 3 == 0) ans += count / 3; // Best case: Example - 15
            if(count % 3 == 1) ans += count / 3 - 1 + 2; // Example - 16, then 16 = (3 * 5 - 3) + (2 * 2)
            if(count % 3 == 2) ans += count / 3 + 1; // Example - 17, then 17 = (3 * 5) + 2
        }
        return ans;
    }
}

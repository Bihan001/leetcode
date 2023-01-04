class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int difficulty : tasks) {
            map.put(difficulty, map.getOrDefault(difficulty, 0) + 1);
        }
        int ans = 0;
        for(int difficulty : map.keySet()) {
            int count = map.get(difficulty);
            if(count < 2) return -1;
            int withTwo = count / 2;
            int withThree = count % 3 == 0 ? count / 3 : count % 3 == 1 ? count / 3 - 1 + 2 : count % 3 == 2 ? count / 3 + 1 : Integer.MAX_VALUE;
            ans += Math.min(withTwo, withThree);
        }
        return ans;
    }
}
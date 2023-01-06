class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int ans = 0;
        for(int c : costs) {
            if(c <= coins) {
                coins -= c;
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
}
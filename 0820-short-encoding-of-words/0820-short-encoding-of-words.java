class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet<>();
        Arrays.sort(words, (a, b) -> b.length() - a.length());
        int ans = 0;
        for(String word : words) {
            if(!set.contains(word)) {
                for(int i = 0; i < word.length(); i++) {
                    set.add(word.substring(i));
                }
                ans += word.length() + 1;
            }
        }
        return ans;
    }
}
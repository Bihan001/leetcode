class Solution {
    public boolean detectCapitalUse(String word) {
        int uppercaseCount = 0;
        for(int i = 0; i < word.length(); i++) {
            if(Character.isUpperCase(word.charAt(i))) {
                uppercaseCount++;
            }
        }
        return uppercaseCount == 0 || uppercaseCount == word.length() || (uppercaseCount == 1 && Character.isUpperCase(word.charAt(0)));
    }
}
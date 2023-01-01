class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> map = new HashMap<>();
        Map<String, Character> revMap = new HashMap<>();
        String[] arr = s.split(" ");
        if(arr.length != pattern.length()) return false;
        for(int i = 0; i < pattern.length(); i++) {
            if(!map.containsKey(pattern.charAt(i))) {
                if(revMap.containsKey(arr[i])) return false;
                map.put(pattern.charAt(i), arr[i]);
                revMap.put(arr[i], pattern.charAt(i));
            } else {
                if(!map.get(pattern.charAt(i)).equals(arr[i])) {
                    return false;
                }
            }
        }
        return true;
    }
}
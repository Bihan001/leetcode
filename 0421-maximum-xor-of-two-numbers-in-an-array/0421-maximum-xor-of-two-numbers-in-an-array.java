class Solution {
    /**
        First, a trie is built using the bits of the numbers from MSB to LSB.
        After that, for each element num in the array, an element is searched in the trie which has the maximum (num ^ trieElement)
        To do this, a number is built using the opposite bits of the (num) since xor of opposite bits result in 1. If opposite bit is not present in the trie for any ith bit, the same bit is taken. 
    */
    public int findMaximumXOR(int[] nums) {
        TrieNode root = new TrieNode();
        
        // Build Trie
        for(int num : nums) {
            TrieNode curr = root;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(curr.children[bit] == null) {
                    curr.children[bit] = new TrieNode();
                }
                curr = curr.children[bit];
            }
        }

        int ans = 0;
        for(int num : nums) {
            TrieNode curr = root;
            int res = 0;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1; // get the ith bit of num
                int targetBit = 1 - bit; // get the opposite bit to maximize the xor result
                if(curr.children[targetBit] != null) {
                    curr = curr.children[targetBit]; // go with opposite bit if found
                    res = res | (1 << i); // mark the ith bit of res as 1 since ith bit of num and ith bit of searched element is different and xor will give 1
                } else {
                    curr = curr.children[bit]; // if opposite bit not found, then go with same bit
                }
            }
            ans = Math.max(ans, res); // res is the maximum possible result for any arr[j] ^ num. no need to xor here since the bits are already set at line 31 -> res = res | (1 << i);
        }
        return ans;
    }
}

class TrieNode {
    TrieNode[] children;

    TrieNode() {
        this.children = new TrieNode[2];
    }
}
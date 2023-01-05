/**
    1. Sort the array by their 0th position
    2. Find common sections between adjacent elements and store in an arr
    3. If common section is not found between current element and last element in arr, insert the current element to arr
    4. If common section is found, update the last element in arr with the new common section
*/

class Solution {
    public int findMinArrowShots(int[][] points) {
        List<int[]> arr = new ArrayList<>();
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0])); // For points: [[-2147483646,-2147483645],[2147483646,2147483647]], a[0] - b[0] is so large that it won't fit in an integer. Thus Integer.compare(a[0], b[0]) is used instead
        arr.add(points[0]);
        for(int i = 1; i < points.length; i++) {
            int[] prev = arr.get(arr.size() - 1);
            int[] curr = points[i];
            if(curr[0] > prev[1]) {
                arr.add(curr);
                continue;
            }
            int[] newCurr = new int[]{curr[0], Math.min(prev[1], curr[1])};
            arr.set(arr.size() - 1, newCurr);
        }
        return arr.size();
    }
}

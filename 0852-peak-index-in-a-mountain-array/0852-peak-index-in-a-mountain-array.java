class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length - 1;
        int ans = 0;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid == 0 || mid == arr.length - 1) return 0;
            if(arr[mid + 1] < arr[mid] && arr[mid - 1] < arr[mid]) return mid;
            if(arr[mid - 1]< arr[mid] && arr[mid] < arr[mid + 1]) {
                low = mid;
            } else if(arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
                high = mid;
            }
        }
        return 0;
    }
}
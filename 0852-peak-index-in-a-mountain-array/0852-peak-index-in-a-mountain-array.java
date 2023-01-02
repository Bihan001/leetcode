class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 0;
        int high = arr.length - 1;
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
        return -1;
    }
}
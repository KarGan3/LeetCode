double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
     if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int low = 0, high = nums1Size;
    int totalLength = nums1Size + nums2Size;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (totalLength + 1) / 2 - partitionX;
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];   
        if (maxX <= minY && maxY <= minX) {
            if (totalLength % 2 == 0) {
                return (double)(fmax(maxX, maxY) + fmin(minX, minY)) / 2;
            } else {
                return fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return -1;
}
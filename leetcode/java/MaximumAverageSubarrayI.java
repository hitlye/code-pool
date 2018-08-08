class MaximumAverageSubarrayI {
  public double findMaxAverage(int[] nums, int k) {
    int n = nums.length;
    int maxSum = Integer.MIN_VALUE;
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    if (sum > maxSum) {
      maxSum = sum;
    }

    int i = 0;
    while (i + k < n) {
      sum -= nums[i];
      sum += nums[i + k];
      if (sum > maxSum) {
        maxSum = sum;
      }
      i++;
    }
    return (double) maxSum / k;
  }
}

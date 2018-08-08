class Sqrt {
  public int mySqrt(int x) {
    if (x < 2) {
      return x;
    }

    int left = 1;
    int right = x / 2;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid > x / mid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left < x / left ? left : right;
  }
}

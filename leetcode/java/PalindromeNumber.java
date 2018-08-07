class PalindromeNumber {
  public boolean isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int length = 0;
    int temp = x;
    while (temp > 0) {
      temp /= 10;
      length++;
    }

    int lastHalf = 0;
    int count = 0;
    while (count < length / 2) {
      int digit = x % 10;
      x /= 10;
      lastHalf = lastHalf * 10 + digit;
      count++;
    }
    if (length % 2 == 1) {
      lastHalf = lastHalf * 10 + x % 10;
    }

    return x == lastHalf;
  }
}

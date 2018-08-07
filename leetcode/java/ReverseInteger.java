class ReverseInteger {
  public int reverse(int x) {
    if (x == Integer.MIN_VALUE) {
      return 0;
    }

    boolean isNegative = x < 0 ? true : false;
    x = Math.abs(x);

    int output = 0;
    while (x > 0) {
      int digit = x % 10;
      x /= 10;

      if (output > Integer.MAX_VALUE / 10 || (output == Integer.MAX_VALUE / 10 && digit > 7)) {
        return 0;
      }

      output = output * 10 + digit;
    }

    return isNegative ? (output == -1 ? Integer.MIN_VALUE : -output) : output;
  }
}

class DivideTwoIntegers {
  public int divide(int dividend, int divisor) {
    boolean isOpposite = (dividend < 0 && divisor > 0) || (dividend >= 0 && divisor < 0);

    long dividendL = dividend;
    long divisorL = divisor;
    dividendL = Math.abs(dividendL);
    divisorL = Math.abs(divisorL);

    long countL = 0;
    while (dividendL >= divisorL) {
      long times = 1;
      while (dividendL >= (times << 1) * divisorL) {
        times = times << 1;
      }
      dividendL -= divisorL * times;
      countL += times;
    }

    if (countL == (long) Integer.MAX_VALUE + 1) {
      return isOpposite ? Integer.MIN_VALUE : Integer.MAX_VALUE;
    }

    int count = (int) countL;
    return isOpposite ? -count : count;
  }
}

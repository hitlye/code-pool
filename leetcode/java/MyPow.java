class MyPow {
  public double myPow(double x, int n) {
    long nLong = n;
    if (nLong < 0) {
      x = 1 / x;
      nLong = -nLong;
    }

    double ans = 1;
    while (nLong > 0) {
      double xPow = x;
      long times = 1;
      while (times << 1 <= nLong) {
        xPow *= xPow;
        times = times << 1;
      }
      nLong -= times;
      ans *= xPow;
    }

    return ans;
  }
}

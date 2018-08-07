class Sqrt {
  public int mySqrt(int x) {
    int sqrt = 0;
    while (sqrt * sqrt <= x && sqrt * sqrt >= 0) {
      sqrt++;
    }
    return sqrt - 1;
  }
}

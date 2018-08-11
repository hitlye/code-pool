class IntegertoRoman {
  public String intToRoman(int num) {
    StringBuilder sb = new StringBuilder();
    while (num > 0) {
      if (num >= 1000) {
        num = addRoman(sb, num, 1000, "M");
      } else if (num >= 500) {
        num = addRoman(sb, num, 500, "D");
      } else if (num >= 100) {
        num = addRoman(sb, num, 100, "C");
      } else if (num >= 50) {
        num = addRoman(sb, num, 50, "L");
      } else if (num >= 10) {
        num = addRoman(sb, num, 10, "X");
      } else if (num >= 5) {
        num = addRoman(sb, num, 5, "V");
      } else if (num >= 1) {
        num = addRoman(sb, num, 1, "I");
      }
    }
    return sb.toString()
        .replace("VIIII", "IX")
        .replace("LXXXX", "XC")
        .replace("DCCCC", "CM")
        .replace("IIII", "IV")
        .replace("XXXX", "XL")
        .replace("CCCC", "CD");
  }

  private int addRoman(StringBuilder sb, int num, int value, String symbol) {
    int times = num / value;
    for (int i = 0; i < times; i++) {
      sb.append(symbol);
    }
    return num - times * value;
  }
}

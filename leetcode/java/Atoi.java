class Atoi {
  public int myAtoi(String str) {
    str = str.trim();
    if (str.isEmpty()) {
      return 0;
    }

    if (str.charAt(0) == '+') {
      return scanInt(str.substring(1), true);
    } else if (str.charAt(0) == '-') {
      return scanInt(str.substring(1), false);
    } else {
      return scanInt(str, true);
    }
  }

  private int scanInt(String str, boolean isPositive) {
    int output = 0;
    for (char c : str.toCharArray()) {
      if (c < '0' || c > '9') {
        break;
      } else {
        int digit = c - '0';
        if (output > Integer.MAX_VALUE / 10
            || (output == Integer.MAX_VALUE / 10 && digit > (isPositive ? 7 : 8))) {
          return isPositive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        } else {
          output = output * 10 + digit;
        }
      }
    }
    return isPositive ? output : -output;
  }
}

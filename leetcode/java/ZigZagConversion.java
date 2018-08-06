import java.util.HashMap;
import java.util.Map;

public class ZigZagConversion {
  public String convert(String s, int numRows) {
    if (numRows == 1 || s.isEmpty())
      return s;

    Map<Integer, StringBuilder> mapping = new HashMap<>();
    for (int i = 0; i < Math.min(numRows, s.length()); i++)
      mapping.put(i, new StringBuilder());

    int row = 0;
    boolean goDown = true;

    for (char c : s.toCharArray()) {
      mapping.get(row).append(c);
      if ((goDown && row == numRows - 1) || (!goDown && row == 0))
        goDown = !goDown;
      row += goDown ? 1 : -1;
    }

    StringBuilder output = new StringBuilder();
    for (int i = 0; i < Math.min(numRows, s.length()); i++)
      output.append(mapping.get(i).toString());

    return output.toString();
  }
}

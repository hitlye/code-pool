import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PartitionLabels {
  public List<Integer> partitionLabels(String S) {
    Map<Character, Integer> lastIndices = new HashMap<>();
    for (int i = 0; i < S.length(); i++) {
      lastIndices.put(S.charAt(i), i);
    }

    List<Integer> lens = new ArrayList<>();
    int start = 0, lastIdx = 0;
    for (int i = 0; i < S.length(); i++) {
      lastIdx = Math.max(lastIndices.get(S.charAt(i)), lastIdx);
      if (i == lastIdx) {
        lens.add(i - start + 1);
        start = i + 1;
      }
    }

    return lens;
  }
}

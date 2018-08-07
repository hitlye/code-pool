import java.util.ArrayList;
import java.util.List;

class PermutationSequence {
  public String getPermutation(int n, int k) {
    List<Integer> candidates = new ArrayList<>();
    StringBuilder output = new StringBuilder();
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
      candidates.add(i);
      factorial *= i;
    }
    for (int i = n; i >= 1; i--) {
      factorial /= i;
      int idx = (k - 1) / factorial;
      k -= idx * factorial;
      output.append(candidates.get(idx));
      candidates.remove(idx);
    }
    return output.toString();
  }
}
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class CombinationSum2 {
  Set<List<Integer>> solutions;

  public List<List<Integer>> combinationSum2(int[] candidates, int target) {
    solutions = new HashSet<>();
    findSum(candidates, new ArrayList<>(), 0, 0, target);
    return new ArrayList<>(solutions);
  }

  private void findSum(int[] candidates, List<Integer> solution, int idx, int sum, int target) {
    if (sum == target) {
      Collections.sort(solution);
      if (!solutions.contains(solution)) {
        solutions.add(solution);
      }
      return;
    } else if (sum > target) {
      return;
    } else {
      for (int i = idx; i < candidates.length; i++) {
        List<Integer> solutionNew = new ArrayList<>(solution);
        solutionNew.add(candidates[i]);
        findSum(candidates, solutionNew, i + 1, sum + candidates[i], target);
      }
    }
  }
}

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ReconstructQueue {
  public int[][] reconstructQueue(int[][] people) {
    if (people.length == 0) {
      return new int[0][2];
    }

    // Group the people with the same height together and sort by k
    Arrays.sort(people, (p1, p2) -> {
      if (p1[0] == p2[0]) {
        return p1[1] - p2[1];
      } else {
        return p2[0] - p1[0];
      }
    });

    List<int[]> queueList = new ArrayList<>();
    int[][] queue = new int[people.length][2];
    for (int[] person : people) {
      queueList.add(person[1], person);
    }
    for (int i = 0; i < queueList.size(); i++) {
      queue[i] = queueList.get(i);
    }

    return queue;
  }
}

import java.util.ArrayList;
import java.util.List;

public class MergeIntervals {
  public List<Interval> merge(List<Interval> intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }

    intervals.sort((i1, i2) -> i1.start == i2.start ? i1.end - i2.end : i1.start - i2.start);

    List<Interval> output = new ArrayList<>();
    int start = intervals.get(0).start;
    int end = intervals.get(0).end;
    for (int i = 1; i < intervals.size(); i++) {
      Interval cur = intervals.get(i);
      if (cur.start > end) {
        output.add(new Interval(start, end));
        start = cur.start;
        end = cur.end;
      } else {
        end = Math.max(end, cur.end);
      }
    }
    output.add(new Interval(start, end));

    return output;
  }
}

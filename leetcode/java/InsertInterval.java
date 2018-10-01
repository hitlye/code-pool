import java.util.List;

public class InsertInterval {
  public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
    int start = newInterval.start, end = newInterval.end;
    int i = 0, n = intervals.size();

    while (i < n) {
      Interval cur = intervals.get(i);
      if (cur.end < start) {
        i++;
      } else if (cur.start > end) {
        break;
      } else {
        start = Math.min(start, cur.start);
        end = Math.max(end, cur.end);
        intervals.remove(i);
        n--;
      }
    }
    intervals.add(i, new Interval(start, end));

    return intervals;
  }
}

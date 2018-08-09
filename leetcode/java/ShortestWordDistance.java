class ShortestWordDistance {
  public int shortestDistance(String[] words, String word1, String word2) {
    int idx1 = -1;
    int idx2 = -1;
    int minDis = Integer.MAX_VALUE;
    for (int i = 0; i < words.length; i++) {
      if (words[i].equals(word1)) {
        idx1 = i;
        if (idx2 != -1) {
          int dis = Math.abs(i - idx2);
          if (dis < minDis) {
            minDis = dis;
          }
        }
      } else if (words[i].equals(word2)) {
        idx2 = i;
        if (idx1 != -1) {
          int dis = Math.abs(idx1 - i);
          if (dis < minDis) {
            minDis = dis;
          }
        }
      }
    }
    return minDis;
  }
}

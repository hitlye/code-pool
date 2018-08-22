import java.util.LinkedHashMap;
import java.util.Map;

class LruCache {
  private int capacity;
  private Map<Integer, Integer> cache;

  public LruCache(int capacity) {
    this.capacity = capacity;
    cache = new LinkedHashMap<>(capacity, 0.75f, true);
  }

  public int get(int key) {
    return cache.getOrDefault(key, -1);
  }

  public void put(int key, int value) {
    if (cache.size() == capacity && !cache.containsKey(key)) {
      cache.remove(cache.entrySet().iterator().next().getKey());
    }
    cache.put(key, value);
  }
}

/**
 * Your LruCache object will be instantiated and called as such:
 * LruCache obj = new LruCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
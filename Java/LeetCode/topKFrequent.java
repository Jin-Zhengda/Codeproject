/**
 * LeetCode LCR 060.前k个高频元素
 */
package LeetCode;
import java.util.*;

public class topKFrequent {
    // 使用map统计频率，按值排序取前k个键
    public List<Integer> topKNums(int[] nums, int k) {
        Map<Integer, Integer> freMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (!freMap.containsKey(nums[i])) {
                freMap.put(nums[i], 0);
            }
            freMap.put(nums[i], freMap.get(nums[i]) + 1);
        }
        List<Map.Entry<Integer, Integer>> sortedMap = new ArrayList<>(freMap.entrySet());
        sortedMap.sort((a, b) -> b.getValue() - a.getValue());
        List<Integer> returnS = new ArrayList<>();
        for (int i = 0; i < sortedMap.size(); i++) {
            if (i >= k) {
                break;
            }
            returnS.add(sortedMap.get(i).getKey());
        }
        return returnS;
    }
}

import java.util.ArrayList;
import java.util.Collections;

public class GemCollector {
    public static void bucketSort(int[] gems) {
        int maxVal = Integer.MIN_VALUE;
        int minVal = Integer.MAX_VALUE;
        
        // Find the maximum and minimum values in the array
        for (int i = 0; i < gems.length; i++) {
            maxVal = Math.max(maxVal, gems[i]);
            minVal = Math.min(minVal, gems[i]);
        }
        
        int numBuckets = (maxVal - minVal) / gems.length + 1;
        ArrayList<ArrayList<Integer>> buckets = new ArrayList<>(numBuckets);
        
        // Initialize buckets
        for (int i = 0; i < numBuckets; i++) {
            buckets.add(new ArrayList<>());
        }
        
        // Distribute gems into buckets
        for (int i = 0; i < gems.length; i++) {
            int bucketIndex = (gems[i] - minVal) / gems.length;
            buckets.get(bucketIndex).add(gems[i]);
        }

        //show buckets before sorting
        for (int i = 0; i < numBuckets; i++) {
            System.out.println("Bucket " + i + ": " + buckets.get(i));
        }
        
        // Sort individual buckets
        for (int i = 0; i < numBuckets; i++) {
            Collections.sort(buckets.get(i));
        }
        
        for (int i = 0; i < numBuckets; i++) {
            System.out.println("Bucket " + i + ": " + buckets.get(i));
        }
        // Concatenate sorted buckets into the result array
        int index = 0;
        for (int i = 0; i < numBuckets; i++) {
            for (int j = 0; j < buckets.get(i).size(); j++) {
                gems[index++] = buckets.get(i).get(j);
            }
        }
    }

    public static void main(String[] args) {
        int[] gems = {29, 15, 2, 45, 10, 17, 36};
        
        System.out.println("Unsorted gems: ");
        for (int i : gems) {
            System.out.print(i + " ");
        }
        System.out.println();
        
        bucketSort(gems);
        
        System.out.println("\n\nSorted gems: ");
        for (int i : gems) {
            System.out.print(i + " ");
        }
    }
}

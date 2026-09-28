class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of first rectangle
        int areaA = (ax2 - ax1) * (ay2 - ay1);

        // Area of second rectangle
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Width of overlapping region
        int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));

        // Height of overlapping region
        int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));

        // Overlapping area
        int overlapArea = overlapWidth * overlapHeight;

        // Don't count overlapping part twice
        return areaA + areaB - overlapArea;
    }
};
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int AxLen = ax2-ax1;
        int AyLen = ay2-ay1;
        int BxLen = bx2-bx1;
        int ByLen = by2-by1;
        int commonArea = 0;
        int Xlen, Ylen;
        Xlen = min(ax2,bx2)-max(ax1,bx1);
        if (Xlen < 0) Xlen = 0;
        Ylen = min(ay2,by2)-max(ay1,by1);
        if (Ylen < 0) Ylen = 0;
        commonArea = Xlen * Ylen;
        return ((AxLen * AyLen) + (BxLen * ByLen) - commonArea);
    }
};
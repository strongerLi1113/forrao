#include "conversion.h"

conversion::conversion()
{

}

int conversion::YUV2RGB(unsigned char* pYUV,unsigned char* pBGR24,int width,int height)
{

        const long len = width * height;
        unsigned char* yData = pYUV;
        unsigned char* vData = &yData[len];
        unsigned char* uData = &vData[len >> 2];

        int bgr[3];
        int yIdx,uIdx,vIdx,idx;
        for (int i = 0;i < height;i++){
            for (int j = 0;j < width;j++){
                yIdx = i * width + j;
                vIdx = (i/2) * (width/2) + (j/2);
                uIdx = vIdx;
      /*  YUV420 转 BGR24
                bgr[0] = (int)(yData[yIdx] + 1.732446 * (uData[vIdx] - 128)); // b分量
                bgr[1] = (int)(yData[yIdx] - 0.698001 * (uData[uIdx] - 128) - 0.703125 * (vData[vIdx] - 128));// g分量
                bgr[2] = (int)(yData[yIdx] + 1.370705 * (vData[uIdx] - 128)); // r分量
     */
     /*  YUV420 转 RGB24 注意如转换格式不对应会导致颜色失真*/
                bgr[0] = (int)(yData[yIdx] + 1.370705 * (vData[uIdx] - 128)); // r分量
                bgr[1] = (int)(yData[yIdx] - 0.698001 * (uData[uIdx] - 128) - 0.703125 * (vData[vIdx] - 128));// g分量
                bgr[2] = (int)(yData[yIdx] + 1.732446 * (uData[vIdx] - 128)); // b分量

                for (int k = 0;k < 3;k++){
                    idx = (i * width + j) * 3 + k;
                    if(bgr[k] >= 0 && bgr[k] <= 255)
                        pBGR24[idx] = bgr[k];
                    else
                        pBGR24[idx] = (bgr[k] < 0)?0:255;
                }
            }
        }
        return true;
}

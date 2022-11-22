#ifndef CV_H
#define CV_H
# include<stdbool.h>
typedef struct
{
    unsigned long bfSize;  //�ļ���С
    unsigned short fReserved1;  //������
    unsigned short fReserved2;  //������
    unsigned long fOffBits;  //λͼ����ƫ���ֽ���
} BitMapFileHeader;  /*�ļ�ͷ*/

typedef struct
{
    unsigned long biSize;   //�ṹ�峤��
    long biWidth;   //λͼ���
    long biHeight;   //λͼ�߶�
    unsigned short biPlanes;   //λͼƽ����
    unsigned short biBitCount;  //��ɫλ��
    unsigned long biCompression;   //ѹ����ʽ
    unsigned long biSizeImage;   //ʵ��λͼ����ռ�õ��ֽ���
    long biXPelsPerMeter;   //X����ֱ���
    long biYPelsPerMeter;   //Y����ֱ���
    unsigned long biClrUsed;   //ʹ�õ���ɫ��
    unsigned long biClrImportant;   //��Ҫ��ɫ��
} BitMapInfoHeader;  /*λͼ��Ϣͷ*/

typedef struct
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
} PixelBlock;

typedef struct
{
    int width;
    int height;
    int channels;
    PixelBlock* imageData;
}BMPImage;

BMPImage* LoadBMPImage(char* path);
bool SaveBMPImage(char* path, BMPImage* bmpImg);

#endif
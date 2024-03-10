#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

int TxPin = 11;
int RxPin = 10;
#define PIN             6
#define NUMPIXELS       104

Adafruit_NeoPixel Strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
SoftwareSerial BTSerial(TxPin, RxPin);

#define kCodeCount_E    8
#define kCodeCount_F    8
#define kCodeCount_f    8
#define kCodeCount_G    8
#define kCodeCount_g    8
#define kCodeCount_A    8
#define kCodeCount_a    8
#define kCodeCount_B    8
#define kCodeCount_C    8
#define kCodeCount_c    8
#define kCodeCount_D    8
#define kCodeCount_d    8

#define getCodeCount(c) kCodeCount_ ## c
#define getCombineCode2(name, code_1, code_2) \
    int name[getCodeCount(code_1) + getCodeCount(code_2)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
    }
#define getCombineCode3(name, code_1, code_2, code_3) \
    int name[getCodeCount(code_1) + getCodeCount(code_2) + getCodeCount(code_3)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
        for (int j = 0; j < getCodeCount(code_3); i++, j++) \
            name[i] = code_3[j]; \
    }
#define getCombineCode4(name, code_1, code_2, code_3, code_4) \
    int name[getCodeCount(code_1) + getCodeCount(code_2) + getCodeCount(code_3) + getCodeCount(code_4)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
        for (int j = 0; j < getCodeCount(code_3); i++, j++) \
            name[i] = code_3[j]; \
        for (int j = 0; j < getCodeCount(code_4); i++, j++) \
            name[i] = code_4[j]; \
    }
#define getCombineCode5(name, code_1, code_2, code_3, code_4, code_5) \
    int name[getCodeCount(code_1) + getCodeCount(code_2) + getCodeCount(code_3) + getCodeCount(code_4) + getCodeCount(code_5)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
        for (int j = 0; j < getCodeCount(code_3); i++, j++) \
            name[i] = code_3[j]; \
        for (int j = 0; j < getCodeCount(code_4); i++, j++) \
            name[i] = code_4[j]; \
        for (int j = 0; j < getCodeCount(code_5); i++, j++) \
            name[i] = code_5[j]; \
    }
#define getCombineCode6(name, code_1, code_2, code_3, code_4, code_5, code_6) \
    int name[getCodeCount(code_1) + getCodeCount(code_2) + getCodeCount(code_3) + getCodeCount(code_4) + getCodeCount(code_5) + getCodeCount(code_6)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
        for (int j = 0; j < getCodeCount(code_3); i++, j++) \
            name[i] = code_3[j]; \
        for (int j = 0; j < getCodeCount(code_4); i++, j++) \
            name[i] = code_4[j]; \
        for (int j = 0; j < getCodeCount(code_5); i++, j++) \
            name[i] = code_5[j]; \
        for (int j = 0; j < getCodeCount(code_6); i++, j++) \
            name[i] = code_6[j]; \
    }

#define getCombineCode7(name, code_1, code_2, code_3, code_4, code_5, code_6,code_7) \
    int name[getCodeCount(code_1) + getCodeCount(code_2) + getCodeCount(code_3) + getCodeCount(code_4) + getCodeCount(code_5) + getCodeCount(code_6) + getCodeCount(code_7)]; \
    { \
        int i = 0; \
        for (; i < getCodeCount(code_1); i++) \
            name[i] = code_1[i]; \
        for (int j = 0; j < getCodeCount(code_2); i++, j++) \
            name[i] = code_2[j]; \
        for (int j = 0; j < getCodeCount(code_3); i++, j++) \
            name[i] = code_3[j]; \
        for (int j = 0; j < getCodeCount(code_4); i++, j++) \
            name[i] = code_4[j]; \
        for (int j = 0; j < getCodeCount(code_5); i++, j++) \
            name[i] = code_5[j]; \
        for (int j = 0; j < getCodeCount(code_6); i++, j++) \
            name[i] = code_6[j]; \
        for (int j = 0; j < getCodeCount(code_7); i++, j++) \
            name[i] = code_7[j]; \
    }
    
#define getCombineCode(name, count, ...) getCombineCode ## count(name, __VA_ARGS__)

int E[getCodeCount(E)] = {  0, 12, 18, 29, 41, 57, 65, 77 };
int F[getCodeCount(F)] = { 11, 19, 28, 42, 56, 66, 200,  200      };
int f[getCodeCount(f)] = { 10, 20, 27, 43, 55, 67, 200 ,  200     };
int G[getCodeCount(G)] = {  9, 21, 26, 44, 54, 68, 38  , 200  };
int g[getCodeCount(g)] = {  8, 22, 37, 45, 53, 69 , 200 ,  200    };
int A[getCodeCount(A)] = {  7, 23, 36, 46, 52, 70, 64,  200   };
int a[getCodeCount(a)] = {  6, 24, 35, 47, 63, 71, 200,  200      };
int B[getCodeCount(B)] = {  5, 25, 34, 48, 62, 72, 13  , 200  };
int C[getCodeCount(C)] = {  4, 14, 33, 49, 61, 73  ,200,  200     };
int c[getCodeCount(c)] = {  3, 15, 32, 50, 60, 74   ,200,  200    };
int D[getCodeCount(D)] = {  2, 16, 31, 51, 59, 75, 39 , 200   };
int d[getCodeCount(d)] = {  1, 17, 58, 30, 76, 40  , 200 ,200     };

void setup()
{
    BTSerial.begin(9600);
    Strip.begin();
    Strip.show();
}

void loop()
{
    if (BTSerial.available()) {
        char cmd = (char)BTSerial.read();
        if (cmd == '0') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));
                
            getCombineCode7(n, E, F, G, A, B, C, D );
            for (int J=0; J<56; ++J)
                Strip.setPixelColor(n[J],Strip.Color(1,1,1));


            for (int k=0; k<8; ++k)
            Strip.setPixelColor(C[k],Strip.Color(1,0,0));
            
            Strip.show();
        }
        else if (cmd == '1') {
            for (int I=0; I<78; I=I+1)
            Strip.setPixelColor(I,Strip.Color(0,0,0));
                
            getCombineCode7(n, c,d,F,f,g,a,C );
            for (int J=0; J<56; ++J)
            Strip.setPixelColor(n[J],Strip.Color(1,1,1));


            for (int k=0; k<8; ++k)
            Strip.setPixelColor(c[k],Strip.Color(1,0,0));
            
            Strip.show();
 
        }
        else if (cmd == '2') {
            for (int I=0; I<78; I=I+1)
            Strip.setPixelColor(I,Strip.Color(0,0,0));
                
            getCombineCode7(n, D,E,f,G,A,B,c );
            for (int J=0; J<56; ++J)
            Strip.setPixelColor(n[J],Strip.Color(1,1,1));


            for (int k=0; k<8; ++k)
            Strip.setPixelColor(D[k],Strip.Color(1,0,0));
            
            Strip.show();
 
        }
            else if (cmd == '3') {
            for (int I=0; I<78; I=I+1)
            Strip.setPixelColor(I,Strip.Color(0,0,0));
                
            getCombineCode7(n, G,g,a,B,c,d,F );
            for (int J=0; J<56; ++J)
            Strip.setPixelColor(n[J],Strip.Color(1,1,1));


            for (int k=0; k<8; ++k)
            Strip.setPixelColor(G[k],Strip.Color(1,0,0));
            
            Strip.show();
 
        }
            else if (cmd == '4') {
            for (int I=0; I<78; I=I+1)
            Strip.setPixelColor(I,Strip.Color(0,0,0));
                
            getCombineCode4(n, E, G, A, C );
            for (int J=0; J<32; ++J)
            Strip.setPixelColor(n[J],Strip.Color(1,1,1));


            for (int k=0; k<8; ++k)
            Strip.setPixelColor(A[k],Strip.Color(1,0,0));
            
            Strip.show();
 
        }
        else if (cmd == 'E') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<8; ++J)
                Strip.setPixelColor(E[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'F') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(F[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'f') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(f[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'G') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<7; ++J)
                Strip.setPixelColor(G[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'g') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(g[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'A') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<7; ++J)
                Strip.setPixelColor(A[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'a') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(a[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'B') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<7; ++J)
                Strip.setPixelColor(B[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'C') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(C[J],Strip.Color(1,1,1));
            
            Strip.show();
        }
        else if (cmd == 'c') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(c[J],Strip.Color(1,1,1));

            Strip.show();
        }
        else if (cmd == 'D') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<7; ++J)
                Strip.setPixelColor(D[J],Strip.Color(1,1,1));

            Strip.show();
        }
        else if (cmd == 'd') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            for (int J=0; J<6; ++J)
                Strip.setPixelColor(d[J],Strip.Color(1,1,1));

            Strip.show();
        }
        else if (cmd == 'z') {
            for (int I=0; I<78; I=I+1)
                Strip.setPixelColor(I,Strip.Color(0,0,0));

            Strip.show();
        }
    }
}


#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void draw_circle(int Xc,int Yc,int rad);
void symmetry(int x,int y,int Xc,int Yc);

int main() {
    int Xc,Yc,R;
    int gd = DETECT, gm;
    printf("Enter the center of the circle:\nXc: ");
    scanf("%d",&Xc);
    printf("Yc: ");
    scanf("%d",&Yc);
    printf("Enter the radius of the circle: ");
    scanf("%d",&R);

    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    draw_circle(Xc,Yc,R);
    getch();
    closegraph();
    return 0;
}

void draw_circle(int Xc,int Yc,int rad){
    int x = 0, y = rad, p = 1 - rad;
    symmetry(x,y,Xc,Yc);
    while(x <= y){
        if(p < 0){
            p += 2*x + 3;
        } else {
            p += 2*(x - y) + 5;
            y--;
        }
        x++;
        symmetry(x,y,Xc,Yc);
        delay(50);
    }
}

void symmetry(int x,int y,int Xc,int Yc){
    putpixel(Xc+x,Yc-y,BLUE);
    putpixel(Xc+y,Yc-x,BLUE);
    putpixel(Xc+y,Yc+x,BLUE);
    putpixel(Xc+x,Yc+y,BLUE);
    putpixel(Xc-x,Yc+y,BLUE);
    putpixel(Xc-y,Yc+x,BLUE);
    putpixel(Xc-y,Yc-x,BLUE);
    putpixel(Xc-x,Yc-y,BLUE);
}


#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int x, y, x1, y1, x2, y2, p, dx, dy;
    int gd = DETECT, gm;

    // 1?? Ask user input FIRST
    printf("Enter the x coordinate of the first point: ");
    scanf("%d", &x1);
    printf("Enter the y coordinate of the first point: ");
    scanf("%d", &y1);
    printf("Enter the x coordinate of the second point: ");
    scanf("%d", &x2);
    printf("Enter the y coordinate of the second point: ");
    scanf("%d", &y2);

    // 2?? Initialize graphics AFTER input
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;

    p = 2*dy - dx;
    putpixel(x, y, 2);

    while(x <= x2) {
        if(p < 0) {
            x++;
            p += 2*dy;
        } else {
            x++;
            y++;
            p += 2*dy - 2*dx;
        }
        putpixel(x, y, 7);
    }

    getch();
    closegraph();
    return 0;
}


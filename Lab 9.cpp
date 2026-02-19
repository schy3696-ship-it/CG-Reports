#include <stdio.h>
#include <conio.h>
#include <graphics.h>

#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

float xmin, ymin, xmax, ymax;

/* Function to compute region code */
int computeCode(float x, float y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherlandClip(float x1, float y1, float x2, float y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;   // Line is inside
            break;
        }
        else if (code1 & code2)
        {
            break;        // Line is outside
        }
        else
        {
            float x, y;
            int code_out = code1 ? code1 : code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);

    if (accept)
    {
        outtextxy(50, 50, "Line is Visible After Clipping");
        line(x1, y1, x2, y2);
    }
    else
    {
        outtextxy(50, 50, "Line is Completely Outside");
    }
}

int main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;

    initgraph(&gd, &gm, "");

    printf("Enter xmin ymin: ");
    scanf("%f %f", &xmin, &ymin);

    printf("Enter xmax ymax: ");
    scanf("%f %f", &xmax, &ymax);

    printf("Enter x1 y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%f %f", &x2, &y2);

    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    getch();

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}


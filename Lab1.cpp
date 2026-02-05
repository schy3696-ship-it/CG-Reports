#include<stdio.h>
#include<graphics.h>

int main(){
	int gd=DETECT,gm;
	initgraph(&gd, &gm, (char*)"");
	
	//Draw here
	setcolor(15);
	line(100,100,200,200);
	line(200,200,300,300);
	
	setcolor(14);
	circle(300,300,50);
	
	setcolor(13);
	rectangle(100,100,150,150);
	
	putpixel(250,250,5);
	putpixel(200,200,6);
	
	setbkcolor(0);
	//To hang graphic mode
	getch();
	//to close graph mode
	closegraph();
	
	return 0;
}

#include "Dibujador.h"
#include "Color.h"
#include "Lista.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void drawColorList(int num, char *nombre, char *red, char *green, char *blue)
{
    int MaxHeight, MaxWidth, i, j;
    init_pair(0,COLOR_BLACK,COLOR_WHITE); // COLOR LETRA; COLOR FONDO

    getmaxyx(stdscr,MaxHeight,MaxWidth);
    int height = MaxHeight/6;
    int fill = height*(num-0.5);

    init_color(6, 0, 0, 0 );
    init_color(7, 1000, 1000, 1000 );
    init_pair(6, 6, 7);
    init_color(num, atoi(red), atoi(green), atoi(blue) );
    init_pair(num, COLOR_BLACK, num);

    //int numx = num%4 + 1;
    
    attron(COLOR_PAIR(num));
    for(i = 0; i < height-2; i++)
    {
        for(j = 5; j < MaxWidth-5; j++)
        {
            mvaddch(fill, j, ' ');
        }
        fill++;
    }
    attroff(COLOR_PAIR(num));

	attron(COLOR_PAIR(6));
    int tab = MaxWidth - strlen(nombre) - strlen(red) - strlen(green) - strlen(blue) - 10;
    for (i = 5;i<tab+5;i++)
    {
		mvaddch(fill,i,' ');
	}
   
    mvprintw(fill,tab,"%s (%s,%s,%s)\n",nombre,red,green,blue);
    attroff(COLOR_PAIR(6));
}

void drawColorGrid(int num, int posx, int posy, char *nombre, char *red, char *green, char *blue)
{
    int MaxHeight, MaxWidth, i, j;
    init_pair(0,COLOR_BLACK,COLOR_WHITE); // COLOR LETRA; COLOR FONDO

    getmaxyx(stdscr,MaxHeight,MaxWidth);
    int height = MaxHeight/6;
    int width = MaxWidth/4;
	init_color(21, 0, 0, 0 );
    init_color(22, 1000, 1000, 1000 );
    init_pair(21, 21, 22);
    init_color(num, atoi(red), atoi(green), atoi(blue) );
    init_pair(num, COLOR_BLACK, num);

    posy = height*(posy) - 2;
    posx = width*(posx - 1);
    
    attron(COLOR_PAIR(num));
    for(i = posy; i < posy + height - 2 ; i++)
    {
        for(j = posx + 1 ; j < posx + width ; j++)
        {
            mvaddch(i, j, ' ');
        }
    }
    attroff(COLOR_PAIR(num));

    attron(COLOR_PAIR(21));
    int tab = width - strlen(nombre) - strlen(red) - strlen(green) - strlen(blue) - 5;
    for (i = posx+1; i<tab+posx+1;i++)
    {
		mvaddch(posy+height-2,i,' ');
	}
	    
    mvprintw(posy+height-2,posx + tab,"%s (%s,%s,%s)\n",nombre,red,green,blue);
    attroff(COLOR_PAIR(21));
}

void drawPage(int tipo)
{
    initscr();
    start_color();
    init_pair(0,COLOR_BLACK,COLOR_WHITE); // COLOR LETRA; COLOR FONDO

    curs_set(0);

    keypad(stdscr,TRUE);

    if (tipo == 1)
    {
    	Lista *lista = initLista();
    	textToList(lista);
    	goToStart(lista);
    	int ch = KEY_RIGHT;
    	int page = 0;
    	while(ch != KEY_UP)
    	{
    		if (ch == KEY_RIGHT)
    		{
    			if (goToPos(lista, page*5 + 1) == 0 )
    			{
			    	clear();
    				page++;
					int i = 1;
			    	do
			    	{
			    		Color *color = getCurrentColor(lista);
				    	drawColorList(i,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
				    	i++;
				    	
			    	}while (next(lista) == 0 && i < 6);
    			}
    		}
    		else if (ch == KEY_LEFT)
    		{
    			if (page > 0)
    			{
			    	clear();
    				goToPos(lista, (page-1)*5 + 1);
    				page--;
					int i = 1;
			    	do
			    	{
			    		Color *color = getCurrentColor(lista);
				    	drawColorList(i,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
				    	i++;
				    	
			    	}while (next(lista) == 0 && i < 6);
    			}
    		}
	    	ch = getch();
    	}
    }

    else if(tipo == 2)
    {
        Lista *lista = initLista();
        textToList(lista);
        goToStart(lista);
        int ch = KEY_RIGHT;
        int page = 0;
        while(ch != KEY_UP)
    	{
    		if (ch == KEY_RIGHT)
    		{
    			if (goToPos(lista, page*20 + 1) == 0 )
    			{
    				page++;
					clear();
		            int x,y,i;
		            i = 1;
	                x = 1;
	                y = 1;
	                do
	                {
	                    Color *color = getCurrentColor(lista);
	                    drawColorGrid(i,x,y,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
	                    i++;
	                    x++;
	                    if(x%5 == 0)
	                    {
	                    	x = 1;
	                    	y++;
	                    }
	                    
	                }while (next(lista) == 0 && i < 21);
    			}
    		}
    		else if (ch == KEY_LEFT)
    		{
    			if (page > 0)
    			{
    				goToPos(lista, (page-1)*20 + 1);
    				page--;
					clear();
		            int x,y,i;
		            i = 1;
	                x = 1;
	                y = 1;
	                do
	                {
	                    Color *color = getCurrentColor(lista);
	                    drawColorGrid(i,x,y,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
	                    i++;
	                    x++;
	                    if(x%5 == 0)
	                    {
	                    	x = 1;
	                    	y++;
	                    }
	                    
	                }while (next(lista) == 0 && i < 21);
    			}
    		}
	    	ch = getch();
        }
    }

    endwin();
   
}

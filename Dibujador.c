#include "Dibujador.h"
#include "Color.h"
#include "Lista.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void drawColorList(int pos, char *nombre, char *red, char *green, char *blue)
{
    int MaxHeight, MaxWithd, i, j;

    getmaxyx(stdscr,MaxHeight,MaxWithd);
    int height = MaxHeight/5;
    int fill = height*(pos-0.5);

    init_color(pos, atoi(red), atoi(green), atoi(blue) );
    init_pair(pos, COLOR_BLACK, pos);
    
    attron(COLOR_PAIR(pos));
    for(i = 0; i < height-1; i++)
    {
        for(j = 5; j < MaxWithd-5; j++)
        {
            mvaddch(fill, j, ' ');
        }
        fill++;
    }
    attroff(COLOR_PAIR(pos));

    int tab = MaxWithd - strlen(nombre) - strlen(red) - strlen(green) - strlen(blue) - 10;
    attron(COLOR_PAIR(0));
    mvprintw(fill,tab,"%s (%s,%s,%s)\n",nombre,red,green,blue);
    attroff(COLOR_PAIR(0));
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
    	while(ch != KEY_UP)
    	{
    		if (ch == KEY_RIGHT)
    		{
				int i = 1;
		    	do
		    	{
		    		Color *color = getCurrentColor(lista);
			    	drawColorList(i,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
			    	i++;
			    	
		    	}while (next(lista) == 0 && i < 6);
    		}
    		else if (ch == KEY_LEFT)
    		{
    			int i = 0;
    			while (prev(lista) == 0 && i < 6)
    			{
    				i++;
    			}	
    			i = 1;
		    	do
		    	{
		    		Color *color = getCurrentColor(lista);
			    	drawColorList(i,getColorName(color),getColorRed(color),getColorGreen(color),getColorBlue(color));
			    	i++;
			    	
		    	}while (next(lista) == 0 && i < 6);
    		}
	    	ch = getch();
	    	clear();
    	}
    }

    endwin();
   
}
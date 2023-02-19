#include "../inc/header.h"

void mx_rain()
{
    srand(time(0));
    mx_initcolor();
    int max_y = 0;
    int max_x = 0;    
    getmaxyx(stdscr, max_y, max_x);
    int start[max_x];
    int lenght[max_x];
    int lenght2[max_x];
    int arr[max_x];
    int arr_del[max_x];

    for (int i = 0; i < max_x; i++) {
        start[i] = -1 * (rand() % 60);
        arr[i] = start[i];
        arr_del[i] = start[i];
        lenght[i] = (rand() % (50 - 10 + 1)) + 10;
        lenght2[i] = lenght[i];
    }

    int speed = 100;
    int color = 1;
    while (1) {
        for (int i = 0; i < max_x; i++) {      
            wchar_t random_char = (rand() % 93 + 33);
            if (i % 2 == 0) {
                random_char = ' ';
            }
            mvaddch(arr[i] + 1, i, random_char | COLOR_PAIR(7));      
            mvaddch(arr[i], i, random_char | COLOR_PAIR(color));
            mvaddch(arr[i] - lenght[i], i, ' ' | COLOR_PAIR(color));
            if (arr[i] != arr_del[i]) {
                mvaddch(arr_del[i] - lenght2[i], i, ' ' | COLOR_PAIR(color));
            }
            if (arr[i] > max_y) {
                start[i] = -1 * (rand() % 25);
                arr[i] = start[i];
                lenght[i] = (rand() % (50 - 5 + 1)) + 5;
            }
            if (arr_del[i] - lenght2[i] > max_y) {
                arr_del[i] = arr[i];
                lenght2[i] = lenght[i];
            }
            arr[i]++;
            arr_del[i]++;
        }

        usleep(1000 * speed);
        nodelay(stdscr,TRUE);
        noecho();
        char ch = getch();
        if (ch == 'q') {
	    clear();
	    break;
	}
	if (ch == '+') {
	    if (speed > 1) {
                if (speed <= 11)
                    speed--;
                else
                    speed -= 10;
            }
	} else if (ch == '-') {
	    if (speed < 300) {
                if (speed <= 10)
                    speed++;
                else
                    speed += 10;
           }
	} else if (ch == '1') {
	    color = 1;
	} else if (ch == '2') {
	    color = 2;
	} else if (ch == '3') {
	    color = 3;
	} else if (ch == '4') {
	    color = 4;
	} else if (ch == '5') {
	    color = 5;
	} else if (ch == '6') {
	    color = 6;
	} else if (ch == '7') {
	    color = 7;
	} else if (ch == '8') {
	    color = 8;
	}
        refresh();
    }
}


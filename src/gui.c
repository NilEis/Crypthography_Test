#include "gui.h"
#include <ncurses/ncurses.h>
#include <stdint.h>
#include <stdlib.h>
#include "helper_functions.h"
#include "asymmetric.h"
#include "prng.h"

#define MAIN_MENU_COLOUR 1
#define SELECTED_COLOUR 2
#define NORMAL_COLOUR 3

static const char* options[] = {"RSA ", "Lcg ", "Exit"};
static const int options_length = 3;

void main_menu();
void gui_rsa();
void gui_lcg();
void n_exit_program(int code);

void gui_init()
{
    initscr();
    start_color();
    init_pair(MAIN_MENU_COLOUR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECTED_COLOUR, COLOR_YELLOW, COLOR_WHITE);
    init_pair(NORMAL_COLOUR, COLOR_WHITE, COLOR_BLACK);
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    main_menu();
}

void main_menu()
{
    int i = 0;
    int h = 0;
    int ch = 0;
    int x_pos = (COLS/2)-5;
    int y_pos = (LINES/2)-3;
    for(;;)
    {
        i = 0;
        clear();
        wbkgd(stdscr,COLOR_PAIR(MAIN_MENU_COLOUR));
        mvaddch(y_pos,x_pos,ACS_ULCORNER);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_URCORNER);
        mvaddch(y_pos+1,x_pos,ACS_VLINE);
        printw("Options:");
        addch(ACS_VLINE);
        printw("\n");
        mvaddch(y_pos+2,x_pos,ACS_LTEE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_RTEE);
        while(i<options_length)
        {
            mvaddch(y_pos+3+i,x_pos,ACS_VLINE);
            printw(" ");
            if(i==h)
            {
                attron(COLOR_PAIR(SELECTED_COLOUR));
            }
            printw("-%s", options[i]);
            wbkgd(stdscr,COLOR_PAIR(MAIN_MENU_COLOUR));
            printw("  ");
            addch(ACS_VLINE);
            i++;
        }
        mvaddch(y_pos+3+i,x_pos,ACS_LLCORNER);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_HLINE);
        addch(ACS_LRCORNER);
        refresh();
        ch = getch();
        switch(ch)
        {
        case KEY_UP:
            h--;
            break;
        case KEY_DOWN:
            h++;
            break;
        case 10:
            switch(h)
            {
            case 0:
                clear();
                gui_rsa();
                break;
            case 1:
                clear();
                gui_lcg();
                break;
            case options_length-1:
                n_exit_program(0);
                break;
            }
            break;
        }
        h %= options_length;
        h -= (h == options_length)*(-1);
    }
}

void gui_rsa()
{
    uint32_t p = 0;
    uint32_t q = 0;
    uint32_t N = 0;
    uint32_t e = 0;
    uint32_t d = 0;
    int tested = 0;
    printw("Please input p and q: (p q):\n->");
    scanw("%u %u",&p,&q);
    tested = is_prime(p);
    if(tested==-1)
    {
        endwin();
        printf("p = %u is not a prime number\n", p);
        n_exit_program(-1);
    }
    tested = is_prime(q);
    if(tested==-1)
    {
        endwin();
        printf("q = %u is not a prime number\n", q);
        n_exit_program(-1);
    }
    get_RSA(p,q, &N, &e, &d);
    printw("\np = %u\nq = %u\nN = %u\ne = %d\nd = %u\n\n",p,q,N,e,d);
    printw("Press ENTER to enter the main menu");
    refresh();
    getch();
}

void gui_lcg()
{
    uint32_t _seed = 0;
    uint32_t _modulus = 0;
    int ch = 0;
    printw("Please enter a seed and the maximum value: ");
    scanw("%u %u", &_seed, &_modulus);
    lcg_seed(_seed);
    for(;;)
    {
        wclear(stdscr);
        printw("Linear congruential generator\n");
        printw("Pseudorandom number: %u\nPress the enter key to create another one (Exit with Esc)...\n", (lcg_rand()%_modulus));
        refresh();
        ch = getch();
        if(ch == 27)
        {
            return;
        }
        else if(ch == 10)
        {
            continue;
        }
        else
        {
            printw("Charcter pressed is = %d Hopefully it can be printed as '%c'\n", ch, ch);
            refresh();
            getch();
        }
    }
}

void n_exit_program(int code)
{
    clear();
    attron(COLOR_PAIR(NORMAL_COLOUR));
    printw("Press ENTER to exit program");
    getch();
    endwin();
    exit(code);
}

#include "gui.h"
#include <ncurses/ncurses.h>
#include <stdint.h>
#include <stdlib.h>
#include "helper_functions.h"
#include "asymmetric.h"

static const char* options[2] = {"RSA", "Exit"};
static const int options_length = 2;

void main_menu();
void gui_rsa();
void n_exit_program(int code);

void gui_init()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    main_menu();
}

void main_menu()
{
    int i = 0;
    int h = 0;
    int ch = 0;
    for(;;)
    {
        i = 0;
        clear();
        standend();
        printw("Options:\n");
        while(i<options_length)
        {
            if(i==h)
            {
                attron(A_STANDOUT);
            }
            else
            {
                standend();
            }
            printw(" -%s\n", options[i]);
            i++;
        }
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
                endwin();
                n_exit_program(0);
                break;
            }
            break;
        }
        h %= options_length;
    }
    attron(A_STANDOUT);
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
    refresh();
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

void n_exit_program(int code)
{
    clear();
    standend();
    printw("Press ENTER to exit program");
    getch();
    endwin();
    exit(code);
}

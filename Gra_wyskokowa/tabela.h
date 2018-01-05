#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



FILE *stream,*stream2, *stream3, *stream4,*stream5;
 struct WYNIK
{
	char nick[30];
	int wynik;
 };
void wczytaj(struct WYNIK TAB[11])
{
	
	errno_t err,err2;
	int n = 0, m = 0,p=0;
	err = fopen_s(&stream,"wyniki.txt", "r");
	
		int value=0;
		for(int i=0;i<10;i++)
		{
				fscanf_s(stream, "%i", &value);
				
				TAB[m].wynik = value;
				m++;
			

		}

		fclose(stream);

	
	err2 = fopen_s(&stream2, "nicki.txt", "r");
	
		char word[30];
		for (int j = 0; j<10; j++)
		{
			fgets(word, sizeof(word), stream2);
			
			/*for (int t = 0; t < 30; t++) {
			TAB[p].nick[t] = word[t];
			}
			//p++;*/
			strcpy_s(TAB[j].nick, sizeof(char[30]), word);
			

		}
	/*size_t bufsize = BUFSIZ;
	size_t b;
	if (stream2 != NULL)
	{
		char word[BUFSIZ];
		for (int i = 0; i < 10; i++)
		{
			char *start = word;
			char field;
			int n;
			//for (int h = 0;h<30;h++)
			//{


			 getline(&start,&bufsize, stream2);
				//sscanf_s(start, "%c%n", &field, &n,sizeof field,sizeof n);
				//start += field;

			//}
			printf("%s\n", word);
			//strcpy_s(TAB[i].nick, 30, word);
			
			printf("%s\n", TAB[i].nick);

		}


			
	}*/
		
fclose(stream2);




}


void wpisz(struct WYNIK *TAB,int *queue)
{
	errno_t err3,err4,err5;
	err3 = fopen_s(&stream3,"wyniki.txt", "w");

	
	for (int i = 0; i < 10; i++)
	{
		fprintf(stream3, "%i\n", TAB[queue[i]].wynik);
		
	}
	fclose(stream3);

	err4 = fopen_s(&stream4, "nicki.txt", "w");

	for (int i = 0; i < 10; i++)
	{
		fputs("                             \n", stream4);
		
	}
	fclose(stream4);
	err5 = fopen_s(&stream5, "nicki.txt", "w");
	for (int i = 0; i < 10; i++)
	{
		//fputs(TAB[queue[i]].nick, stream5);
		//fputs("\n", stream4);
		fprintf(stream5, "%s", TAB[queue[i]].nick);
		if (queue[i] == 10) {
			fprintf(stream5, "\n");
		}
	}
	fclose(stream5);
}
void NICK(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3,char nick[30])
{
	al_init();
	al_install_keyboard();
	//char nick[30]=" ";
	//nick[0] = ' ';
	char *letter;
	bool redraw;
	int ile =1;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 10);
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	al_clear_to_color(al_map_rgb(0, 127, 255));
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//scanf_s("%s",&nick);
		
		//fgets(nick, sizeof(nick), stdin);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			al_get_keyboard_state(&keyState);
			if (al_key_down(&keyState, ALLEGRO_KEY_ENTER)) {
				break;
			}
			else redraw = true;
			
			if (ile<25&&al_key_down(&keyState, ALLEGRO_KEY_Q)) {
				letter = "q";
				strncat_s(nick,30, letter,1);
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_W)) {
				letter = "w";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_E)) {
				letter = "e";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile < 25 && al_key_down(&keyState, ALLEGRO_KEY_R)) {
				letter = "r";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_T)) {
				letter = "t";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_Y)) {
				letter = "y";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile < 25 && al_key_down(&keyState, ALLEGRO_KEY_U)) {
				letter = "u";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			
		    if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_I)) {
					letter = "i";
					strncat_s(nick, 30, letter, 1);
					ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_O)) {
				letter = "o";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_P)) {
				letter = "p";
				strncat_s(nick, 30, letter, 1);
				ile++;
			}
		/*	if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_BACKSPACE)) {
				nick[ile-1] = ' ';
				
				ile--;
			}*/
		}
		
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if ((redraw==true)&&(al_is_event_queue_empty(event_queue))) {

			al_clear_to_color(al_map_rgb(0, 127, 255));
			al_draw_text(font3, al_map_rgb(0, 0, 0), 500, 330, ALLEGRO_ALIGN_CENTRE, "Wpisz nick:");
			al_draw_textf(font3, al_map_rgb(0, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "%s",nick);

			al_flip_display();
			redraw = false;
		}
	}
	al_destroy_timer(timer);
	al_uninstall_keyboard();

	al_destroy_event_queue(event_queue);
}
void sort(float liczba,ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{
	

	struct WYNIK TAB[11];
	wczytaj(TAB);
	if (liczba > TAB[9].wynik) {
		char nick[30]="";
		
		NICK(display, font3,nick);
		TAB[10].wynik = (int)(liczba*10);
		
		//char word[31] = "xxx";

		strcpy_s(TAB[10].nick, sizeof(char[30]), nick);
		int value = 0;
		int queue[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
		int i, j;
		for (i = 0; i < 10; i++)
		{

			for (j = 0; j < 10 - i; j++)
			{
				if (TAB[queue[j]].wynik < TAB[queue[j + 1]].wynik)
				{
					value = queue[j + 1];
					queue[j + 1] = queue[j];
					queue[j] = value;

					//strcpy_s(word, sizeof word +1, TAB[j + 1].nick);
					///strcpy_s(TAB[j + 1].nick, sizeof(TAB[j + 1].nick)+1, TAB[j].nick);
					//strcpy_s(TAB[j ].nick, sizeof(TAB[j + 1].nick)+1, word);
				}


			}
		}

		wpisz(TAB, queue);
	
	}

}
void TABELA(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{
	struct WYNIK TAB[11];
	wczytaj(TAB);
	al_init();
	al_install_keyboard();
	bool redraw;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 10);
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	al_clear_to_color(al_map_rgb(0, 127, 255));
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);



		if (ev.type == ALLEGRO_EVENT_TIMER) {
			al_get_keyboard_state(&keyState);
			if (al_key_down(&keyState, ALLEGRO_KEY_ENTER)) {
				break;
			}
			
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if ((al_is_event_queue_empty(event_queue))) {

			al_clear_to_color(al_map_rgb(0, 127, 255));
			al_draw_text(font3, al_map_rgb(0, 0, 0), 300, 70, ALLEGRO_ALIGN_CENTRE, "NR");
			al_draw_text(font3, al_map_rgb(0, 0, 0), 400, 70, ALLEGRO_ALIGN_CENTRE, "PUNKTY");
			al_draw_text(font3, al_map_rgb(0, 0, 0), 500, 70, ALLEGRO_ALIGN_CENTRE, "NICK");
			for (int i = 0; i< 10; i++) {
				
				al_draw_textf(font3, al_map_rgb(0, 0, 0), 300, 100 + 60 * i, ALLEGRO_ALIGN_CENTRE, "%i.",i + 1);
				al_draw_textf(font3, al_map_rgb(0, 0, 0), 400, 100 + 60 * i, ALLEGRO_ALIGN_CENTRE, "%3.1f  ",(float)(TAB[i].wynik)/10);
			//	al_draw_textf(font3, al_map_rgb(0, 0, 0), 500, 100+60*i, ALLEGRO_ALIGN_CENTRE,"%s",  TAB[i].nick);
				
				for (int j = 0; j < strlen(TAB[i].nick)-1; j++)
				{
					al_draw_textf(font3, al_map_rgb(0, 0, 0), 485+j*12, 100 + 60 * i, ALLEGRO_ALIGN_CENTRE, "%c", TAB[i].nick[j]);
				}
			}
			al_flip_display();
			
		}
	}
	al_destroy_timer(timer);
	al_uninstall_keyboard();

	al_destroy_event_queue(event_queue);
	
}
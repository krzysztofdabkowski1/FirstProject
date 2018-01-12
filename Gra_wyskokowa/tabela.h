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
				//(TAB+i)->wynik = value;
		}		
				

		

		fclose(stream);
printf("%i ", TAB[0].wynik);
	
	err2 = fopen_s(&stream2, "nicki.txt", "r");
	
		char word[30];
		for (int j = 0; j<10; j++)
		{
			fgets(word, sizeof(word), stream2);
			
			//for (unsigned int t = 0; t < strlen(word); t++) {
			//TAB[j].nick[t] = word[t];
	
			//}
			
			strcpy_s(TAB[j].nick, sizeof(char[30]), word);
		}
	
		
fclose(stream2);




}


void wpisz(struct WYNIK *TAB,int *queue,int ile)
{
	errno_t err3,err4,err5;
	err3 = fopen_s(&stream3,"wyniki.txt", "w");

	
	for (int i = 0; i < 10; i++)
	{
		fprintf(stream3, "%i\n", TAB[queue[i]].wynik);
		
	}
	fclose(stream3);
	err5 = fopen_s(&stream5, "nicki.txt", "w");
	for (int i = 0; i < 10; i++)
	{
		if (queue[i] != 10) {
			
		fprintf(stream5, "%s", TAB[queue[i]].nick);
		}
		else
		{
			for (int j = 0; j < ile; j++)
			{
				fprintf(stream5, "%c", TAB[queue[i]].nick[j]);
			}
			fprintf(stream5, "\n");

		}
	}
	fclose(stream5);
}
int NICK(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3,char *nick)
{
	al_init();
	al_install_keyboard();
	//char nick[30]=" ";
	nick[0] = '_';
	bool redraw;
	int ile =0;
	int time = 0;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 6);
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
				nick[ile] = 'q';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_W)) {
				nick[ile] ='w';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_E)) {
				nick[ile] = 'e';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile < 25 && al_key_down(&keyState, ALLEGRO_KEY_R)) {
				nick[ile] = 'r';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_T)) {
				nick[ile] = 't';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_Y)) {
				nick[ile] = 'y';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile < 25 && al_key_down(&keyState, ALLEGRO_KEY_U)) {
				nick[ile] = 'u';
				nick[ile + 1] = '_';
				ile++;
			}
			
		    if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_I)) {
				nick[ile] = 'i';
				nick[ile + 1] = '_';
					ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_O)) {
				nick[ile] = 'o';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_P)) {
				nick[ile] = 'p';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_A)) {
				nick[ile] = 'a';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_B)) {
				nick[ile] = 'b';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_C)) {
				nick[ile] = 'c';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_S)) {
				nick[ile] = 's';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_D)) {
				nick[ile] = 'd';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_F)) {
				nick[ile] = 'f';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_G)) {
				nick[ile] = 'g';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_H)) {
				nick[ile] = 'h';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_J)) {
				nick[ile] = 'j';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_K)) {
				nick[ile] = 'k';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_L)) {
				nick[ile] = 'l';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_Z)) {
				nick[ile] = 'z';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_X)) {
				nick[ile] = 'x';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_V)) {
				nick[ile] = 'v';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_N)) {
				nick[ile] = 'n';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_M)) {
				nick[ile] = 'm';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile<25 && al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
				nick[ile] = ' ';
				nick[ile + 1] = '_';
				ile++;
			}
			if (ile>0&&ile<25 && al_key_down(&keyState, ALLEGRO_KEY_BACKSPACE)) {
				nick[ile] = ' ';
				nick[ile - 1] = '_';
				
				ile--;
			}
			nick[ile + 1] =NULL;
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
	return ile;
}
void sort(float liczba, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{

	int ile;
	struct WYNIK TAB[11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			TAB[i].nick[j] = ' ';
		}
	}
	wczytaj(TAB);
	if (liczba * 10 > TAB[9].wynik) {
		char nick[30] ;

		ile=NICK(display, font3, nick);
		TAB[10].wynik = (int)(liczba * 10);
		printf("%s\n", nick);
		//char word[31] = "xxx";

		//strcpy_s((TAB+10)->nick, sizeof(char[30]), nick);
		for (int i = 0; i < ile; i++)
		{
			TAB[10].nick[i] = nick[i];
		}
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

		wpisz(TAB, queue,ile);

	}
	
}
void TABELA(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{
	struct WYNIK TAB[11];
	//TAB->wynik = 0;
	wczytaj(TAB);
	al_init();
	al_install_keyboard();
	printf("%i", TAB->wynik);
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
			al_draw_text(font3, al_map_rgb(0, 0, 0), 600, 70, ALLEGRO_ALIGN_CENTRE, "NICK");
			for (int i = 0; i< 10; i++) {
				
				al_draw_textf(font3, al_map_rgb(0, 0, 0), 300, 100 + 60 * i, ALLEGRO_ALIGN_CENTRE, "%i.",i + 1);
				al_draw_textf(font3, al_map_rgb(0, 0, 0), 400, 100 + 60 * i, ALLEGRO_ALIGN_CENTRE, "%3.1f  ",(float)(TAB[i].wynik)/10);
				//al_draw_textf(font3, al_map_rgb(0, 0, 0), 600, 100+60*i, ALLEGRO_ALIGN_CENTRE,"%s",  TAB[i].nick);
				for (int j = 0; j < strlen(TAB[i].nick)-1; j++)
				{
					al_draw_textf(font3, al_map_rgb(0, 0, 0), 600+11*j, 100 + 60 * i, ALLEGRO_ALIGN_CENTER, "%c", TAB[i].nick[j]);
				 }
	
			}
			al_flip_display();
			
		}
	}
	al_destroy_timer(timer);
	al_uninstall_keyboard();

	al_destroy_event_queue(event_queue);
	
}
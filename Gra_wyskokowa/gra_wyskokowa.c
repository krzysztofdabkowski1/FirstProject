#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "graj.c"
#include "tabela.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
//const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 700;

int main()
{
	al_init();
	al_init_font_addon(); 
	al_init_ttf_addon();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY * display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 32, 0),*font2=al_load_ttf_font("arial.ttf",66,0), *font3= al_load_ttf_font("arial.ttf", 20, 0);
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *kursor = al_create_bitmap(0,0);
	float kursor_x = 500;
	float kursor_y = 350;
	bool redraw = true;
	bool on = true;
	bool helpON = false;
	bool authorON = false;
	float a=0,b=0;
	int t = 0;
	timer = al_create_timer(1.0 / 60);
	al_install_mouse();
    al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(kursor);
	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	al_flip_display();

	al_start_timer(timer);
	al_set_window_title(display, "gra wyskokowa");
	while (on)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			kursor_x= ev.mouse.x;
			kursor_y=ev.mouse.y;
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN&&(kursor_x > 470 && kursor_x< 530 && kursor_y>350 && kursor_y < 400))
		{
			redraw = true;
			for (int i = 0; i < 2; i++) {
				b= graj(display, font3);
				a = a + b;
				if (b == -1) {
					a = -1;
					i =1;
				}
			}
			
			
			
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (kursor_x > 450 && kursor_x < 550 && kursor_y>550 && kursor_y < 600)&&authorON==false&&helpON==false)
		{

			on = false;
		}

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (kursor_x > 320 && kursor_x< 680 && kursor_y>400 && kursor_y < 450) && authorON == false && helpON==false)
		{
			redraw = true;
			TABELA(display, font3);

		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (kursor_x > 450 && kursor_x < 550 && kursor_y>450 && kursor_y < 500) && authorON == false)
		{
			helpON = true;
			ev.type = ALLEGRO_EVENT_MOUSE_BUTTON_UP;
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && helpON==true)
		{
			helpON = false;
		}

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (kursor_x > 430 && kursor_x < 570 && kursor_y>500 && kursor_y < 550)&& helpON==false)
		{
			authorON = true;
			ev.type = ALLEGRO_EVENT_MOUSE_BUTTON_UP;
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && authorON == true)
		{
			authorON = false;
			ev.type = ALLEGRO_EVENT_MOUSE_BUTTON_UP;
		}
		
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 127, 255));
			if (a == 0&&helpON==false && authorON == false) {
				al_draw_text(font2, al_map_rgb(0, 0, 0), 500, 100, ALLEGRO_ALIGN_CENTRE, "GRA WYSKOKOWA");
				if (kursor_x > 470 && kursor_x < 530 && kursor_y>350 && kursor_y < 400)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "Graj");
				}
				else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "Graj");

				if (kursor_x > 320 && kursor_x < 680 && kursor_y>400 && kursor_y < 450)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 500, 400, ALLEGRO_ALIGN_CENTRE, "Tabela najlepszych wynikow");
				}
				else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 400, ALLEGRO_ALIGN_CENTRE, "Tabela najlepszych wynikow");

				if (kursor_x > 450 && kursor_x < 550 && kursor_y>450 && kursor_y < 500)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 500, 450, ALLEGRO_ALIGN_CENTRE, "Pomoc");
				}
				else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 450, ALLEGRO_ALIGN_CENTRE, "Pomoc");

				if (kursor_x > 430 && kursor_x < 570 && kursor_y>500 && kursor_y < 550)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 500, 500, ALLEGRO_ALIGN_CENTRE, "O autorze");
				}
				else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 500, ALLEGRO_ALIGN_CENTRE, "O autorze");

				if (kursor_x > 450 && kursor_x < 550 && kursor_y>550 && kursor_y < 600)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 500, 550, ALLEGRO_ALIGN_CENTRE, "Wyjdz");
				}
				else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 550, ALLEGRO_ALIGN_CENTRE, "Wyjdz");
			}
			else if(a!=-1&&helpON==false && authorON == false){
				al_draw_textf(font2, al_map_rgb(0, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "%3.1f", a);
				t++;
				if (t == 120) {
					
                    sort(a, display, font3);
					a = 0;
					t = 0;
					
				}
			}
			else if (helpON==true && authorON == false)
			{
				al_clear_to_color(al_map_rgb(0, 127, 255));
				al_flip_display();
			}
			else if (authorON == true && helpON == false)
			{
				al_clear_to_color(al_map_rgb(0, 127, 255));
				al_flip_display();
			}
			else a = 0;
			al_flip_display();
		}
	}
	
	
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_font(font3);
	al_destroy_bitmap(kursor);
    al_destroy_display(display);
	return 0;
}



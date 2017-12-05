#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
const float FPS = 60;
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
	int a;
	timer = al_create_timer(1.0 / FPS);
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
			on = false;
			a=graj(display,font3);
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 127, 255));
			al_draw_text(font2, al_map_rgb(0, 0, 0), 500, 100, ALLEGRO_ALIGN_CENTRE, "GRA WYSKOKOWA");
			if (kursor_x > 470 && kursor_x< 530 && kursor_y>350 && kursor_y < 400)
			{
				al_draw_text(font, al_map_rgb(255, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "Graj");
			}
		    else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "Graj");
				
			if (kursor_x > 320 && kursor_x < 680 && kursor_y>400 && kursor_y < 450)
		    {
			    al_draw_text(font, al_map_rgb(255, 0, 0), 500, 400, ALLEGRO_ALIGN_CENTRE, "Tabela najlepszych wyników");
		    }
			else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 400, ALLEGRO_ALIGN_CENTRE, "Tabela najlepszych wyników");
			
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
			else al_draw_text(font, al_map_rgb(0, 0, 0), 500, 550, ALLEGRO_ALIGN_CENTRE,"Wyjdz");
			al_flip_display();
		}
	}
	system("pause");
	
	al_destroy_event_queue(event_queue);
    al_destroy_display(display);
	return 0;
}
double angle(float *line,int i)
{
	double angle=0;
	//if ((line[2 * i + 1] - line[2 * (i+2) + 1] - 15) / (line[2 * i] - line[2 * ( i+2)]) < (3.14))
	//{
		 angle = atan((line[6 * i + 1] - line[6 * (i+4) + 1]) / (line[6 * i] - line[6 * (i+4)]));
	//}
		 printf("%f\n", angle);
	//if (angle > 0) angle = -angle;
	return angle;
}
int graj(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{
	int x=1000, y=150;
	int i = 0,t=0;
	int start=0;
	double ANGLE=0;
	al_init_image_addon();
	ALLEGRO_BITMAP *jumper = al_load_bitmap("jumping-ski.png");
	ALLEGRO_BITMAP *player = al_load_bitmap("skiing.png");
	ALLEGRO_BITMAP *player2 = al_load_bitmap("skiing2.png");
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue2 = NULL;
	bool redraw = true;
	int etap = 0, tak=0;
	float array[8] = { 1000,230,900,300,800,370,670,385 };
	float array2[8] = {1000,350,450,375,370,620,0,650};
	float dest2[240];
	float dest3[8]; 
	float dest4[8];
	float dest5[8];
	float line[1000];
	float line2[1000];
	
	al_calculate_spline(line, 8, array, 0.5,100);
	al_calculate_spline(dest2, 8, array2, 0.5, 60);
	al_calculate_spline(line2, 8, array2, 0.5, 100);

	dest2[0] = 0;
	dest2[1] = 700;
	dest2[2] = 1000;
	dest2[3] = 700;
	dest2[4] = 1000;
	dest2[5] = 350;

	dest3[0] = 990;
	dest3[1] = 360;
	dest3[2] = 990;
	dest3[3] = 238;
	dest3[4] = 970;
	dest3[5] = 250;
	dest3[6] = 970;
	dest3[7] = 370;

    dest4[0] = 900;
	dest4[1] = 360;
	dest4[2] = 900;
	dest4[3] = 298;
	dest4[4] = 880;
	dest4[5] = 310;
	dest4[6] = 880;
	dest4[7] = 360;
	
	dest5[0] = 720;
	dest5[1] = 450;
	dest5[2] = 720;
	dest5[3] = 375;
	dest5[4] = 700;
	dest5[5] = 380;
	dest5[6] = 700;
	dest5[7] = 450;
	
	al_clear_to_color(al_map_rgb(0, 127, 255));
	//al_set_target_bitmap(jumper);
//	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_set_target_bitmap(al_get_backbuffer(display));
	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_display_event_source(display));
	al_register_event_source(event_queue2, al_get_timer_event_source(timer));
	al_start_timer(timer);
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue2, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (etap==0) 
			{
				redraw = true;
				x = line[6 * i];
				y = line[6 * i + 1] - 9;
				if(ANGLE = angle(line, i)<=0) ANGLE = angle(line,i);

				
				if (x <= 670)
				{
					etap = 1;
				}
				i++;
				
				

		    }
			
		    if(etap==1){
				redraw = true;
				x = x - 8 + t / 16;
				y = y + t / 7;
				t++;
				for (int i = 0; i < 400; i=i+2)
				{
					if ((line2[i] > x)&&(line2[i] < x + 10))
					{
						if ((line2[i + 1] > y)&&(line2[i + 1] < y + 10))
						{
						//	printf("detection");
							//printf(" %i , %i , %f , %f,%i", x, y, line2[i], line2[i + 1],i);
							tak = i;
							etap = 2;
							t = 0;
		
							
						}
					}
				}
				
			}
			if (etap == 2)
			{
				redraw = true;
					if (x>0)
					{
						x = line2[tak+2*start];
						y = line2[tak + 1+2*start]-10;
						ANGLE = angle(line2, tak+2 * start);
						if (floor(0.07*t) <= 2)
						{
							start = start + 2-floor(0.07*t);
							
						}
						//printf("%i, %i\n",x, y);
						
                     t++;
					}
					

				
				
			}
		}
		
		//printf("%f\n", line2[i]);

		
		    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
		    }
			if (redraw && al_is_event_queue_empty(event_queue2)) {
				redraw = false;
				al_clear_to_color(al_map_rgb(0, 127, 255));
				if (etap==1/*x > 0 && y < 700*/) {
					al_draw_rotated_bitmap(jumper,32,22,x, y,7.5*3.14/4, 0);
				}
				if (etap == 0) {
					al_convert_mask_to_alpha(player, al_map_rgb(255, 255, 255));
					al_draw_rotated_bitmap(player, 32, 22, x, y, ANGLE/*7.5*3.14 / 4*/, 0);
				}
				if (etap == 2) {
					al_convert_mask_to_alpha(player2, al_map_rgb(255, 255, 255));
					al_draw_rotated_bitmap(player2, 32, 22, x, y,ANGLE /*7.5*3.14 / 4*/, 0);
				}
				al_draw_spline(array2, al_map_rgb(255, 255, 255), 2);
				al_draw_spline(array, al_map_rgb(255, 255, 255), 4);
				al_draw_filled_polygon(dest2, 120, al_map_rgb(255, 255, 255));

				al_draw_filled_polygon(dest3, 4, al_map_rgb(255, 255, 255));
				al_draw_filled_polygon(dest4, 4, al_map_rgb(255, 255, 255));
				al_draw_filled_polygon(dest5, 4, al_map_rgb(255, 255, 255));
				al_draw_filled_rectangle(10, 10, 150, 40, al_map_rgb(0, 100, 0));
				al_draw_filled_rectangle(900, 10, 990, 40, al_map_rgb(110, 100, 110));
				al_draw_filled_rectangle(211, 601, 215, 605, al_map_rgb(255, 0, 0));
				al_draw_filled_rectangle(277, 575, 281, 579, al_map_rgb(0, 255, 0));
				al_draw_text(font3, al_map_rgb(255, 0, 0), 15, 20, ALLEGRO_ALIGN_LEFT, "tu bedzie kiedys predkosc wiatru");
				al_draw_text(font3, al_map_rgb(255, 0, 0), 905, 20, ALLEGRO_ALIGN_CENTRE, "5 sekund na start");
				al_flip_display();
			}

			

		}


	
	
		al_destroy_event_queue(event_queue2);
		al_destroy_bitmap(jumper);
	return 0;
	
}
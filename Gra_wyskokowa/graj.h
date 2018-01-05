


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

const float FPS = 60;



double angle(float *line, int i)
{
	double angle = 0;
	//if ((line[2 * i + 1] - line[2 * (i+2) + 1] - 15) / (line[2 * i] - line[2 * ( i+2)]) < (3.14))
	//{
	angle = atan((line[6 * i + 1] - line[6 * (i + 5) + 1]) / (line[6 * i] - line[6 * (i + 5)]));
	//}

	//if (angle > 0) angle = -angle;
	return angle;
}
double angle2(float *line, int i, int tak)
{
	double angle = 0;

	angle = atan((line[tak + 2 * i + 1] - line[tak + 2 * (i + 8) + 1]) / (line[tak + 2 * i] - line[tak + 2 * (i + 8)]));

	return angle;
}


void RAND(float* wind) {

	srand(time(NULL));
	wind[0] = rand() % 30;

	if ((int)wind[0] % 2 != 0) wind[0] = wind[0] + 1;
	wind[0] = wind[0] / 10;
	if (rand() % 10 > 5) wind[0] = -wind[0];
	for (int i = 1; i < 6; i++) {

		if (rand() % 10 < 5 && wind[i - 1] != 3.0) wind[i] = wind[i - 1] + 0.2;
		else if (wind[i - 1] != -3.0) wind[i] = wind[i - 1] - 0.2;
		else wind[i] = wind[i - 1] + 0.2;
	}

}
void OCENY(float *oceny, double EDGE, float lad, bool upadek) {
	float start = 0, end = 0;
	if (lad == 0)
	{
		if (EDGE == 2.5) {
			start = 0;
			end = 3;
		}
		if (EDGE == 1.5) {
			start = 2;
			end = 5;
		}
		if (EDGE == 1)
		{
			start = 4;
			end = 8;
		}
		if (EDGE == 0)
		{
			start = 7;
			end = 10;
		}
		if (EDGE == -1)
		{
			start = 9;
			end = 12;
		}
	}
	else {
		if (EDGE == 2.5)
		{
			start = 10;
			end = 13;
		}
		if (EDGE == 1.5)
		{
			start = 12;
			end = 14;
		}
		if (EDGE == 1)
		{
			start = 13;
			end = 15;
		}
		if (EDGE == 0)
		{
			start = 16;
			end = 18;
		}

		if (EDGE == 0 && lad == 2) {
			start = 16;
			end = 18;
		}
		if (EDGE == 0 && lad == 3)
		{
			start = 17;
			end = 19;
		}
		if (EDGE == -1) {
			start = 18;
			end = 19.5;
		}
		if (EDGE == -1 && lad == 2) {
			start = 18.5;
			end = 20;
		}
		if (EDGE == -1 && lad == 3) {
			start = 19.4;
			end = 20;
		}
	}
	srand(time(NULL));
	int pomoc;
	for (int i = 0; i < 5; i++) {

		pomoc = 10 * start + rand() % (int)(10 * end - 10 * start);
		oceny[i] = pomoc / 10;

		if (pomoc - (pomoc / 10) * 10 <= 5) oceny[i] = floor(oceny[i]) + 0.5;
		//if (oceny[i] - floor(oceny[i]) < 0.5) oceny[i] = floor(oceny[i]) + 0.5;
		else oceny[i] = oceny[i] + 1.0;
	}
}
float graj(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font3)
{
	int x = 1000, y = 220;
	int i = 0, j = 0, t = 0, t1 = 0, t2 = 0, t3 = 0, t5 = 0, z, k;
	int start = 0, start2 = 0;
	double ANGLE = -0.52;
	double ANGLE2 = 5.8875;
	double ANGLE3 = 0;
	double EDGE = 2.5;
	double balance = 0;
	double LONG = 0;
	float WIND = 0;
	float wind[6];
	float oceny[5];
	float suma;
	bool EDGE_DOWN = false;
	al_init_image_addon();
	al_install_keyboard();

	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_BITMAP *niebo = al_load_bitmap("niebo.jpg");
	ALLEGRO_BITMAP *jumper = al_load_bitmap("jumping-ski.png");
	ALLEGRO_BITMAP *jumper2 = al_load_bitmap("jumping-ski2.png");
	ALLEGRO_BITMAP *player = al_load_bitmap("skiing.png");
	ALLEGRO_BITMAP *player2 = al_load_bitmap("skiing2.png");
	ALLEGRO_BITMAP *player3 = al_load_bitmap("skiing3.png");
	ALLEGRO_BITMAP *player4 = al_load_bitmap("skiing4.png");
	ALLEGRO_BITMAP *player5 = al_load_bitmap("skiing5.png");
	ALLEGRO_BITMAP *player6 = al_load_bitmap("skiing6.png");
	ALLEGRO_BITMAP *player7 = al_load_bitmap("skiing7.png");
	ALLEGRO_BITMAP *time = al_load_bitmap("time.png");
	ALLEGRO_BITMAP *time2 = al_load_bitmap("time2.png");
	ALLEGRO_BITMAP *plus = al_load_bitmap("plus.png");
	ALLEGRO_BITMAP *minus = al_load_bitmap("minus.png");
	ALLEGRO_BITMAP *narty = al_load_bitmap("narty.png");

	ALLEGRO_BITMAP *pol = al_load_bitmap("pol.png");
	ALLEGRO_BITMAP *ger = al_load_bitmap("ger.png");
	ALLEGRO_BITMAP *slo = al_load_bitmap("slo.png");
	ALLEGRO_BITMAP *swe = al_load_bitmap("swe.png");
	ALLEGRO_BITMAP *aus = al_load_bitmap("aus.png");

	ALLEGRO_BITMAP *smutnazaba = al_load_bitmap("smutnazaba.jpg");

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue2 = NULL;
	bool redraw = true;
	bool stop_ride = false;
	bool end = false;
	bool key[3] = { false,false,false };
	bool upadek = true;
	bool blisko = false;
	bool lad_down = false;
	int lad = 0;
	int etap = -1, tak = 0;
	float array[8] = { 1000,230,900,300,820,370,670,385 };
	float array2[8] = { 1000,350,450,375,370,620,0,650 };
	float dest2[240];
	float dest3[8];
	float dest4[8];
	float dest5[8];
	float line[1000];
	float line2[1000];

	al_calculate_spline(line, 8, array, 0.5, 88);
	al_calculate_spline(dest2, 8, array2, 0.5, 60);
	al_calculate_spline(line2, 8, array2, 0.5, 200);

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

	float belka[12] = { 993,220,  993,224, 995,224, 995,231, 998,229, 998,220 };
	al_clear_to_color(al_map_rgb(0, 127, 255));
	//al_set_target_bitmap(jumper);
	//	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_set_target_bitmap(al_get_backbuffer(display));

	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_display_event_source(display));
	al_register_event_source(event_queue2, al_get_timer_event_source(timer));
	al_register_event_source(event_queue2, al_get_keyboard_event_source());
	al_start_timer(timer);



	RAND(wind);
	WIND = wind[0];

	end = false;
	while (!end)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue2, &ev);


		if (ev.type == ALLEGRO_EVENT_TIMER) {

			al_get_keyboard_state(&keyState);

			if (x == 1000)
			{
				redraw = true;
				if (t1 >= 60) WIND = wind[1];
				if (t1 >= 120) WIND = wind[2];
				if (t1 >= 180) WIND = wind[3];
				if (t1 >= 240) WIND = wind[4];
				if (t1 >= 300) WIND = wind[5];
				t1++;
			}
			if (x == 1000 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && t1 <= 300) {
				redraw = true;
				etap = 0;
			}

			if (etap == 0)
			{
				redraw = true;
				x = line[6 * i];
				y = line[6 * i + 1] - 9;
				if (angle(line, i) <= 0) ANGLE = angle(line, i);


				if (x <= 670)
				{
					etap = 1;
				}
				i++;



			}
			if (x >= 705 && x <= 715 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && EDGE_DOWN == false) {

				EDGE = 1.5;
				EDGE_DOWN = true;
			}
			if (x >= 695 && x < 705 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && EDGE_DOWN == false) {

				EDGE = 1;
				EDGE_DOWN = true;
			}
			if (x >= 680 && x < 695 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && EDGE_DOWN == false) {

				EDGE = 0;
				EDGE_DOWN = true;
			}
			if (x >= 670 && x < 680 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && EDGE_DOWN == false) {

				EDGE = -1;
				EDGE_DOWN = true;
			}
			if (etap == 1) {
				redraw = true;
				balance = -0.5;
				if (ANGLE2 > 5.95 || ANGLE2 < 5.75) balance = 0.4;
				//EDGE = -1;
				// WIND = 3.0;

				x = x - 8 + (t / 15) + (balance)-t * WIND / 180; ////8 //15
				y = y + (t / 6) + EDGE;    ///(t/6)
				t++;
				//printf("%f\n", balance);
				for (int i = 0; i < 800; i = i + 2)
				{
					if ((line2[i] > x) && (line2[i] < x + 7))
					{
						if ((line2[i + 1] > y) && (line2[i + 1] < y + 7))
						{

							tak = i;
							etap = 2;
							LONG = x;

							LONG = (((1000 - LONG) - 366) / 3 - 13.7);
							if (LONG - floor(LONG) < 0.5) LONG = floor(LONG) + 0.5;
							else LONG = ceil(LONG);


							t = 0;
						}
						if (y >= line2[i + 1] - 25 && y < line2[i + 1] - 15 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && lad_down == false) {
							upadek = false;
							lad_down = true;
							lad = 1;
						}
						if (y >= line2[i + 1] - 15 && y < line2[i + 1] - 10 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && lad_down == false) {
							upadek = false;
							lad_down = true;
							lad = 2;
						}
						if (y >= line2[i + 1] - 10 && al_key_down(&keyState, ALLEGRO_KEY_SPACE) && lad_down == false) {
							upadek = false;
							lad_down = true;
							lad = 3;
						}
						if (x<500 && y > line2[i + 1] - 25) blisko = true;
						if (ANGLE2 > 6.3 || ANGLE2 < 5.5)
						{
							upadek = true;
							lad = 0;
						}
					}
				}

			}
			if (etap == 1 && al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
				ANGLE2 = ANGLE2 - 0.05;
			}
			if (etap == 1 && al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
				ANGLE2 = ANGLE2 + 0.05;
			}
			if (etap == 1)
			{
				ANGLE2 = ANGLE2 + 0.001*t3 + WIND / 200;
				t3++;
			}
			if (etap == 2)
			{
				redraw = true;
				if (x > 0)
				{
					x = line2[tak + 2 * start];
					y = line2[tak + 1 + 2 * start] - 8;
					z = line2[tak + 20 + 2 * start2];
					k = line2[tak + 20 + 1 + 2 * start2] - 8;
					ANGLE = angle2(line2, start, tak);
					ANGLE3 = angle2(line2, start2, tak);
					if (floor(0.1*t) <= 3)
					{
						if (x > 98) start = start + 3;
						else start = start + 3 - floor(0.1*t);
						if (x > 100) start2 = start2 + 5;
						else start2 = start2 + 3 - floor(0.001*t);

					}
					else stop_ride = true;
					//printf("%i, %i\n",x, y);

					t++;
				}




			}
		}





		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (redraw && al_is_event_queue_empty(event_queue2)) {
			redraw = false;
			al_draw_bitmap(niebo, 0, 0, 0);
			//	al_clear_to_color(al_map_rgb(0, 127, 255));
			if (etap == -1) {

				al_convert_mask_to_alpha(player7, al_map_rgb(255, 255, 255));
				al_draw_rotated_bitmap(player7, 32, 22, x, y - 8, -0.55, 0);

			}

			if (etap == 0) {
				if (x < 680) {
					al_convert_mask_to_alpha(player5, al_map_rgb(255, 255, 255));
					al_draw_rotated_bitmap(player5, 32, 22, x, y - 8, ANGLE, 0);
				}
				else
				{
					al_convert_mask_to_alpha(player, al_map_rgb(255, 255, 255));
					al_draw_rotated_bitmap(player, 32, 22, x, y, ANGLE, 0);
				}
			}
			if (etap == 1) {
				if (blisko == false) {
					if (x > 640) {
						al_convert_mask_to_alpha(jumper, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(jumper, 32, 22, x, y, ANGLE2, 0);
					}
					else {
						if (ANGLE2 >= 5.75) {
							al_convert_mask_to_alpha(jumper2, al_map_rgb(255, 255, 255));
							al_draw_rotated_bitmap(jumper2, 32, 22, x, y, ANGLE2, 0);
						}
						else
						{
							al_convert_mask_to_alpha(jumper, al_map_rgb(255, 255, 255));
							al_draw_rotated_bitmap(jumper, 32, 22, x, y, ANGLE2, 0);
						}
					}
				}
				else
				{
					al_convert_mask_to_alpha(player5, al_map_rgb(255, 255, 255));
					al_draw_rotated_bitmap(player5, 32, 22, x, y, ANGLE2, 0);
				}
			}
			if (etap == 2) {


				if (upadek == false) {
					al_convert_mask_to_alpha(player2, al_map_rgb(255, 255, 255));
					if (stop_ride == false) al_draw_rotated_bitmap(player2, 32, 31, x, y, ANGLE, 0);
					else
					{
						al_convert_mask_to_alpha(player3, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(player3, 32, 30, x, y, ANGLE, 0);
						t2++;

					}
				}
				else
				{
					if (ANGLE2 <= 6.5) {
						al_convert_mask_to_alpha(player4, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(player4, 32, 31, x, y, ANGLE, 0);
						al_convert_mask_to_alpha(narty, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(narty, 32, 31, z, k, ANGLE3, 0);
					}
					else {
						al_convert_mask_to_alpha(player6, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(player6, 32, 31, x, y, ANGLE, 0);
						al_convert_mask_to_alpha(narty, al_map_rgb(255, 255, 255));
						al_draw_rotated_bitmap(narty, 32, 31, z, k, ANGLE3, 0);
					}
					if (stop_ride == true) t2++;

				}
			}

			al_draw_spline(array2, al_map_rgb(255, 255, 255), 2);
			al_draw_spline(array, al_map_rgb(255, 255, 255), 4);
			al_draw_filled_polygon(dest2, 120, al_map_rgb(255, 255, 255));

			al_draw_filled_polygon(dest3, 4, al_map_rgb(255, 255, 255));
			al_draw_filled_polygon(dest4, 4, al_map_rgb(255, 255, 255));
			al_draw_filled_polygon(dest5, 4, al_map_rgb(255, 255, 255));
			al_draw_filled_polygon(belka, 6, al_map_rgb(130, 82, 1));

			//al_draw_filled_rectangle(900, 10, 990, 40, al_map_rgb(110, 100, 110));
			al_draw_filled_rectangle(211, 601, 215, 605, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle(277, 575, 281, 579, al_map_rgb(0, 255, 0));
			al_draw_filled_rectangle(164, 617, 168, 621, al_map_rgb(0, 0, 255));


			if (WIND < 0) {
				al_draw_filled_rectangle(10, 10, 150, 40, al_map_rgb(80, 0, 0));
				al_draw_textf(font3, al_map_rgb(255, 0, 0), 65, 15, ALLEGRO_ALIGN_LEFT, "%1.1f", WIND);
				al_convert_mask_to_alpha(minus, al_map_rgb(255, 255, 255));
				al_draw_bitmap(minus, 17, 12, 0);
			}
			else if (WIND >= 0)
			{
				al_draw_filled_rectangle(10, 10, 150, 40, al_map_rgb(0, 100, 0));
				al_draw_textf(font3, al_map_rgb(0, 255, 0), 65, 15, ALLEGRO_ALIGN_LEFT, "%1.1f", WIND);
				al_convert_mask_to_alpha(plus, al_map_rgb(255, 255, 255));
				al_draw_bitmap(plus, 17, 12, 0);

			}


			if (t5 % 15 >= 0 && t5 % 15 <= 7 && t1>180 && etap == -1)
			{
				al_convert_mask_to_alpha(time2, al_map_rgb(255, 255, 255));
				al_draw_bitmap(time2, 880, 7, 0);
				al_draw_textf(font3, al_map_rgb(255, 230, 0), 935, 14, ALLEGRO_ALIGN_CENTRE, "%i s", 5 - t1 / 60);
				t5++;
			}
			else
			{
				al_convert_mask_to_alpha(time, al_map_rgb(255, 255, 255));
				al_draw_bitmap(time, 880, 7, 0);
				al_draw_textf(font3, al_map_rgb(255, 0, 0), 935, 14, ALLEGRO_ALIGN_CENTRE, "%i s", 5 - t1 / 60);
				t5++;
			}

			if (t1 > 300)
			{
				al_draw_text(font3, al_map_rgb(255, 0, 0), 500, 350, ALLEGRO_ALIGN_CENTRE, "koniec czasu");
				al_flip_display();
				t2++;
			}
			al_flip_display();
			if (t2 >= 60) end = true;
		}


	}
	if (t1 < 300) {
		al_clear_to_color(al_map_rgb(0, 127, 255));
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 500, 550, ALLEGRO_ALIGN_LEFT, "%1.1f m", LONG);

		OCENY(oceny, EDGE, lad, upadek);
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 150, 370, ALLEGRO_ALIGN_LEFT, "%1.1f", oceny[0]);
		al_draw_bitmap(pol, 120, 300, 0);
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 300, 370, ALLEGRO_ALIGN_LEFT, "%1.1f", oceny[1]);
		al_draw_bitmap(aus, 270, 300, 0);
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 450, 370, ALLEGRO_ALIGN_LEFT, "%1.1f", oceny[2]);
		al_draw_bitmap(ger, 420, 300, 0);
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 600, 370, ALLEGRO_ALIGN_LEFT, "%1.1f", oceny[3]);
		al_draw_bitmap(swe, 570, 300, 0);
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 750, 370, ALLEGRO_ALIGN_LEFT, "%1.1f", oceny[4]);
		al_draw_bitmap(slo, 720, 300, 0);
		suma = oceny[0] + oceny[1] + oceny[2] + oceny[3] + oceny[4] + LONG;
		al_draw_textf(font3, al_map_rgb(255, 0, 0), 800, 550, ALLEGRO_ALIGN_LEFT, "RAZEM: %1.1f", suma);
		al_draw_rounded_rectangle(100, 280, 840, 400, 1, 1, al_map_rgb(255, 0, 0), 5);

	}
	else {
		suma = -1;
		al_clear_to_color(al_map_rgb(0, 127, 255));
		al_draw_bitmap(smutnazaba, 0, 100, 0);
		al_draw_text(font3, al_map_rgb(255, 00, 0), 700, 400, ALLEGRO_ALIGN_LEFT, "DYSKWALIFIKACJA");
	}
	al_flip_display();
	al_rest(2.0);
	al_destroy_timer(timer);
	al_uninstall_keyboard();

	al_destroy_event_queue(event_queue2);
	al_destroy_bitmap(niebo);
	al_destroy_bitmap(jumper);
	al_destroy_bitmap(player);
	al_destroy_bitmap(player2);
	al_destroy_bitmap(player3);
	al_destroy_bitmap(player4);
	al_destroy_bitmap(player6);
	al_destroy_bitmap(player7);
	al_destroy_bitmap(time);
	al_destroy_bitmap(time2);
	al_destroy_bitmap(plus);
	al_destroy_bitmap(minus);
	al_destroy_bitmap(narty);
	al_destroy_bitmap(pol);
	al_destroy_bitmap(ger);
	al_destroy_bitmap(slo);
	al_destroy_bitmap(swe);
	al_destroy_bitmap(aus);
	al_destroy_bitmap(smutnazaba);

	return suma;

}
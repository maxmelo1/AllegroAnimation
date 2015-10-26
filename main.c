#include <stdio.h>
#include <stdbool.h>

#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

bool initialize(ALLEGRO_DISPLAY *);

int main(int argc, char *argv[]){
    ALLEGRO_DISPLAY *janela = NULL;

    if (!initialize(janela))
    {
        return -1;
    }

	// Linha: x1, y1, x2, y2, cor, espessura
    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 0, 0), 1.0);
    al_flip_display();

    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    al_rest(0.5);
 
    // Triângulo: x1, y1, x2, y2, x3, y3, cor, espessura
    al_draw_triangle(70.0, 30.0, 20.0, 55.0, 110.0, 250.0, al_map_rgb(255, 255, 255), 5.0);
    al_flip_display();

    al_rest(2.0);
 
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
 
    al_rest(0.5);
 
    // Triângulo preenchido: x1, y1, x2, y2, x3, y3, cor
    al_draw_filled_triangle(40.0, 90.0, 120.0, 246.0, 400.0, 23.0, al_map_rgb(255, 255, 0));
    al_flip_display();

    al_rest(5.0);
 
    al_destroy_display(janela);
 
    return 0;
}

bool initialize(ALLEGRO_DISPLAY *janela){
	if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
        return false;
    }
 
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
        return false;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
 
    al_set_window_title(janela, "Testando allegro_primitives");
 
    return true;
}

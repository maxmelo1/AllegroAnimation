#include <stdio.h>
#include <stdbool.h>

#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

bool initialize(ALLEGRO_DISPLAY **, ALLEGRO_EVENT_QUEUE **);
void drawScenario();

int main(int argc, char *argv[]){
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    bool run = 1;

    if (!initialize(&janela, &eventQueue))
    {
        return -1;
    }

    drawScenario();


    al_register_event_source(eventQueue, al_get_display_event_source(janela));
    al_register_event_source(eventQueue, al_get_keyboard_event_source()); ///Tell allegro to get events from the keyboard

    while(run){
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN) ///look for keyboard events
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                printf("oi");
                run = false;
            }
        }


        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            run = false;
        }
    }

 
    al_destroy_display(janela);
 
    return 0;
}

bool initialize(ALLEGRO_DISPLAY **janela, ALLEGRO_EVENT_QUEUE **eventQueue){
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
 
    *janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!*janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
 
    //al_set_window_title(janela, "Testando allegro_primitives");

    *eventQueue = al_create_event_queue();
    if (!*eventQueue)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(*janela);
        return -1;
    }

    if(!al_install_keyboard()) ///setup the keyboard
    {
        fprintf(stderr, "Failed to install keyboard.\n");
        //return -1;
        exit(-1);
    }

    //printf("j3anela = null: %d\n", *janela == NULL );

    return true;
}

void drawScenario(){
    al_draw_line(0.0, 100.0, 640.0, 100.0, al_map_rgb(255,0,0), 1.0 );
    al_flip_display();
}
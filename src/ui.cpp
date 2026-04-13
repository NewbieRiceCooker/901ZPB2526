#include "liblvgl/lvgl.h"
#include "globals.hpp"

lv_obj_t * tabview;
    // 2. Add Tabs
lv_obj_t * tabAuton;
lv_obj_t * tabData;

const int NUM_AUTONS = 6;
static lv_obj_t * autonBtns[NUM_AUTONS];

static void autonSelectEvent(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED){
        int autonID = (int)(uintptr_t)lv_event_get_user_data(e);
        autonomousPreSet = autonID;

        lv_obj_t * clickedBtn = lv_event_get_target(e);

        for (int i = 0; i < NUM_AUTONS; i++){
            lv_obj_set_style_bg_color(autonBtns[i], lv_palette_main(LV_PALETTE_BLUE),0);
        }

        lv_obj_set_style_bg_color(clickedBtn, lv_palette_main(LV_PALETTE_GREEN), 0);
    }
}






void lv_main_menu(void){
    
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 40);
    tabAuton = lv_tabview_add_tab(tabview, "Auton Selector");
    tabData = lv_tabview_add_tab(tabview, "Live Data");

    // Left 3+$S Block Auton (ID: 1)
    autonBtns[0] = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(autonBtns[0], 0, 0);                            /*Set its position*/
    lv_obj_set_size(autonBtns[0], 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(autonBtns[0], autonSelectEvent, LV_EVENT_CLICKED, (void*)1); 
    
    lv_obj_t * btnLabel0 = lv_label_create(autonBtns[0]);          /*Add a label to the button*/
    lv_label_set_text(btnLabel0, "Left 3+4 Block");                     /*Set the labels text*/
    lv_obj_center(btnLabel0);

    // Left 

    //Right 7 Alley Wing (ID: 3)
    autonBtns[1] = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(autonBtns[1], 0, 50);                            /*Set its position*/
    lv_obj_set_size(autonBtns[1], 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(autonBtns[1], autonSelectEvent, LV_EVENT_CLICKED, (void*)3);         /*Assign a callback to the button*/
    lv_obj_t * btnLabel1 = lv_label_create(autonBtns[1]);          /*Add a label to the button*/
    lv_label_set_text(btnLabel1, "R7 Long Alley");                     /*Set the labels text*/
    lv_obj_center(btnLabel1);

    //Left 4 Rush (ID: 2)

    autonBtns[2] = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(autonBtns[2] , 300, 0);                            /*Set its position*/
    lv_obj_set_size(autonBtns[2] , 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(autonBtns[2] , autonSelectEvent, LV_EVENT_CLICKED, (void*)2);         /*Assign a callback to the button*/
    lv_obj_t * btnLabel2  = lv_label_create(autonBtns[2] );          /*Add a label to the button*/
    lv_label_set_text(btnLabel2, "L4RUSH");                     /*Set the labels text*/
    lv_obj_center(btnLabel2);

    //Skill Button (ID: 9)

    autonBtns[3] = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(autonBtns[3], 300, 50);                            /*Set its position*/
    lv_obj_set_size(autonBtns[3], 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(autonBtns[3], autonSelectEvent, LV_EVENT_CLICKED, (void*)9);           /*Assign a callback to the button*/
    lv_obj_t * btnLabel3 = lv_label_create(autonBtns[3]);          /*Add a label to the button*/
    lv_label_set_text(btnLabel3, "Skills");                     /*Set the labels text*/
    lv_obj_center(btnLabel3);



    // Temps

    labelTemps = lv_label_create(tabData);
    lv_obj_align(labelTemps, LV_ALIGN_CENTER, -100, 0); // Center it
    lv_label_set_text(labelTemps, "Initializing Temps...");
    lv_obj_set_style_text_font(labelTemps, &lv_font_montserrat_20, 0);

    //Cords

    labelCoords = lv_label_create(tabData);
    lv_obj_align(labelCoords, LV_ALIGN_CENTER, 100, 0); // Center it
    lv_label_set_text(labelCoords, "Initializing Coords...");
    lv_obj_set_style_text_font(labelCoords, &lv_font_montserrat_30, 0);




    
    
    


    
 }

 /*
 LEFT 3+4 | LEFT 7  | SKILLS
 RRIGHT 4+3 | RIGHT 7 | AWP
 
 */
#include "liblvgl/lvgl.h"
#include "globals.hpp"

lv_obj_t * tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 40);

    // 2. Add Tabs
lv_obj_t * tabAuton = lv_tabview_add_tab(tabview, "Auton Selector");
lv_obj_t * tabData = lv_tabview_add_tab(tabview, "Live Data");


static void left7blockautonbuttonevent(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        autonomousPreSet = 1;
        lv_label_set_text(autonomousSubtitle, "Selected: Left 7 Block Auton");
    }
}

static void right7AlleyButtonEvent(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        autonomousPreSet = 3;
        lv_label_set_text(autonomousSubtitle, "Selected: Right 7 Long Alley");
    }
}

static void skillsButtonEvent(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        autonomousPreSet = 9;
        lv_label_set_text(autonomousSubtitle, "Selected: Skills Auton");
    }
}

static void goAutonScreen(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        lv_tabview_set_act(tabview, 0, LV_ANIM_ON);
    }
}

static void goStatsScreen(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        lv_tabview_set_act(tabview, 1, LV_ANIM_ON);
    }
}

static void startAutonEvent(lv_event_t * e) {
    if(lv_event_get_code(e) == LV_EVENT_CLICKED && autonState == 0) {
        if(autonomousPreSet == 9){ //this is the skills auton
            gameTimer = 105; // Skills: 1:45
        }
        else{
            gameTimer = 15; // Standard 15 second Autonomous Round
        }
        
        countdownValue = 3; // Reset to 3 seconds
        autonState = 1; //move to countDown state
    }
}

static void cancelAutonEvent(lv_event_t * e) {
    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {
        autonState = 0;
        lv_label_set_text(countdownLabel, "Auton Cancelled");
    }
}






void lv_main_menu(void){

   

    // Autonomous Subtitle
    autonomousSubtitle = lv_label_create(tabAuton);
    lv_label_set_long_mode(autonomousSubtitle, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(autonomousSubtitle, true);                      /*Enable re-coloring by commands in the text*/
    lv_label_set_text(autonomousSubtitle, "Autonomous description goes here:");
    lv_obj_set_width(autonomousSubtitle, 150);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(autonomousSubtitle, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_pos(autonomousSubtitle,150,0);
    

    // Left 7 Block Auton
    lv_obj_t * leftSevenBlockButton = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(leftSevenBlockButton, 0, 0);                            /*Set its position*/
    lv_obj_set_size(leftSevenBlockButton, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(leftSevenBlockButton, left7blockautonbuttonevent, LV_EVENT_ALL, NULL);         /*Assign a callback to the button*/
    lv_obj_t * levelSevenBlockButtonLabel = lv_label_create(leftSevenBlockButton);          /*Add a label to the button*/
    lv_label_set_text(levelSevenBlockButtonLabel, "Left 7 Block");                     /*Set the labels text*/
    lv_obj_center(levelSevenBlockButtonLabel);

    //Right 7 Alley Wing
    lv_obj_t * rightSevenAlleyButton = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(rightSevenAlleyButton, 0, 50);                            /*Set its position*/
    lv_obj_set_size(rightSevenAlleyButton, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(rightSevenAlleyButton, right7AlleyButtonEvent, LV_EVENT_ALL, NULL);         /*Assign a callback to the button*/
    lv_obj_t * rightSevenAlleyButtonLabel = lv_label_create(rightSevenAlleyButton);          /*Add a label to the button*/
    lv_label_set_text(rightSevenAlleyButtonLabel, "R7 Long Alley");                     /*Set the labels text*/
    lv_obj_center(rightSevenAlleyButtonLabel);

    //Skill Button

    lv_obj_t * skillButton = lv_btn_create(tabAuton);     /*Add a button the current screen*/
    lv_obj_set_pos(skillButton, 300, 50);                            /*Set its position*/
    lv_obj_set_size(skillButton, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(skillButton, skillsButtonEvent, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_t * skillButtonLabel = lv_label_create(skillButton);          /*Add a label to the button*/
    lv_label_set_text(skillButtonLabel, "Skills");                     /*Set the labels text*/
    lv_obj_center(skillButtonLabel);

    //Countdown Display Label
    countdownLabel = lv_label_create(tabAuton);
    lv_label_set_text(countdownLabel, "Ready to Start");
    lv_label_set_long_mode(countdownLabel, LV_LABEL_LONG_WRAP); 
    lv_obj_set_pos(countdownLabel,150,120);
    lv_obj_set_style_text_font(countdownLabel, &lv_font_montserrat_18, 0); // Large font
    lv_obj_set_width(countdownLabel, 150);

    //Start Button
    lv_obj_t * btnStart = lv_btn_create(tabAuton);
    lv_obj_set_size(btnStart, 120, 50);
    lv_obj_set_pos(btnStart,0,120);
    lv_obj_add_event_cb(btnStart, startAutonEvent, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(btnStart, lv_palette_main(LV_PALETTE_GREEN), 0);
    
    lv_obj_t * lblStart = lv_label_create(btnStart);
    lv_label_set_text(lblStart, "START");
    lv_obj_center(lblStart);

    // Cancel Button
    lv_obj_t * btnCancel = lv_btn_create(tabAuton);
    lv_obj_set_size(btnCancel, 120, 50);
    lv_obj_set_pos(btnCancel,300,120);
    lv_obj_add_event_cb(btnCancel, cancelAutonEvent, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(btnCancel, lv_palette_main(LV_PALETTE_RED), 0);

    lv_obj_t * lblCancel = lv_label_create(btnCancel);
    lv_label_set_text(lblCancel, "CANCEL");
    lv_obj_center(lblCancel);



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
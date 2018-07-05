#pragma once

#define USE_GENERIC_MAIN
#undef REMOVE_LEADING_ZERO_FROM_TIME  /* 12 hour display will not have a leading '0' or ' ' if this is defined */
#undef FONT_NAME
#undef FONT_SYSTEM_NAME  /* the default font system will be used */
#undef DEBUG_TIME
//#define USE_TIME_MACHINE  // NOTE mixing with DEBUG_TIME doesn't make sense

// Show step count using builtin code
#define USE_HEALTH
//#define UPDATE_HEALTH_ON_ACTIVITY  /* If not set, only updates step count display once per minute */

#define DRAW_BATTERY
#define DRAW_SMALL_BATTERY

#define QUIET_TIME_IMAGE RESOURCE_ID_IMAGE_QUIET_TIME
//#define QUIET_TIME_IMAGE_GRECT GRect(20, 20, 20, 20)  // Example assumes a 20x20 image
#define BT_DISCONNECT_IMAGE RESOURCE_ID_IMAGE_BT_DISCONNECT

#define BG_IMAGE RESOURCE_ID_IMAGE_MAIN
#define IMAGE_RES_X 144  // NOTE if image res changes - this needs to change too!
#define IMAGE_RES_Y 161  // NOTE if image res changes - this needs to change too!

#ifdef PBL_ROUND /* 180x180 */
    /* Image at top of screen, centered horizontally */
    #define BG_IMAGE_GRECT GRect((180 - IMAGE_RES_X) / 2, 0, IMAGE_RES_X, IMAGE_RES_Y)

    #define QUIET_TIME_IMAGE_GRECT GRect(17, 48, 17, 17)  // TODO consider placing in top of screen/circle
/*TODO center/move right*/
    #define CLOCK_POS GRect(0, 52, 180, 180) /* probably taller than really needed */
    #define HEALTH_POS GRect(0, 40, 180, 180)
    #define BT_POS GRect(0, 100, 180, 180) /* probably taller than really needed */

    #define DATE_ALIGN GTextAlignmentCenter
    #define DATE_POS GRect(0, 120, 180, 180) /* probably taller than really needed */

    #define BAT_ALIGN GTextAlignmentCenter
    #ifdef DRAW_BATTERY
        #define BAT_POS GRect(85, 10, 180, 180) /* probably taller than really needed */
    #else
        #define BAT_POS GRect(0, 140, 180, 180) /* probably taller than really needed */
    #endif /* DRAW_BATTERY */

#else /* PBL_RECT 144x168*/
    /* Clock at top of screen, Image below and centered horizontally */
    #define BG_IMAGE_GRECT GRect((144 - IMAGE_RES_X) / 2, 35,  IMAGE_RES_X, IMAGE_RES_Y)  // use same size as image. On Aplite can determine this at runtime but not Basalt

    #define QUIET_TIME_IMAGE_GRECT GRect(3, 35, 14, 14)  // 14x14 image
    #define HEALTH_POS GRect(0, 40, 144, 168)
    //#define BT_POS GRect(0, 120, 144, 168) /* probably taller than really needed */
    //#define DATE_POS GRect(0, 140, 144, 168) /* probably taller than really needed */

    #define BAT_POS GRect(0, 35, 144, 168) /* probably taller than really needed */
    /*
    #ifdef DRAW_BATTERY
        #define BAT_POS GRect(5, 150, 144, 168)
    #else
        #define BAT_POS GRect(0, 140, 144, 168) // probably taller than really needed
    #endif // DRAW_BATTERY
    */

    #define CLOCK_POS GRect(0, -15, 144, 168) // top of screen for FONT_KEY_ROBOTO_BOLD_SUBSET_49

    //#define BT_DISCONNECT_IMAGE_GRECT GRect(144 - 20, 138, 20, 30)
    #define BT_DISCONNECT_IMAGE_GRECT GRect(144 - 20, 168 - (2 * 30 + 4), 20, 30)

    #define BT_POS GRect(0, 120, 144, 168) /* probably taller than really needed */
    #define DATE_POS GRect(0, 35, 144, 168) /* probably taller than really needed */

#endif /* end of Round or rectangle */

/* for screen shots and font testing
#define DEBUG_TIME
#define DEBUG_TIME_SCREENSHOT
// ensure quiet time and bluetooth disconnection info is shown
#ifndef quiet_time_is_active  // so not aplite
#define quiet_time_is_active() true  // DEBUG!
#endif
#define bluetooth_connection_service_peek() false  // DEBUG!
*/

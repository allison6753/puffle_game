#include "helper.h"

// background image
#include "images/snow_scene.h"

// penguin image
#include "images/penguin.h"

// puffle images
#include "images/blue_puffle.h"
#include "images/pink_puffle.h"
#include "images/green_puffle.h"
#include "images/brown_puffle.h"
#include "images/yellow_puffle.h"
#include "images/gray_puffle.h"
#include "images/purple_puffle.h"
#include "images/white_puffle.h"
#include "images/red_puffle.h"

extern struct penguin *playerP;
extern struct puffle puffles[9];

void setup(void) {
    // initailize penguin
    playerP -> row = 130;
    playerP -> col = 150;
    playerP -> width = PENGUIN_WIDTH;
    playerP -> height = PENGUIN_HEIGHT;
    playerP -> image = penguin;

    // initialize puffles
    int initialHorDis[9] = {2, -1, 0, 1, 1, 2, 3, -2, -3};
    int initialVertDis[9] = {-1, 0, 2, 3, -2, 1, -3, -1, -2};
    const short unsigned int *images[9] = {pink_puffle, blue_puffle, yellow_puffle, green_puffle, white_puffle, red_puffle, gray_puffle, brown_puffle, purple_puffle};
    for (int i = 0; i < 9; i++) {
        puffles[i].row = (i * BLUE_PUFFLE_HEIGHT) % HEIGHT;
        puffles[i].col = (i * BLUE_PUFFLE_WIDTH) % WIDTH;
        puffles[i].height = BLUE_PUFFLE_HEIGHT;
        puffles[i].width = BLUE_PUFFLE_WIDTH;
        puffles[i].vertDis = initialVertDis[i];
        puffles[i].horDis = initialHorDis[i];
        puffles[i].show = 1;
        puffles[i].image = images[i];
    }
}

void control(u32 currentButtons, u32 previousButtons) {
    // up button
    if (KEY_JUST_PRESSED(BUTTON_UP, currentButtons, previousButtons)) {
        if ((playerP -> row) >= 3) {
        playerP -> row -= 3;
        undrawImageDMA((playerP -> row) + (playerP -> height), (playerP -> col), (playerP -> row) + (playerP -> height) + 3, (playerP -> col) + (playerP -> width), snow_scene);
        }
    }

    // down button
    if (KEY_JUST_PRESSED(BUTTON_DOWN, currentButtons, previousButtons)) {
        if ((playerP -> row) <= HEIGHT - (playerP -> height) - 3) {
        playerP -> row += 3;
        undrawImageDMA(playerP -> row - 3, (playerP -> col), (playerP -> row), (playerP -> col) + (playerP -> width), snow_scene);
        }
    }

    // left button
    if (KEY_JUST_PRESSED(BUTTON_LEFT, currentButtons, previousButtons)) {
        if ((playerP -> col) >= 3) {
        playerP -> col -= 3;
        undrawImageDMA(playerP -> row, (playerP -> col) + (playerP -> width), (playerP -> row) + (playerP -> height), (playerP -> col) + (playerP -> width) + 3, snow_scene);
        }
    }

    // right button
    if (KEY_JUST_PRESSED(BUTTON_RIGHT, currentButtons, previousButtons)) {
        if ((playerP -> col) <= WIDTH - (playerP -> width) - 3) {
        playerP -> col += 3;
        undrawImageDMA(playerP -> row, (playerP -> col) - 3, (playerP -> row) + (playerP -> height), (playerP -> col) - 1, snow_scene);
        }
    }
}
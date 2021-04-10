#include "setup.h"

void setup() {
    // initailize penguin
    struct penguin player;
    struct penguin *playerP = &player;
    playerP -> row = 130;
    playerP -> col = 150;
    playerP -> width = PENGUIN_WIDTH;
    playerP -> height = PENGUIN_HEIGHT;
    playerP -> image = penguin;

    // initialize puffles
    int initialHorDis[9] = {2, -1, 0, 1, 1, -2, 3, -2, -3};
    int initialVertDis[9] = {-1, 0, 2, 3, -2, 1, -3, 1, -2};
    const short unsigned int *images[9] = {pink_puffle, blue_puffle, yellow_puffle, green_puffle, white_puffle, red_puffle, gray_puffle, brown_puffle, purple_puffle};
    struct puffle puffles[9];
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

    // initialize score
    int score = 0;
}
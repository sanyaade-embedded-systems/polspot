#ifndef POLSPOT_UI_TRACKLIST_H
#define POLSPOT_UI_TRACKLIST_H

#include "ui.h"

void tracklist_init(ui_t *ui);
void tracklist_draw(ui_t *ui);
int  tracklist_keypress(wint_t ch, bool code);

void tracklist_set(int pos, bool focus);

#endif

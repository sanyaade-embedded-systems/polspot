#ifndef POLSPOT_UI_LOG_H
#define POLSPOT_UI_LOG_H

#include "ui.h"

void log_init(ui_t *ui);
void log_draw(ui_t *ui);
int  log_keypress(wint_t ch, bool code);

void log_append(const char *fmt, ...);

#endif

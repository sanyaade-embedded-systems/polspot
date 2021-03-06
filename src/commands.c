#include <string.h>

#include "commands.h"
#include "session.h"
#include "ui.h"
#include "ui_footer.h"
#include "ui_log.h"

void cmd_cb_connect()
{
  // Prompt for username.
  footer_input(INPUT_USERNAME);
}

void cmd_cb_disconnect()
{
  sess_disconnect();
}

void cmd_cb_search()
{
  footer_input(INPUT_SEARCH);
}

void cmd_cb_stop()
{
  sess_stop();
}

void cmd_cb_pause()
{
  sess_pause();
}

void cmd_cb_log()
{
  ui_show(UI_SET_LOG);
}

void cmd_cb_help()
{
  ui_show(UI_SET_HELP);
}

void cmd_cb_main()
{
  ui_show(UI_SET_BROWSER);
}

void cmd_cb_redraw()
{
  ui_redraw_post();
}

void cmd_cb_quit()
{
  ui_quit_post();
}

typedef void (*cmd_cb_t)();
typedef struct cmd {
  char    *name;
  int      args;
  cmd_cb_t cmd_cb;
} cmd_t;

static cmd_t g_commands[] = {
  { "connect",    0, cmd_cb_connect    },
  { "c",          0, cmd_cb_connect    },
  { "disconnect", 0, cmd_cb_disconnect },
  { "d",          0, cmd_cb_disconnect },
  { "search",     0, cmd_cb_search     },
  { "s",          0, cmd_cb_search     },
  { "stop",       0, cmd_cb_stop       },
  { "t",          0, cmd_cb_stop       },
  { "pause",      0, cmd_cb_pause      },
  { "p",          0, cmd_cb_pause      },
  { "log",        0, cmd_cb_log        },
  { "l",          0, cmd_cb_log        },
  { "help",       0, cmd_cb_help       },
  { "h",          0, cmd_cb_help       },
  { "?",          0, cmd_cb_help       },
  { "main",       0, cmd_cb_main       },
  { "m",          0, cmd_cb_main       },
  { "redraw",     0, cmd_cb_redraw     },
  { "r",          0, cmd_cb_redraw     },
  { "quit",       0, cmd_cb_quit       },
  { "q",          0, cmd_cb_quit       },
  { 0, 0, 0 }
};

void command_process(char *str)
{
  char cmd[16];
  if (sscanf(str, "%15s", cmd) == 1) {
    for (int i = 0; g_commands[i].name; ++i) {
      if (!strcmp(cmd, g_commands[i].name)) {
        g_commands[i].cmd_cb();
        return;
      }
    }
    log_append("Unknown command: '%s'", cmd);
  }
}

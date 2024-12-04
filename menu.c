/* menu.c 
 * module to handle menu options/user navigation in menu:
 *   adjust config settings
 *   block creation
 *   high score display
 *   high score writing (if returning score from teetris.c)
 *   quitting (duh)
 */ 

#include <teetris.c>

const char *hiscores = ".hiscores"

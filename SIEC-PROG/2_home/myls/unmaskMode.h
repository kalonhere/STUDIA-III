#ifndef _UNMASK_MODE_H_
#define _UNMASK_MODE_H_

typedef enum {
  PRIVELEGES = 0,
  MONTH = 1,
  TIME = 2,
}UNMASK_MODE_MODIFIER;

// CHAR ??? CONST CHAR??? CONST CHAR * ????? VOOOOOOOOID ESSSA
const char *unmaskMode(struct stat file_data, UNMASK_MODE_MODIFIER);

#endif

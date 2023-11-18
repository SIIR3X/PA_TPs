#pragma once

#include <stdio.h>

#include "list.h"

typedef enum { BIN, TEXT } stream_mode_t;

list_t * stream_2_persons(char * filename, stream_mode_t mode);
list_t * stream_2_friendships(char * filename, stream_mode_t mode, list_t * Lpers);
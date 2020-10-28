#pragma once

#ifndef BUILDER_C_SERVER_CONFIG_H
#define BUILDER_C_SERVER_CONFIG_H

#include <inttypes.h>
#include <stdbool.h>

typedef struct server_config {
  char host[16];
  uint16_t port;

  bool ssl;
  char certificate[80];
  char key[80];
} server_config_t;

#endif // BUILDER_C_SERVER_CONFIG_H

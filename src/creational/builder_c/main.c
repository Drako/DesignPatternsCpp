#include "server_config.h"

#include <stdio.h>
#include <string.h>

char const* bool_to_string(bool value)
{
  return &"false\0true"[value*6];
}

void print_config(server_config_t const* config)
{
  printf("host: \"%s\", port: %d, ssl: %s, certificate: \"%s\", key: \"%s\"\n",
      config->host,
      config->port,
      bool_to_string(config->ssl),
      config->certificate,
      config->key
  );
}

int main(void)
{
  server_config_t config = {
      .host = "localhost",
      .port = 80,
      .ssl = false,
  };
  print_config(&config);

  config.port = 443;
  config.ssl = true;
  strcpy(config.certificate, "server.crt");
  strcpy(config.key, "server.key");
  print_config(&config);

  return 0;
}

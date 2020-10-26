#pragma once

#ifndef BUILDER_SERVER_CONFIG_HXX
#define BUILDER_SERVER_CONFIG_HXX

#include <cstdint>
#include <string>

class server_config final {
  std::string host;
  std::uint16_t port;

  bool ssl;
  std::string certificate;
  std::string key;

  server_config(std::string host, std::uint16_t port, bool ssl, std::string certificate, std::string key);

  struct stage2 final {
    std::string host;
    std::uint16_t port;
    std::string certificate;
    std::string key;

    server_config build()&& noexcept;
  };

  struct stage1 final {
    std::string host;
    std::uint16_t port;

    server_config build()&& noexcept;

    stage2 with_ssl(std::string certificate, std::string key)&& noexcept;
  };

public:
  struct builder final {
    stage1 server(std::string host, std::uint16_t port)&& noexcept;
  };

  server_config(server_config const&) = default;
  server_config(server_config&&) = default;

  server_config& operator=(server_config const&) = delete;
  server_config& operator=(server_config&&) = delete;

  [[nodiscard]]
  std::string const& get_host() const noexcept;

  [[nodiscard]]
  std::uint16_t get_port() const noexcept;

  [[nodiscard]]
  bool is_ssl_enabled() const noexcept;

  [[nodiscard]]
  std::string const& get_certificate() const noexcept;

  [[nodiscard]]
  std::string const& get_key() const noexcept;
};

#endif // BUILDER_SERVER_CONFIG_HXX

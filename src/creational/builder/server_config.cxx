#include "server_config.hxx"

#include <utility>

server_config::server_config(std::string host, std::uint16_t port, bool ssl, std::string certificate, std::string key)
    :host{std::move(host)}, port{port}, ssl{ssl}, certificate{std::move(certificate)}, key{std::move(key)}
{
}

std::string const& server_config::get_host() const noexcept
{
  return host;
}

std::uint16_t server_config::get_port() const noexcept
{
  return port;
}

bool server_config::is_ssl_enabled() const noexcept
{
  return ssl;
}

std::string const& server_config::get_certificate() const noexcept
{
  return certificate;
}

std::string const& server_config::get_key() const noexcept
{
  return key;
}

server_config::stage1 server_config::builder::server(std::string host, std::uint16_t const port)&& noexcept
{
  return {std::move(host), port};
}

server_config server_config::stage1::build()&& noexcept
{
  return {std::move(host), port, false, {}, {}};
}

server_config::stage2 server_config::stage1::with_ssl(std::string certificate, std::string key)&& noexcept
{
  return {std::move(host), port, std::move(certificate), std::move(key)};
}

server_config server_config::stage2::build()&& noexcept
{
  return {std::move(host), port, true, std::move(certificate), std::move(key)};
}

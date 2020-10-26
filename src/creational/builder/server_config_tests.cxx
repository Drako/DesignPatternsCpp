#include <gtest/gtest.h>

#include "server_config.hxx"

#include <type_traits>

TEST(ServerConfigTest, ServerConfigIsImmutable)
{
  EXPECT_FALSE(std::is_copy_assignable<server_config>::value);
  EXPECT_FALSE(std::is_move_assignable<server_config>::value);
}

TEST(ServerConfigTest, ServerConfigCannotBeConstructedWithoutBuilder)
{
  EXPECT_FALSE(
      (std::is_constructible<server_config, std::string, std::uint16_t, bool, std::string, std::string>::value)
  );
}

TEST(ServerConfigTest, ServerConfigSupportsHttp)
{
  auto const cfg = server_config::builder{}
      .server("localhost", 80)
      .build();

  EXPECT_EQ(cfg.get_host(), "localhost");
  EXPECT_EQ(cfg.get_port(), 80);
  EXPECT_EQ(cfg.is_ssl_enabled(), false);
  EXPECT_EQ(cfg.get_certificate(), "");
  EXPECT_EQ(cfg.get_key(), "");
}

TEST(ServerConfigTest, ServerConfigSupportsHttps)
{
  auto const cfg = server_config::builder{}
      .server("localhost", 443)
      .with_ssl("server.crt", "server.key")
      .build();

  EXPECT_EQ(cfg.get_host(), "localhost");
  EXPECT_EQ(cfg.get_port(), 443);
  EXPECT_EQ(cfg.is_ssl_enabled(), true);
  EXPECT_EQ(cfg.get_certificate(), "server.crt");
  EXPECT_EQ(cfg.get_key(), "server.key");
}

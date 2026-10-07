#include <gtest/gtest.h>

#include "upstream_b/upstream_b.hpp"

TEST(UpstreamB, SummarizesThroughUpstreamA)
{
  EXPECT_EQ("elements=2", upstream_b::summarize("<a><b/></a>"));
}

TEST(UpstreamB, MalformedXmlIsInvalid)
{
  EXPECT_EQ("invalid", upstream_b::summarize("<a>"));
}

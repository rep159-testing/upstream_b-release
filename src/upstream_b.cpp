#include "upstream_b/upstream_b.hpp"

#include "upstream_a/upstream_a.hpp"

namespace upstream_b
{

std::string summarize(const std::string & xml)
{
  const int count = upstream_a::count_elements(xml);
  if (count < 0) {
    return "invalid";
  }
  return "elements=" + std::to_string(count);
}

}  // namespace upstream_b
